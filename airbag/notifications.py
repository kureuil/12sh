from gi.repository import Notify

def desktop_notify(testsuite):
	Notify.init("airbag")
	if (len(testsuite.failed_tests) != 0):
		msg = "Ran {0} tests. {1} of them failed, check the logs for more informations.".format(testsuite.tests_count, len(testsuite.failed_tests))
	else:
		msg = "Ran {0} tests. Everything passed, good job !".format(testsuite.tests_count)
	Notify.Notification.new("{0}'s tests".format(testsuite.project), msg, None).show()
