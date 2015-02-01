import logging
from os import path, getcwd
from datetime import datetime
from termcolor import cprint

def setup_logging():
    curdate = datetime.now()
    logging.basicConfig(level=logging.DEBUG,
        format='%(asctime)s %(levelname)-8s %(message)s',
        datefmt='%m-%d %H:%M',
        filename=path.join(getcwd(), 'airbag', 'logs', "{0}-{1:02}-{2:02} {3:02}:{4:02}:{5:02}.log".format(
            curdate.year,
            curdate.month,
            curdate.day,
            curdate.hour,
            curdate.minute,
            curdate.second
        )),
        filemode='a+'
    )

def get_logger(logger='airbag'):
    return logging.getLogger(logger)

def log(log_msg, color=None, style=None):
    get_logger().info(log_msg)
    cprint(log_msg, color, attrs=style)