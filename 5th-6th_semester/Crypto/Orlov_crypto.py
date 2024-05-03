import time

# Получение числа в двоичной системе исчисления
def to_bin(num):
    binary = []
    while num != 0:
        binary.insert(0, num % 2)
        num //= 2
    return binary

# Функция вычисления a^x (mod m) "в лоб"
def pow(a, x, m):
    res = 1
    for i in range(0, x):
        res *= a
    res %= m
    return res

# Функция вычисления a^x (mod m) с помощью быстрого алгоритма
def quick_pow(a, x, m):
    x_bin = to_bin(x)
    res = a
    for i in x_bin[1::]:
        if i == 1:
            res = res*res*a
        else:
            res = res*res
        res %= m
    return res

def main():
    a = int(input('Введите a: '))
    x = int(input('Введите x: '))
    m = int(input('Введите m: '))

    start_time = time.time()
    res = pow(a, x, m)
    print('Возведение в степень "в лоб":')
    print(a, '^', x, '(mod ', m, ') = ', res, sep='')
    print('Время выполнения:', time.time()-start_time, 'сек')
    
    start_time = time.time()
    res = quick_pow(a, x, m)
    print('Возведение в степень с помощью быстрого алгоритма:')
    print(a, '^', x, '(mod ', m, ') = ', res, sep='')
    print('Время выполнения:', time.time()-start_time, 'сек')

if __name__ == '__main__':
    main()



