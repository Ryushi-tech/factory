#!/usr/bin/env python3

import random, string

def randomname(n):
    return ''.join(random.choices(string.ascii_lowercase, k=n))

lim = 100
n = random.randint(4, lim)
a = random.randint(-1000,1000)
b = random.randint(-1000,1000)
c = random.randint(-1000,1000)
d = random.randint(-1000,1000)
print(a,b,c,d)
print(n)
for i in range(n):
    e = random.randint(-1000,1000)
    f = random.randint(-1000,1000)
    print(e,f)
# for i in range(m - 2):
#     x, y = random.sample(range(1, n), k=2)
#     print(x, y)
# for i in range(h):
#     print(i, i + random.randint(1, 3))
    # x = random.randint(0, w)
    # if i == 0:
    #     tmp = ["s"] + ["."] * x + ["#"] * (w - x - 1)
    # elif i == h - 1:
    #     tmp = ["g"] + ["."] * x + ["#"] * (w - x - 1)
    # else:
    #     tmp = ["."] * x + ["#"] * (w - x)
    # random.shuffle(tmp)
    # print("".join(tmp))
# tmp1 = [x for x in range(1,n+1)]
# tmp2 = [x for x in range(n)]
# random.shuffle(tmp1)
# random.shuffle(tmp2)
# print(" ".join(map(str, tmp1)))
# for x, y in zip(tmp1, tmp2):
#     print(x, y)