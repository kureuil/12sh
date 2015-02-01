import requests
import json

def slack_notify(testsuite):
    if 'slack' not in testsuite.config:
        return
    if 'url' not in testsuite.config['slack']:
        return
    if 'username' not in testsuite.config['slack']:
        username = 'airbag-bot'
    else:
        username = testsuite.config['slack']['username']
    if 'emoji' not in testsuite.config['slack']:
        emoji = ':rocket:'
    else:
        emoji = testsuite.config['slack']['emoji']
    if 'channel' not in testsuite.config['slack']:
        channel = '#random'
    else:
        channel = testsuite.config['slack']['channel']
    url = testsuite.config['slack']['url']
    headers = {'content-type':'application/json'}
    attachments = {
        'fields': []
    }
    if (len(testsuite.failed_tests) != 0):
        msg = "{0}: Ran {1} tests".format(testsuite.project, testsuite.tests_count)
        pretext = "{0} of them failed.".format(len(testsuite.failed_tests))
        for test in testsuite.failed_tests:
            field = {
                'title': test.name,
                'short': False
            }
            attachments['fields'].append(field)
        attachments['color'] = 'danger'
    else:
        msg = "{0}: Ran {1} tests.".format(testsuite.project, testsuite.tests_count)
        pretext = "Everything passed, good job !"
        attachments['color'] = 'good'
    attachments['fallback'] = pretext
    attachments['pretext'] = pretext
    payload = json.dumps({
            'username' : username,
            'text' : msg,
            'attachments': [attachments],
            'icon_emoji' : emoji,
            'channel': channel
    })
    request = requests.post(url, headers=headers, data=payload)
