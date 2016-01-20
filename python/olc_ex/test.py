def setAlarm(alarmClock, atime):
    #
    if atime < 0 or atime > 24:
        print(u"time value should have 0 ~ 24.")
        return
    alarmClock['atime'] = atime
    return alarmClock

class AlarmClock:
    def __init__(self, ctime = 13, atime = 7):
        self.ctime = ctime
        self.atime = atime
        
    def setAlarm(self, atime):
        if atime < 0 or atime > 24:
            print(u"time value should have 0 ~ 24.")
            return
        self.atime = atime

    def __str__(self):
        return u'current time is {0}.'.format(self.atime)

        
