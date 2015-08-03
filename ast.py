#!/usr/bin/env python2

import argparse
from sys import exit
import re
try:
    from clang.cindex import CursorKind, Index
except:
    print('You need libclang to be installed to run this program')
    exit(1)

def get_info(node, source_file, depth=0):
    children = [get_info(c, source_file, depth+1)
                for c in node.get_children()]

    if node.location.file and node.location.file.name != source_file:
        return None

    return { 'kind' : node.kind,
                'spelling' : node.spelling,
                'location' : node.location,
                'extent.start' : node.extent.start,
                'extent.end' : node.extent.end,
                'is_definition' : node.is_definition(),
                'children' : children,
                'depth': depth }

def main():
    parser = argparse.ArgumentParser(description='Checks the norme on C source files')
    parser.add_argument('files', metavar='FILES', type=str, nargs='+',
                        help='source files to be processed')
    parser.add_argument('-d', '--dump', action='store_true',
                        help='Dump file AST content')
    args = parser.parse_args()

    if len(args.files) == 0:
        parser.error('invalid number arguments')

    for source_file in args.files:
        index = Index.create()
        tu = index.parse(source_file, None)
        if not tu:
            parser.error("unable to load input")

        infos = get_info(tu.cursor, source_file)
        if args.dump:
            rprint(infos)
        linter = Linter(infos, source_file)
        linter.lint()

