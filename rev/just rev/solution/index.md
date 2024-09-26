## Just Rev

Description: Show me your skills

---
Solution
---

We are given a binary and checking the file type & properties shows this
![image](https://github.com/user-attachments/assets/9e390aa1-e97c-4b08-a1dd-1c7d5687ab0b)

So this is a 64bit executable which is dynamically linked and stripped

Running it to get an overview of what it does shows this
![image](https://github.com/user-attachments/assets/704a1d96-177e-439a-ae59-ec6865c7c690)

From this we can tell that we need to provide the right flag and if we get it we should get a message that isn't "Wrong"

Using IDA we can decompile the binary and here's the main function
![image](https://github.com/user-attachments/assets/719e6a79-87bb-44ab-8fb4-b16e66e8325f)

Uhhh it's a C++ binary 🤮

First:
- It prints out some words, then it receives our input using `std::cin` and stores it in variable `s`
- It then gets the length of the input string and stores it in variable `v10`
- Then it calls three functions passing the variable `s & v10` as argument
- It then iterates through the length variable `s` and compares `s[i]` against a dword value stored at `dword_4040[i]`
- If the comparism returns False it returns and print the error message "Wrong." else it prints the success message "Correct!"
