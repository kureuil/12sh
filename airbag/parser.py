import argparse

def parse_options():
    parser = argparse.ArgumentParser(description='Run tests')
    parser.add_argument('-f', '--file',
        nargs=1, required=False, default='airbag.yaml')
    return parser.parse_args()
