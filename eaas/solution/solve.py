enc = bytes.fromhex("4958494c4002534554484c05446840094864440d4c6071321d2074750a3a")

for i in range(0xff):
    r = bytes([enc[idx] ^ ((i + idx) % 256) for idx in range(len(enc))])
    if b"csean" in r:
        print(r)
