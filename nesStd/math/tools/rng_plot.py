import matplotlib.pyplot as plt
import numpy as np

size = 256
xor = 57
seed0 = 4
seed1 = 0

gens = int(input("generations to create ? (65535 = periode): " )) 
rn = []
distArray= []
count = {}
x = []

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
    
    rn.append(seed0)

for i in rn:
    if not i in count:
        count[i] = 1
    else:
        count[i] += 1 

for i in count:
    distArray.append(count[i])
    x.append(i)

periode = plt.subplot(212)
periode.plot(rn,'-o', markersize = 5, markerfacecolor='red', linewidth = 1)
periode.set_title('full graph')

zoomed_in = plt.subplot(222)
zoomed_in.margins(-0.499,0)
zoomed_in.plot(rn,'-o',markersize = 5, markerfacecolor='orange', linewidth = 1)
zoomed_in.set_title('zoomed in')

dist = plt.subplot(221)
dist.bar(x,distArray, width = 1.5, color = 'green', edgecolor = 'black') 
dist.set_title('distribution')

con = int(input("print array ? (1 = yes, 0 = no): "))
if (con == 1):
    print(count)
    print(rn)

plt.show()