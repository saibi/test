#!/usr/bin/python
# -*- coding: utf-8 -*-
morning_msg = u'좋은아침'
goodday_msg = u'good afternoon'
evening_msg = u'evening'
have_coffee = u'coffee'

hour = 5

if hour < 12:
    print(morning_msg)
    print(have_coffee)
elif hour < 18:
    print(goodday_msg)
else:
    print(evening_msg)

