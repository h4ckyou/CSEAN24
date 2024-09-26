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


For the first function here's the decompilation
![image](https://github.com/user-attachments/assets/19c52fa6-ad03-4b1c-8658-5bb6efe4f1f2)

This might look kinda hard to assimilate but from renaming variable names and data types i got this

```c
__int64 __fastcall sub_1169(char *buf, int len)
{
  void *v2; // rsp
  __int64 result; // rax
  __int64 buf_len; // [rsp+0h] [rbp-30h] BYREF
  char *tmp; // [rsp+8h] [rbp-28h]
  char v6; // [rsp+16h] [rbp-1Ah]
  char v7; // [rsp+17h] [rbp-19h]
  char *v8; // [rsp+18h] [rbp-18h]
  __int64 v9; // [rsp+20h] [rbp-10h]
  int j; // [rsp+28h] [rbp-8h]
  int i; // [rsp+2Ch] [rbp-4h]

  tmp = buf;
  HIDWORD(buf_len) = len;
  v9 = len - 1LL;
  v2 = alloca(16 * ((len + 15LL) / 0x10uLL));
  v8 = &buf_len;
  for ( i = 0; i < HIDWORD(buf_len) - 1; i += 2 )
  {
    v7 = tmp[i];
    v6 = tmp[i + 1];
    v8[i] = v6;
    v8[i + 1] = v7;
  }
  for ( j = 0; ; ++j )
  {
    result = j;
    if ( j >= SHIDWORD(buf_len) )
      break;
    tmp[j] = v8[j];
  }
  return result;
}
```

Now that looks much better
- It defines the tmp variable to be a pointer to the buf variable
- It iterates through the length of the buf while incrementing the iterate by 2
- It stores the current buf value into variable `v7` and then the next buf value into variable `v6`
- Then it stores `v6` into `v8[i]` and `v7` into `v8[i + 1]`

Then after it does this swap it would replace the values of `buf` to `v8`

The conclusion we can draw from what this function does is that it performs a swap of adjacent bytes within the buffer

Now let's see example:

If we give it:
- abcd, the result should give: badc

We can confirm by setting a breakpoint before the call to the function and seeing the modified value after this function is called
![image](https://github.com/user-attachments/assets/fc646460-33cf-45bb-ba87-c61c5341d322)
![image](https://github.com/user-attachments/assets/8f2625c1-fdac-43ae-a3f8-2163fc394222)
![image](https://github.com/user-attachments/assets/b9c3e3f8-45a3-4268-a445-2b8c28e145ed)

