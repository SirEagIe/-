def isPrime(n):
    if n == 1:
        return True
    if n < 1:
        return False
    d = 2
    while n % d != 0:
        d += 1
    return d == n

def gcd(a, b):
    if a == 0 or b == 0: 
        return max(a, b)
    else:
        if a > b:
            return gcd(a % b, b)
        else:
            return gcd(a, b % a)

def gcd_extended(a, b):
    if b == 0:
        gcd, x, y = a, 1, 0
        return gcd, x, y
    else:
        x2, x1, y2, y1 = 1, 0, 0, 1
        while b > 0:
            q = a // b
            r = a - q * b
            x = x2 - q * x1
            y = y2 - q * y1
            a, b, x2, x1, y2, y1 = b, r, x1, x, y1, y
        gcd, x, y = a, x2, y2
        return gcd, x, y

def pow(a, x, m):
    x_bin = []
    while x != 0:
        x_bin.insert(0, x % 2)
        x //= 2
    res = a
    for i in x_bin[1::]:
        if i == 1:
            res = res*res*a
        else:
            res = res*res
        res %= m
    return res

def encrypt(x, e, m):
    y = pow(x, e, m)
    return y
    
def decrypt(y, d, m):
    x = pow(y, d, m)
    return x
    
def main():
    p = int(input('Введите p: '))
    q = int(input('Введите q: '))
    d = int(input('Введите d: '))
    phi = (p-1)*(q-1)
    if not isPrime(p):
        print('p - не простое')
        input()
        exit()
    if not isPrime(q):
        print('q - не простое')
        input()
        exit()
    if d < 0:
        print('d должно быть положительным')
        input()
        exit()
    if gcd(d, phi) != 1:
        print('d и phi не взаимно простые')
        input()
        exit()
    m = p*q
    gcd_, x, y = gcd_extended(d, phi)
    e = (x % phi + phi) % phi
    key = int(input('1 - Зашфировать \n2 - Расшифровать\n'))
    if key == 1:
        x = int(input('Введите x: '))
        print(encrypt(x, e, m))
        input()
    elif key == 2:
        y = int(input('Введите y: '))
        print(decrypt(y, e, m))
        input()
        
if __name__ == '__main__':
    main()