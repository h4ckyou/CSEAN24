flag = "csean-ctf{y0u_c4n_sw4p_r3v3rs3_m4ngl4_and_r0t4t3_4_byt3}"

def swap():
    tmp_buf = list(flag)

    for i in range(0, len(flag)-1, 2):
        tmp1 = flag[i]
        tmp2 = flag[i+1]
        tmp_buf[i] = tmp2
        tmp_buf[i+1] = tmp1

    return tmp_buf


def reverse(buf, n):
    tmp_buf = [0]*n

    for i in range(n):
        tmp_buf[i] = buf[n-1-i]

    return tmp_buf
  

def rol(value, shift):
    return ((value << shift) | (value >> (8 - shift))) & 0xFF


def mangle(buf, n):
    tmp_buf = [0]*n

    j = 0
    
    for i in range(n):
        val = ord(buf[i])
        if j & 1 == 0:
            r = (~((rol(val ^ 0x40, 4) - 0xcafe) & 0xff)) & 0xff
            tmp_buf[i] = chr(r)
        else:
            r = (~(((val + 0x20) - 0xbabe) & 0xff)) & 0xff
            tmp_buf[i] = chr(r)

        j += 1

    return tmp_buf


buf = swap()
buf = reverse(buf, len(buf))
buf = mangle(buf, len(buf))

hex_rep = [hex(ord(i)) for i in buf]
print(len(hex_rep))
print(hex_rep)
