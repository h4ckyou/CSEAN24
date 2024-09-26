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

With that we get the general idea of the main function, so here's my renamed code

```c
__int64 __fastcall main(int a1, char **a2, char **a3)
{
  __int64 v3; // rax
  __int64 v4; // rdx
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v8; // rax
  char buf[72]; // [rsp+0h] [rbp-50h] BYREF
  unsigned int len; // [rsp+48h] [rbp-8h]
  int i; // [rsp+4Ch] [rbp-4h]

  v3 = std::operator<<<std::char_traits<char>>(
         &std::cout,
         "Reversing is pain but can you find your way around this?",
         a3);
  std::ostream::operator<<(v3, &std::endl<char,std::char_traits<char>>);
  std::operator<<<std::char_traits<char>>(&std::cout, "Flag: ", v4);
  std::operator>><char,std::char_traits<char>>(&std::cin, buf);
  len = strlen(buf);
  sub_1169(buf, len);
  sub_128B(buf, len);
  sub_134A(buf, len);
  for ( i = 0; i < len; ++i )
  {
    v5 = dword_4040[i];
    if ( buf[i] != v5 )
    {
      v6 = std::operator<<<std::char_traits<char>>(&std::cout, "Wrong.", v5);
      std::ostream::operator<<(v6, &std::endl<char,std::char_traits<char>>);
      return 0LL;
    }
  }
  v8 = std::operator<<<std::char_traits<char>>(&std::cout, "Correct!", v5);
  std::ostream::operator<<(v8, &std::endl<char,std::char_traits<char>>);
  return 0LL;
}
```

Now we need to figure out exactly what the three function does to our input:
- sub_1169(buf, len);
- sub_128B(buf, len);
- sub_134A(buf, len);

