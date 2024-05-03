n = int(input('Введите состовное n: '))
factor = []

def gcd(a, b): 
    if b == 0: 
        return a
    else:
        return gcd(b, a % b)

while True:
    a = 2
    b = 2
    d = 1
    while d == 1:
        a = (a**2 + 1) % n
        b = (b**2 + 1) % n
        b = (b**2 + 1) % n
        d = gcd(a - b, n)
    if d != n:
        factor.append(d)
        n = n // d
    if d == n:
        break
factor.append(n)
print(factor)