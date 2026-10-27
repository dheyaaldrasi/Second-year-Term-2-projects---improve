# -*- coding: utf-8 -*-
"""
Created on Sat Aug  3 21:45:33 2024

@author: admin
"""

class Opreation:
    def sum(self,a=None,b=None,c=None):
        if a!=None and b!=None and c!=None:
            print(a+b+c)
        elif a!=None and b!=None:
            print(a+b)
        else:
            print(a)
            
    def sub(self,*args):
        Count=0
        for n in args:
            Count-=n
        print(Count)
op=Opreation()

op.sum(5,3,2)
op.sub(3,8,6,7,1,6,3,8,1)