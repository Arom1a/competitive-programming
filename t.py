import random

INT_MAX = 2**31-1

with open('./bin/input.in','w') as f:
    for i in range(10000):
        f.write(str(random.randint(0,INT_MAX)) + ' ')