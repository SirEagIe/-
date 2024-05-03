a = int(input('Введите а: '))
b = int(input('Введите b: '))

def gcd1(a, b):
    while a != 0 and b != 0:
        if a > b:
            a -= b
        else:
            b -= a
    return a or b

def gcd2(a, b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a or b

def gcd3(a, b): 
    if b == 0: 
        return a
    else:
        return gcd3(b, a % b)

print('НОД(', a, ', ', b ,') = ', gcd1(a, b), ' (реализация с помощью вычитания)',sep='')
print('НОД(', a, ', ', b ,') = ', gcd2(a, b), ' (реализация с помощью остатка от деления)', sep='')
print('НОД(', a, ', ', b ,') = ', gcd3(a, b), ' (реализация с помощью рекурсии)', sep='')