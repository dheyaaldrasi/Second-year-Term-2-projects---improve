# %%

#The Time Class - The first program
#Eng. Diaa Al-Drasi

class Time:
    def __init__(self, hours=0, minutes=0, seconds=0):
        self.hours = hours
        self.minutes = minutes
        self.seconds = seconds
        self._normalize()

    def _normalize(self):
        self.minutes += self.seconds // 60
        self.seconds = self.seconds % 60
        self.hours += self.minutes // 60
        self.minutes = self.minutes % 60

    def __add__(self, other):
        return Time(
            self.hours + other.hours,
            self.minutes + other.minutes,
            self.seconds + other.seconds
        )

    def __iadd__(self, extra_seconds): 
        self.seconds += extra_seconds
        self._normalize()
        return self

    def __gt__(self, other):
        self_total = (self.hours * 3600) + (self.minutes * 60) + self.seconds
        other_total = (other.hours * 3600) + (other.minutes * 60) + other.seconds
        return self_total > other_total

    def __str__(self):
        return f"{self.hours:02d}:{self.minutes:02d}:{self.seconds:02d}"


time1 = Time(1, 50, 0)
time2 = Time(1, 20, 0)
time3 = Time(1, 45, 75)
time4 = Time(15, 50, 24)

time1 += 360
print(time1)


time5 = time3 + time4
print(time3 > time1)

print(time5)

time3 = time1 + time2
print(time3)

time3 += 1
print(time3)

print(time3 > time1)

print("-------------------------")



# %%

#Multiple Inheritance - The second program
#Eng. Diaa Al-Drasi

class Device:
    def __init__(self, brand, **kwargs):
        super().__init__(**kwargs)
        self.brand = brand

    def show_brand(self):
        print(f"Brand: {self.brand}")

class Phone(Device):
    def __init__(self, screen_size, **kwargs):
        super().__init__(**kwargs)
        self.screen_size = screen_size

    def make_call(self):
        print("Making a call...")

class Camera(Device):
    def __init__(self, resolution, **kwargs):
        super().__init__(**kwargs)
        self.resolution = resolution

    def take_photo(self):
        print("Taking a photo...")

class SmartPhone(Phone, Camera):
    def __init__(self, brand, screen_size, resolution):
        super().__init__(brand=brand, screen_size=screen_size, resolution=resolution)

    def show_smartphone_details(self):
        print(f"Brand: {self.brand} | Screen: {self.screen_size} inches | Camera: {self.resolution} MP")


my_phone = SmartPhone(brand="Samsung", screen_size=6.8, resolution=108)

my_phone.show_brand()
my_phone.make_call()
my_phone.take_photo()
my_phone.show_smartphone_details()


print("-----------------------")




# %%

#Calculator & Exception Handling - The third program
#Eng. Diaa Al-Drasi

class Calculator:
    def div(self, a, b):
        if b == 0:
            raise ZeroDivisionError("Cannot divide by zero.")
        return a / b

    @staticmethod
    def power(base: int, exp: int) -> int:
        if exp < 0:
            raise ValueError("Negative exponent is not allowed.")
        return base ** exp

    def get_item(self, items: list, index: int):
        if not items or index < 0 or index >= len(items):
            raise IndexError("List is empty or index is out of bounds.")
        return items[index]

    def get_average(self, numbers: list[int]) -> float:
        if not numbers:
            raise ValueError("List cannot be empty to calculate average.")
        return sum(numbers) / len(numbers)

if __name__ == "__main__":
    calc = Calculator()

    try:
        calc.div(10, 0)
    except ZeroDivisionError as e:
        print(e)

    try:
        Calculator.power(5, -2)
    except ValueError as e:
        print(e)

    try:
        calc.get_item([10, 20, 30], 5)
    except IndexError as e:
        print(e)

    try:
        calc.get_average([])
    except ValueError as e:
        print(e)
# %%
