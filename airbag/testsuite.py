from yaml import load, dump, YAMLError
from time import time
from os import getcwd, path
from .logging import log
from collections import deque
from .test import Test

try:
    from yaml import CLoader as Loader, CDumper as Dumper
except ImportError:
    from yaml import Loader, Dumper


class Testsuite(object):
    """docstring for Testsuite"""
    def __init__(self, options):
        super(Testsuite, self).__init__()
        self.file = path.join(getcwd(), options.file)
        self.tests_count = 0
        self.tests = deque()
        self.failed_tests = []
        self.setup = []
        self.teardown = []
        self.project = 'Airbag'
        self.config = {}

    def run(self):
        self.parse_config()

        for func in self.setup:
            func(self)
        start_time = time()
        while len(self.tests) > 0:
            test = self.tests.popleft()
            test.run()
            if test.failed == True:
                self.failed_tests.append(test)
        exec_time = time() - start_time
        log("Ran {0} tests in {1:.3f}s".format(len(self.tests), exec_time))
        if (len(self.failed_tests) != 0):
            log("{0} of them failed. Check the logs.".format(len(self.failed_tests)))
        for func in self.teardown:
            func(self)

    def parse_config(self):
        with open(self.file) as f:
            try:
                config = load(f, Loader=Loader)
                self.config = config
                self.get_project_name(config)
                for test in config['tests']:
                    self.add_test(test, config)
                self.tests_count = len(self.tests)
            except YAMLError as exc:
                if (hasattr(exc, 'problem_mark')):
                    print("Error in configuration file.")
                else:
                    print(
                        "Error in configuration file at line {0} and column {1}".format(
                            exc.problem_mark.line + 1,
                            exc.problem_mark.column + 1
                        )
                    )

    def get_project_name(self, config):
        if 'project' in config:
            self.project = config['project']
        elif 'program' in config:
            self.project = config['program']

    def add_test(self, test, config):
        test = Test(test, config)
        self.tests.append(test)

    def onSetup(self, cb):
        self.setup.append(cb)

    def onTeardown(self, cb):
        self.teardown.append(cb)
