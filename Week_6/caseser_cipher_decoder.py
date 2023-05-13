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