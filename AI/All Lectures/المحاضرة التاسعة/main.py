# -*- coding: utf-8 -*-
"""
Created on Sat Sep  7 16:44:13 2024

@author: admin
"""

from tkinter import *
from tkinter import ttk



class MainPage(Tk):
    def __init__(self):
        super().__init__()
        self.geometry("500x500")
        self.title("MainPage")
        self.gender=IntVar()

        self.radmale=ttk.Radiobutton(self,text="Man",value=1,variable=self.gender)
        self.radmale.pack()
        self.radfemale=ttk.Radiobutton(self,text="Female",value=0,variable=self.gender)
        self.radfemale.pack()
        self.button=Button(self,text="Print",command=self.printGender)
        self.button.pack()
        
        self.genderCombox=ttk.Combobox(self,values=['Male','Female'],state='readonly')
        self.genderCombox.set("Select Gender")
        self.genderCombox.pack()
        self.spinBox_numbers=Spinbox(self,from_=0,to=100)
        self.spinBox_numbers.pack()
    def printGender(self):
        print("the gender is","Man" if self.gender.get()==1 else "Female")
        print("the combo box is ",self.genderCombox.get())
        print("the selected number is ",self.spinBox_numbers.get())
p=MainPage()
p.mainloop()