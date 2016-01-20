#!/usr/bin/python
# -*- coding: utf-8 -*-

def maxNumber(x, y, z):
    ''' 
    get max number
    '''

    bigger = x;

    if y > bigger:
        bigger = y

    if z > bigger:
        bigger = z

    return bigger



    
    
def maxNumberList(numlist):
    ''' '''

    if type(numlist) != list :
        print("param is not list")
        return

    bigger = numlist[0]

    for val in numlist:
        if val > bigger:
            bigger = val


    return bigger

