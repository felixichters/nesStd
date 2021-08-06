import time 
class ANSI: 
    red = '\033[91m'
    green = '\u001b[32m'
    blue = '\u001b[34m'
    reset = '\033[0m'
size = 256
xor = 57

def main(): 
    while True:
        seed0 = int(input("lo-byte of seed: "))
        seed1 = int(input("hi-byte of seed: "))
        gens = int(input("generations to create ? (65535 = periode): " )) 
        print(rng16(seed0,seed1,gens))
    
def rng16(seed0, seed1, gens):
    rn = []
    for j in range(gens):
        for i in range (8): 
            bu0 = seed0
            if (seed1 > 127):
                seed0 = (seed0 << 1)%size
                seed0 = (seed0 ^ xor)%size 
            else: 
                seed0 = (seed0 << 1)%size 

            if (bu0>127):
                seed1 = (seed1 << 1)%size 
                seed1 = (seed1+  1)%size
            else: 
                seed1 = (seed1 << 1)%size
        rn.append(str(hex(seed1)) + '|' + str(hex(seed0)))
    return rn 
if __name__ == "__main__":
    main()