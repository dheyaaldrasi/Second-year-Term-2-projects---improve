# -*- coding: utf-8 -*-
"""
Created on Sat Sep  7 17:16:15 2024

@author: admin
"""

from tkinter import *
from tkinter import ttk



class MainPage(Tk):
    def __init__(self):
        super().__init__()
        self.geometry("500x500")
        self.title("Mainpage")
        self.gender=IntVar()
        self.MaleGender=ttk.Radiobutton(self,text="Male",
                                        value=1,variable=self.gender)
        self.FemaleGender=ttk.Radiobutton(self,text="Female",
                                        value=0,variable=self.gender)
        self.MaleGender.pack()
        self.FemaleGender.pack()
        self.printGenderBtn=Button(self,text="اطبع النوغ",command=self.PrintGender)
        self.printGenderBtn.pack()
        self.comboxgender=ttk.Combobox(self,values=['Man','Female'],state='readonly')
        self.comboxgender.pack()
        self.comboxgender.set("اختار")
        self.spinBox=Spinbox(self,from_=0,to=100,command=lambda:print(self.spinBox.get()))
        self.spinBox.pack()
        self.comboxgender.bind("<<ComboboxSelected>>", lambda event: print(self.comboxgender.get()))
    def PrintGender(self):
        print("the gender is ","Man" if self.gender.get()==1 else "Female")
        if self.comboxgender.get()!="اختار":
           print("the gender from combobox is ",self.comboxgender.get())
        print("the select number is ",self.spinBox.get())
         

        
p=MainPage()
p.mainloop()