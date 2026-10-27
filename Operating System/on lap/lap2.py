class Student:
    def __init__(self, name, age):
        self.__name = name
        self.age = age

    def getName(self):
        print(self.__name)

    def setName(self, name):
        self.__name = name

    def showInfo(self):
        print(f"The name is {self.__name} and the age is {self.age}.")


s1 = Student("Diaa", 21)
s1.showInfo()


class Animal:
    def __init__(self, name, sound):
        self.name = name
        self.sound = sound


class Dog(Animal):
    def __init__(self, name, sound, color):
        super().__init__(name, sound)





