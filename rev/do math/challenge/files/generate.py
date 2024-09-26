import numpy as np 
import random

flag = b"csean-ctf{h0p3_th1s_w4s_fuN_and_gg_0n_s0lv1ng_t1s}"
keystr = "csean-ctf-is-the-best-fr!"

key = np.array([ord(i) for i in keystr]).reshape(5, 5)

matrix = np.array([i for i in flag]).reshape(10, 5)
enc = np.matmul(matrix, key)
ct = enc.reshape(10, 5)

print(ct)
print()
print(key)
