# # Python3 program to validate
# # UPI ID  using Regular Expression

# import re

# # Function to validate
# # UPI ID(For India Country Only)
# def isValidUpi(str):

#     # Regex to check valid UPI ID
#     regex = "^[a-zA-Z0-9.-]{2, 256}@[a-zA-Z][a-zA-Z]{2, 64}$"

#     # Compile the ReGex
#     p = re.compile(regex)

#     # If the string is empty
#     # return false
#     if (str == None):
#         return False

#     # Return if the string
#     # matched the ReGex
#     if(re.search(p, str)):
#         return True
#     else:
#         return False


# # Driver code
# if __name__ == '__main__':
    
#     # Test Case 1:
#     str1 = "9136812895@ybl"
#     print(isValidUpi(str1))
    
#     # Test Case 2:
#     str2 = "Kingshivamsingh@ybl"
#     print(isValidUpi(str2))
    
#     # Test Case 3:
#     str3 = "Rahul 1998"
#     print(isValidUpi(str3))
    
#     # Test Case 4:
#     str4 = "934517865"
#     print(isValidUpi(str4))
    
#     # Test Case 5:
#     str5 = "ViratKohli101@paytm"
#     print(isValidUpi(str5))
    
#     # Test Case 6:
#     str6 = "Akanksha  @ybl"
#     print(isValidUpi(str6))


import re

def is_valid_upi_id(upi_id):
    pattern = "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$"
    return re.match(pattern, upi_id)

upi_id = "Kingshivamsingh@ybl"
if is_valid_upi_id(upi_id):
    print(f"{upi_id} is a valid UPI ID")
else:
    print(f"{upi_id} is not a valid UPI ID")
