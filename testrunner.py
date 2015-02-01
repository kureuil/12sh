#!/usr/bin/python3

from os import getcwd, path, mkdir
from datetime import datetime
from airbag.logging import setup_logging
from airbag.testsuite import Testsuite
from airbag.parser import parse_options
from airbag.slack import slack_notify
from airbag.notifications import desktop_notify
import logging

def main():
    setup()
    options = parse_options()
    testsuite = Testsuite(options)
    testsuite.onTeardown(slack_notify)
    testsuite.onTeardown(desktop_notify)
    testsuite.run()
    teardown()

def setup():
    dir = getcwd()
    airbag = path.join(dir, 'airbag')

    if not path.exists(airbag):
    	mkdir(airbag)
    if not path.exists(path.join(airbag, 'logs')):
    	mkdir(path.join(airbag, 'logs'))
    setup_logging()

def teardown():
    logging.shutdown()

if __name__ == "__main__":
	main()
