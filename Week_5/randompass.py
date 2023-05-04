import random
import string

def generate_password(length):
    """Generates a random password of the given length."""
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''
    for i in range(length):
        password += random.choice(characters)
    return password

password_length = 12
password = generate_password(password_length)
print(password)
