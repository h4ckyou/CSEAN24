key = 0x637466

chunks = [
    0x63736561, 0x6E2D6374, 0x667B7331, 0x6D706C33,
    0x5F783072, 0x5F656E63, 0x72797074, 0x31306E5F,
    0x68696464, 0x336E217D
]

r = []

for i in chunks:
    r.append(hex(i ^ key))

print(r)
