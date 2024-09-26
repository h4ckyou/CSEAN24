## Guess The Flag

Description: This is me totally not trolling

---
Solution
---

We are given a text file and checking the content shows this
![image](https://github.com/user-attachments/assets/d66217bd-0252-4f6e-b71f-583260abdf34)

Looking at it, we can see it's a 2D array that has so many sublists

One distinction between every elements in the sublists is that one is of type(str()) and the other of type(int())

The element of type(str()) are all hex values 

Starting from the bottom we can see this:

```
[['3a', 5], ['2f', 7], ['2f', 6], ['70', 3], ['73', 4], ['74', 2], ['68', 0], ['74', 1]]
```

If we start decoding from when `sublists[1]` is `0` we get this:

```
0 -> h
1 -> t
2 -> t
3 -> p
4 -> s
5 -> :
6 -> /
7 -> /
```

From this we can see that the decoded value is `https://`

With this, we can conclude that the 2D array is made up of sublists, and each sublist contains:
- A hexadecimal string that, when converted to a character, represents part of a message.
- An index that determines where that character should be placed in the final message.


But if you notice the whole structure you can see that the index is basically shuffled around, so we need to parse it well














