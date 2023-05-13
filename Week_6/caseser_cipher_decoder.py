#CASER CIPHER DECODER

def main():
    print("[>] CAESAR CIPHER DECODER!!! \n")
    print("[1] Encrypt\n[2] Decrypt")
    try:
        func = int(input("Choose one of the above(example for encode enter 1): "))
    except:
        print("\n[>] Invalid input")
        exit()

    if func == 2:
        decode()
    else:
        if func == 1:
            encode()
        else:
            print("\n[>] Invalid input")
        exit()

def encode():
    text = input("Enter text to encode: ")
    key = input("Enter number of characters you want to shift: ")
    encoded_cipher = ""
    try:
        key = int(key)
    except:
        print("Only intigers between 0 to 25 are allowed. Try again :)")
        exit()
    if key > 25:
        print("Only intigers between 0 to 25 are allowed. Try again :)")
        exit()
    else:
        key = key
    text = text.upper()
    for char in text:
        ascii = ord(char)
        if ascii > 90:
            new_ascii = ascii
        else:
            if ascii < 65:
                new_ascii = ascii
            else:
                new_ascii = ascii + key
                if  new_ascii > 90:
                    new_ascii = new_ascii - 26
                else:
                    new_ascii = new_ascii
        encoded = chr(new_ascii)
        encoded_cipher = encoded_cipher + encoded
    print("Encoded text: " + encoded_cipher)
