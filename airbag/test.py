from os import getcwd
from subprocess import Popen, PIPE
from .logging import log

class Test(object):
    """docstring for Test"""
    def __init__(self, name, config):
        super(Test, self).__init__()
        self.name     = name
        self.stdin    = self.get_attr('stdin',     name, config)
        self.stdout   = self.get_attr('stdout',    name, config)
        self.program  = self.get_attr('program',   name, config)
        if (isinstance(self.program, str)):
            self.program = [self.program]
        self.expected = self.get_attr('expected',  name, config, False)
        self.args     = self.get_attr('args',      name, config)
        if (isinstance(self.args, str)):
            self.args = [self.args]
        self.failed   = False

    def run(self):
        dir = getcwd()
        output = self.get_test_output()
        expected = self.get_test_expected()

        log(self.name, style=['bold'])
        if output != expected:
            log("\tKO: output differs, test failed.", 'red')
            log("\tProgram output:")
            log(output)
            log("\tExpected output:")
            log(expected)
            self.failed = True
        else:
            log("\tOK", 'green')

    def get_test_output(self):
        stdin_res   = None
        stdout_res  = None
        program_res = None
        res         = None

        if self.stdin is not None:
            stdin = Popen(self.stdin, stdout=PIPE)
            stdin_res = stdin.stdout

        if self.program is None:
            return
        else:
            self.program.extend(self.args)
            program = Popen(
                self.program,
                stdin=stdin_res,
                stdout=PIPE
            )
            if stdin_res is not None:
                stdin_res.close()
            program_res = program.stdout

        if self.stdout is not None:
            stdout = Popen(
                self.stdout,
                stdin=program_res,
                stdout=PIPE
            )
            program_res.close()
            stdout_res = stdout.stdout

        if stdout_res is None:
            res = str(program.communicate()[0], 'utf-8')
        else:
            res = str(stdout.communicate()[0], 'utf-8')
        return res

    def get_test_expected(self):
        expected = self.expected

        if expected.startswith("!"):
            with open(expected[1:], 'r') as expected_file:
                return expected_file.read()
        return expected

    def get_attr(self, attr, test, config, split=True):
        res = None
        props = config['tests'][test]

        if (attr in props):
            res = props[attr]
        elif (attr in config):
            res = config[attr]
        if split == True and isinstance(res, str) and " " in res:
            res = res.split(" ")
        return res
