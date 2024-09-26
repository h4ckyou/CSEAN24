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

















