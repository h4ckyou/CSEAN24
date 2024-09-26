## DeeStrucTor

Description: I was given this weird file but it does not seem to do anything, can you help me figure it out?

---
Solution
---

We are given a binary `chall` and from checking the file properties we get this
![image](https://github.com/user-attachments/assets/b8cf86f9-a503-4ff1-8991-06c69e1f9088)

This is a 64bits executable which is statically linked and stripped

Running it we see it does nothing?
![image](https://github.com/user-attachments/assets/1fb73a9a-179e-4623-b0d5-dc0472e42f47)

There are two ways you can go about this:
- Just "smartly" checking the list of available functions in IDA
- Researching about "destructors in C"

I'll start from the first one. Loading it into IDA we should get this
![image](https://github.com/user-attachments/assets/0156a070-1823-44d5-ac0b-ddd8137cec01)

Since the binary is stripped, the function names are not available. Additionally, because it is statically linked, the binary size is significantly larger due to all the necessary functions being embedded directly within the binary.

Now one easy way to get reference to the main function is by searching for the strings being outputted during runtime?

For example:
- View -> Open Subviews -> Strings

![image](https://github.com/user-attachments/assets/005b4e0e-31cb-489a-93f1-1557bd5ac117)

Now we look for the string "This program does nothing." because that was printed to the screen when we ran the binary
![image](https://github.com/user-attachments/assets/64a3bf87-6b3d-4980-9a5b-954d839cd7ad)

You can just `CTRL + F`

Ok our string is located in the `.rodata` section and when we double click it we should get this
![image](https://github.com/user-attachments/assets/80ebbf78-4460-4707-bdcb-679149e51ded)

Now we check for `Cross Reference` to that string and doing that we should get this
![image](https://github.com/user-attachments/assets/d9e1841c-e3d6-489b-a95c-e773d167f33c)

We can see that function `sub_401805+4` executes an instruction which makes use of the string in that location

Now we just double click on that 🙂
![image](https://github.com/user-attachments/assets/a884bbba-e094-4ea6-81ab-f9b4d6324edb)

This now, is the main function

Press the almighty `F5` key to get the pseudocode (C like decompilation)
![image](https://github.com/user-attachments/assets/ae0c5c3d-135f-41cc-99e2-e5c770966184)

And again because this is stripped we can't tell which function is which

But you can intuitively tell that `sub_404690` is functions `puts()`

Now we just rename the functions!
![image](https://github.com/user-attachments/assets/e4a20162-e7ef-4498-9fb8-90440897f2c3)

That looks more like it!














