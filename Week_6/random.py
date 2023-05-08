import random
import string

def generate_email_password():
    # Generate a random email address
    email_length = random.randint(5, 10)
    email_name = ''.join(random.choices(string.ascii_lowercase, k=email_length))
    email_domain = random.choice(['gmail.com', 'yahoo.com', 'hotmail.com'])
    email = f"{email_name}@{email_domain}"

    # Generate a random password
    password_length = random.randint(8, 12)
    password_characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choices(password_characters, k=password_length))

    return email, password

email, password = generate_email_password()
print(f"Email: {email}")
print(f"Password: {password}")