class Linter():
    def __init__(self, node, source_file):
        self.head = node
        self.filepath = source_file
        self.function_def_count = 0
        self.used_lines = []
        self.lines = []

    def error(self, node, message):
        print('{}:{}:{}:{}'.format(
            node['location'].file,
            node['location'].line,
            node['location'].column,
            message
        ))

    def ranged_error(self, node, message):
        print('{}:{}:{}:{}:{}:{}'.format(
            node['location'].file,
            node['extent.start'].line,
            node['extent.start'].column,
            node['extent.end'].line,
            node['extent.end'].column,
            message
        ))

    def lint(self):
        self.lint_file()
        self.do_lint(self.head, None)

    def lint_file(self):
        with open(self.filepath) as source:
            contents = source.read().split('\n')
            self.lines = contents
            self.check_header()
            for i in xrange(0, len(contents)):
                self.check_length_limit(contents[i], i)
                self.check_trailing_whitespace(contents[i], i)

    def check_header(self):
        def error():
            print('{}:{}:{}:{}'.format(self.filepath, 1, 1, 'Invalid header'))
        if not self.lines[0].startswith('/*'):
            error()
            return
        for i in xrange(1, 8):
            if not self.lines[i].startswith('**'):
                error()
                return
        if not self.lines[8].startswith('*/'):
            error()
            return

    def check_length_limit(self, line, line_no):
        line_len = 0
        if line.startswith('**'):
            return
        for i in xrange(0, len(line)):
            if line[i] == '\t':
                line_len += 8 - i % 8
            else:
                line_len += 1
        if len > 80:
            for i in xrange(80, line_len):
                print('{}:{}:{}:{}'.format(
                    self.filepath,
                    line_no,
                    i,
                    'A line should not be longer than 80 characters'
                ))

    def check_trailing_whitespace(self, line, line_no):
        for i in xrange(len(line), 0, -1):
            if line[i - 1] == ' ' or line[i - 1] == '\t':
                print('{}:{}:{}:{}'.format(
                    self.filepath,
                    line_no,
                    i,
                    'Trailing whitespace at the end of line'
                ))
            else:
                break

    def do_lint(self, node, parent, depth=0):
        if depth == 1:
            if node['kind'] == CursorKind.VAR_DECL:
                if not node['spelling'].startswith('g_'):
                    self.ranged_error(
                        node,
                        'A global variable name must be prefixed by `g_`'
                    )

            if node['kind'] == CursorKind.FUNCTION_DECL:
                self.arguments_count = 0
                self.function_def_count += 1
                if self.function_def_count > 5 and node['location'].file.name.endswith('.c'):
                    self.error(
                        node,
                        'A file mustn\'t contain more than 5 functions'
                    )

        if depth == 2:
            if node['kind'] == CursorKind.COMPOUND_STMT:
                flen = node['extent.end'].line - node['extent.start'].line
                if flen > 26:
                    for i in xrange(26, flen):
                        self.error(
                            node,
                            'A function mustn\'t be longer than 25 lines'
                        )
                if parent and parent['location'].line == node['location'].line:
                    self.error(
                        node,
                        'A compound statement must be on its own line'
                    )

            if node['kind'] == CursorKind.PARM_DECL:
                self.arguments_count += 1
                if self.arguments_count > 4:
                    self.ranged_error(
                        node,
                        'A function mustn\'t take more than 4 arguments'
                    )

        if depth > 2:
            if parent['kind'] == CursorKind.RETURN_STMT:
                if node['kind'] != CursorKind.PAREN_EXPR:
                    self.ranged_error(
                        node,
                        'A return statement must be followed by a parenthesis expr'
                    )

            if node['kind'] == CursorKind.COMPOUND_STMT and (
                parent['extent.start'].line == node['location'].line or parent['extent.end'].line == node['location'].line):
                self.error(
                    node,
                    'A compound statement must be on its own line'
                )

            if node['kind'] == CursorKind.DO_STMT:
                self.error(
                    node,
                    'Do statements are not allowed'
                )

            if node['kind'] == CursorKind.FOR_STMT:
                self.error(
                    node,
                    'For statements are not allowed'
                )

            if node['kind'] == CursorKind.GOTO_STMT:
                self.error(
                    node,
                    'Goto statements are not allowed'
                )

            if node['kind'] in (CursorKind.WHILE_STMT, CursorKind.IF_STMT):
                line = self.lines[node['location'].line - 1]
                col = node['location'].column - 1
                while line[col] not in (' ', '\t'):
                    col += 1
                whitespaces = 0
                while line[col + whitespaces] in (' ', '\t'):
                    whitespaces += 1
                if whitespaces > 1:
                    for i in xrange(1, whitespaces):
                        print('{}:{}:{}:{}'.format(
                            node['location'].file,
                            node['location'].line,
                            col + i,
                            'Keywords should be followed by one whitespace'
                        ))

            if node['kind'] == CursorKind.CONDITIONAL_OPERATOR:
                if parent['kind'] != CursorKind.PAREN_EXPR:
                    self.ranged_error(
                        node,
                        'A ternary expression must be enclosed in parenthesis'
                    )

        if node['kind'] in (CursorKind.VAR_DECL, CursorKind.FUNCTION_DECL):
            if re.search('[A-Z]', node['spelling']):
                self.error(
                    node,
                    'A name must contain only lowercase letters, numbers and underscores'
                )

        if node['kind'] == CursorKind.STRUCT_DECL and node['spelling']:
            if not node['location'].file.name.endswith('.h'):
                self.error(
                    node,
                    'Structures must be declared in header files'
                )

            if not node['spelling'].startswith('s_'):
                self.error(
                    node,
                    'Structure names must be prefixed by `s_`'
                )

            if parent and parent['kind'] == CursorKind.TYPEDEF_DECL:
                deduced_typename = 't' + node['spelling'][1:]
                if parent['spelling'] != deduced_typename:
                    self.error(
                        parent,
                        'Structure typedef must match structure\'s name'
                    )

        if node['kind'] == CursorKind.TYPEDEF_DECL:
            if not node['location'].file.name.endswith('.h'):
                self.error(
                    node,
                    'Typedef must be declared in header files'
                )

            if not node['spelling'].startswith('t_'):
                self.error(
                    node,
                    'Typedef names must be prefixed by `t_`'
                )

        if node['kind'] == CursorKind.UNION_DECL and node['spelling']:
            if not node['location'].file.name.endswith('.h'):
                self.error(
                    node,
                    'Unions must be declared in header files'
                )

            if not node['spelling'].startswith('u_'):
                self.error(
                    node,
                    'Union names must be prefixed by `u_`'
                )

        if node['kind'] == CursorKind.FUNCTION_DECL and node['spelling']:
            if not node['location'].file.name.endswith('.h') and node['is_definition'] is False:
                self.error(
                    node,
                    'Functions must be declared in header files'
                )

            if not node['location'].file.name.endswith('.c') and node['is_definition']:
                sef.error(
                    node,
                    'Funtions must be defined in source files'
                )

        if parent and parent['kind'] == CursorKind.UNARY_OPERATOR:
            if node['location'].line != parent['location'].line or node['location'].column != (parent['location'].column + 1):
                self.error(
                    parent,
                    'Unary operator mustn\'t be followed by whitespaces'
                )

        for child in node['children']:
            if child is not None:
                self.do_lint(child, node, depth+1)

def iprint(str, depth):
    print('{}{}'.format('\t' * depth, str))

def rprint(node, depth=0):
    print('')
    iprint('spelling:      {}'.format(node['spelling']), depth)
    iprint('kind:          {}'.format(node['kind']), depth)
    iprint('location:      {}'.format(node['location']), depth)
    iprint('extent.start:  {}'.format(node['extent.start']), depth)
    iprint('extent.end:    {}'.format(node['extent.end']), depth)
    iprint('is_definition: {}'.format(node['is_definition']), depth)
    if len(node['children']):
        iprint('children:', depth)
        for child in node['children']:
            if child is not None:
                rprint(child, depth+1)

if __name__ == '__main__':
    main()
