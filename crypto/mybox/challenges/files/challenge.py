#!/usr/bin/env python3
import random
import time

flag = b"csean-ctf{a_r4nd0m_subst1tut1on_b0x_1s_d0pe_r1ght}24"
e_flag = b"*"


def menu():
    print("1. Generate flag")
    print("2. Confirm flag")
    print("3. Exit")
    try:
        choice = int(input("> "))
        return choice
    except Exception:
        print("Invalid choice")
        exit()


def generate():
    global e_flag

    key = random.randint(0, 0x100)
    ct = int(time.time())
    random.seed(ct)
    sbox = list(range(256))
    random.shuffle(sbox)

    s = []

    for val in flag:
        r = key
        while val:
            r = sbox[r]
            val -= 1
        s.append(r)

    e_flag = bytes(s)

    print(f'Encrypted flag: {e_flag.hex()}')


def confirm():
    print(e_flag)
    print(f"DEBUG:: Current time: {int(time.time())}")
    s1 = input("Enter flag to check: ")
    if len(e_flag) == 0:
        print("Nothing to validate with")
        return
    else:
        print("Checking...")
        msg = s1.encode()
        if msg == e_flag:
            exit("You got it right")
        else:
            print("Hmmm try better")


def quit():
    exit("Good bye")


def main():
    while True:
        choice = menu()
        if choice == 1:
            generate()
        elif choice == 2:
            confirm()
        elif choice == 3:
            quit()


if __name__ == '__main__':
    main()
