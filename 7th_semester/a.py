import math

def sum(a, b):
    res = (a[0]*b[1]+b[0]*a[1], a[1]*b[1])
    return res

def ras(a, b):
    res = (a[0]*b[1]-b[0]*a[1], a[1]*b[1])
    return res

def mult(a, b):
    res = (a[0]*b[0], a[1]*b[1])
    return res
    
a = (9526243, 1355452560)
d = (1, 255024)
p1 = (24, 25)
p2 = (25, 25)

r1 = sum(a, mult(d, p1))
r2 = sum(a, mult(d, p2))

print(r1, r2)
gcd1 = math.gcd(r1[0], r1[1])
gcd2 = math.gcd(r2[0], r2[1])
print(gcd1, gcd2)
print((r1[0]//gcd1, r1[1]//gcd1), (r2[0]//gcd2, r2[1]//gcd2))

r = ras(r2, r1)
gcd = math.gcd(r[0], r[1])
print((r[0]//gcd, r[1]//gcd))