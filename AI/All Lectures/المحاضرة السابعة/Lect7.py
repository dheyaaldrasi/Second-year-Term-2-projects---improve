from tkinter import *
from Student import *

Students=[]
class MainPage(Tk):
    def __init__(self):
        super().__init__()
        self.geometry("500x500")
        self.title("mainPage")
        self.labe1=Label(self,text="بيانات الطالب")
        self.labe1.pack()
        self.lname=Label(self,text="الاسم")
        self.lname.place(x=450,y=70)
        self.ename=Entry(self)
        self.ename.place(x=300,y=73)
        self.lage=Label(self,text="العمر")
        self.lage.place(x=450,y=100)
        self.eage=Entry(self)
        self.eage.place(x=300,y=103)
        self.lmajor=Label(self,text="التخصص")
        self.lmajor.place(x=450,y=130)
        self.emajor=Entry(self)
        self.emajor.place(x=300,y=133)
        self.degree=Label(self,text="المؤهل")
        self.degree.place(x=450,y=160)
        self.edegree=Entry(self)
        self.edegree.place(x=300,y=163)
        self.btnsave=Button(self,text="احفظ",command=self.savestudent)
        self.btnsave.place(x=420,y=190)
        self.btncancel=Button(self,text="اغلق",command=self.close)
        self.btncancel.place(x=320,y=190)
        self.btnshow=Button(self,text="عرض الطلاب",command=self.ShowData)
        self.btnshow.place(x=220,y=190)
        
    def close(self):
        self.destroy()
        
    def savestudent(self):
        s=Student(self.ename.get(), self.eage.get(), self.emajor.get(),self. edegree.get())
        Students.append(s)
        messagebox.showinfo("تمت الاضافة")
        
    def ShowData(self):
        self.new_window=NewWindow(self)
        
        
class NewWindow(Toplevel):
    def __init__(self,master=None):
        super().__init__(master)
        self.geometry("300x300")
        self.students=Listbox(self)
        self.students.place(x=0,y=0)
        for (s,i) in zip( Students,range(0,len(Students))):
            self.students.insert(i, s.name)
mp=MainPage()
mp.mainloop()
