# -*- coding: utf-8 -*-
"""
Created on Thu Aug  1 19:32:57 2024

@author: admin
"""

from abc import ABC,abstractmethod
import math
class Shape(ABC):
    def __init__(self):
        pass
    
    @abstractmethod 
    def area(self):
        pass
    
    @abstractmethod 
    def perimeter(self):
        pass
    
    
class Circle(Shape):
    def __init__(self,reduis):
        self.reduis=reduis
        
    def area(self):
     return   math.pi*(self.reduis**2)
        
    def perimeter(self):
      return  2*math.pi*self.reduis
  
class Traningle(Shape):
    def __init__(self,width,height):
        self.width=width
        self.height=height
        
    def area(self):
     return   self.width*self.height
        
    def perimeter(self):
      return  2*(self.width+self.height)
        
c1=Circle(3.5)
t1=Traningle(5,8)
print(c1.area())
print(c1.perimeter())
print(t1.area())
print(t1.perimeter())