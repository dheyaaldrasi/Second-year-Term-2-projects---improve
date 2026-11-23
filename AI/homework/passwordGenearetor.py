import numpy as np

UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LOWERCASE = "abcdefghijklmnopqrstuvwxyz"
DIGITS = "0123456789"
SYMBOLS = "~!@#$%^&*()_+|{}[]:;'?.><"

# arr=np.random.seed(42)

def generate_password(length=12):
    if length <= 0:
        raise ValueError("Password length must be greater than 0.")
    chars = np.array(list(UPPERCASE + LOWERCASE + DIGITS + SYMBOLS))
    selected_chars = np.random.choice(chars, size=length)
    return "".join(selected_chars)


length = int(input("Enter the length of the password: "))
password = generate_password(length)
print(f"Your password is: {password}")

