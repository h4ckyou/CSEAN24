key = 0x637466

chunks = [
    0x63101107, 0x6e4e1712, 0x66180757, 0x6d131855,
    0x5f1b4414, 0x5f061a05, 0x721a0412, 0x31531a39,
    0x680a1002, 0x330d551b
]

flag = b""

for i in range(len(chunks)):
    chunk = chunks[i]
    xored = chunk ^ key
    flag += xored.to_bytes((xored.bit_length() + 7) // 8)


print(flag)
