# -*- coding: utf-8 -*-
"""
Created on Sat Jul 20 16:54:19 2024

@author: admin
"""

class emp:
    def __init__(self,name,ID,salary):
        self.__name=name
        self.__ID=ID
        self.__salary=salary
        
    def setname(self,name):
        self.__name=name
    def getname(self):
        return self.__name
    def setID(self,ID):
        self.__ID=ID
    def getID(self):
        return self.__ID
    def setsalary(self,newsalary):
        self.__salary=newsalary
    def getsalary(self):
        return self.__salary
class Manger:
    def __init__(self):
        self.__emps=[]
        
    def addemp(self,emp):
         self.__emps.append(emp)
         print("emp is added")
         
    def updatesalary(self,emp_id,newsalary):
        if len(self.__emps)>1:
            for e in self.__emps:
                if e.getID()==emp_id:
                    e.setsalary(1000)
                  
                   
        else:
            print("the list is empty or not found the emp")
            
    def removeemp(self,emp_id):
        if len(self.__emps)>1:
            for e in self.__emps:
                if e.getID()==emp_id:
                   self.__emps.remove(e)
                   print("Deleted salary")
                else:
                    print("not found")
        else:
            print("the list is empty")
            
    def printemps(self):
        if len(self.__emps)<1:
            print("the list is empty")
            return
        for e in self.__emps:
            print(e.getname(), e.getID(),e.getsalary())
        
e1=emp("mohammed",1001,2500)
e2=emp("ahmed",1002,3000)
e3=emp("naji",1003,1500)

manger=Manger()
manger.addemp(e1)  
manger.addemp(e2)  
manger.addemp(e3)
manger.printemps()  
manger.updatesalary(1002, 1000)
manger.printemps()  
manger.removeemp(1003)
manger.printemps()  
