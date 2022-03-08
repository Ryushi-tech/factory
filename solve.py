#!/usr/bin/env python3

n=int(input())
ans=""
while(n):
    if n%2==1:
        n-=1
        ans+="A"
    else:
        n//=2
        ans+="B"
print(ans[::-1])