#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from pwn import *
from warnings import filterwarnings

# Set up pwntools for the correct architecture
exe = context.binary = ELF('domath')
context.terminal = ['xfce4-terminal', '--title=GDB-Pwn', '--zoom=0', '--geometry=128x50+1100+0', '-e']

filterwarnings("ignore")
context.log_level = 'debug'

def start(argv=[], *a, **kw):
    if args.GDB:
        return gdb.debug([exe.path] + argv, gdbscript=gdbscript, *a, **kw)
    elif args.REMOTE: 
        return remote(sys.argv[1], sys.argv[2], *a, **kw)
    else:
        return process([exe.path] + argv, *a, **kw)

gdbscript = '''
init-pwndbg
b *compute+540
continue
'''.format(**locals())

#===========================================================
#                    EXPLOIT GOES HERE
#===========================================================

def init():
    global io

    io = start()


def solve():

    check = [58, 0, 0, 0]
    flag = list(map(ord, "csean-ctf{h0p3_th1s_w4s_fuN_and_gg_0n_s0lv1ng_th1s}"))

    for chk in check:
        io.sendline(str(chk))
    
    io.sendline("csean-ctf{h0p3_th1s_w4s_fuN_and_gg_0n_s0lv1ng_t1s}")
    # for val in flag:
    #     io.sendline(str(val))


    io.interactive()

def main():
    
    init()
    solve()

if __name__ == '__main__':
    main()
