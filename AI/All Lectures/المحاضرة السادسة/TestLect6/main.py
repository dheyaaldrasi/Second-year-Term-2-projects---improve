# -*- coding: utf-8 -*-
"""
Created on Sat Aug 17 16:39:37 2024

@author: admin
"""

from tkinter import *
from Opreation import *

def calculate():
    result.delete(0,END)
    try:
      n1=int(ennum1.get())
      n2=int(ennum2.get())
      res=n1+n2
      result.insert(0, str(res))
    
    except:
      print("ادخل رقم رجاء")
      messagebox.showinfo("خطا","ادخل رقم وليس حرف ")
o1=Opreation()
root=Tk()
root.geometry("500x300")
root.resizable(False,False)
#root.config(bg='red')
root.title("MainPage")
f1=Frame(root,bg='green',width=250,height=299)
f2=Frame(root,bg='blue',width=250,height=299)
f1.place(x=1,y=1)
f2.place(x=251,y=1)

ennum1=Entry(f1,font=20)
ennum2=Entry(f1,font=20)
result=Entry(f1,font=20)

btn=Button(f2,text="احسب",width=20,command=calculate)
ennum1.place(x=50,y=1)
ennum2.place(x=50,y=31)
result.place(x=50,y=61)
btn.place(x=1,y=1)
root.mainloop()