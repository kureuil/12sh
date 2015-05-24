#!/usr/bin/python3

from sys import argv
from tempfile import mkstemp
from shutil import move
from os import remove, close, path

def get_mocks_for_file(f):
    headers = []
    try:
        with open(f.replace('.c', '.mocks'), "r") as mocks:
            for line in mocks:
                if line[-1] == "\n":
                    line = line[:-1]
                    headers.append('#define MOCK_' + line.upper() + " 1")
    except FileNotFoundError:
        return []
    return headers

def replace(file_path):
    fd, abs_path = mkstemp("temp")
    linem2 = ""
    linem1 = ""
    with open(abs_path, "w+") as new_file:
        with open(file_path, "r") as old_file:
            for line in old_file:
                if linem2[:-1] == "/*" and linem1[:-1] == "** @TESTABLE" and line[:-1] == "*/":
                    headers = get_mocks_for_file(file_path)
                    new_file.write("*/\n\n")
                    for header in headers:
                        new_file.write(header + "\n")
                    new_file.write('#include "mock.h"' + "\n");
                else:
                    new_file.write(line)
                linem2 = linem1
                linem1 = line
    close(fd)
    move(abs_path, file_path.replace('.c', '.mock.c'))

for arg in argv[1:]:
    replace(arg)
