#!/usr/bin/python
# -*- coding: utf-8 -*-
morning_msg = u'좋은아침'
goodday_msg = u'good afternoon'
evening_msg = u'evening'
have_coffee = u'coffee'

hour = 5

# 한글

def greeting(hour, morning_msg = 'good morning'):
    '''
    display greeting msg
    '''
    # check param

    if  type(hour) != int:
        print('hour shoud be integer')
        return
    
    if hour < 0 or hour > 24:
        print(u'Invalid hour value (hour >= 0 && hour <= 24)')
        return hour
        
    if hour < 12:
        print(morning_msg)
        print(have_coffee)
    elif hour < 18:
        print(goodday_msg)
    elif hour == 24:
        # todo : need msg
        pass
    else:
        print(evening_msg)

    return hour

