import math
import time

def is_prime(n):
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n and n % d != 0:
        d += 2
    return d * d > n

def factorize(n):
    factors = []
    p = 2
    while True:
        while n % p == 0 and n > 0:
            factors.append(p)
            n = n / p
        p += 1
        if p > n / p:
            break
    if n > 1:
        factors.append(n)
    return factors

# Алгоритм быстрого возведения в степень
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
    
# Функция для получения подходящих дробей
def get_convergents_fractions(num1, num2):
    continued_fraction = []
    while num1 > 1:
        continued_fraction.append(math.floor(num1 / num2))
        num1 = num1 % num2
        num2, num1 = num1, num2
    convergents_fractions = []
    p1, p2 = 0, 1
    q1, q2 = 1, 0
    for i in range(0, len(continued_fraction)):
        p3 = continued_fraction[i] * p2 + p1
        q3 = continued_fraction[i] * q2 + q1
        convergents_fractions.append((p3, q3))
        p1, p2 = p2, p3
        q1, q2 = q2, q3
    return convergents_fractions
    
# Алгоритм решения линейного сравнения с помощью подходящих дробей
def linear_comparison_solution(a, b, m):
    convergents_fractions = get_convergents_fractions(m, a)
    n = len(convergents_fractions)
    x = (pow(-1, n - 1, m) * convergents_fractions[-2][0] * b) % m
    return x

def sum(curve, point1, point2):
    if point1[0] == point2[0] and point1[1] != point2[1]:
        return 'inf', 'inf'
    if point1[0] == 'inf':
        return point2
    if point2[0] == 'inf':
        return point1
    k = 0
    if point1[0] != point2[0] and point1[1] != point2[1]:
        if (point2[0] - point1[0]) % curve[0] == 1:
            k = (point2[1] - point1[1]) % curve[0]
        else:
            k = ((point2[1] - point1[1]) * linear_comparison_solution((point2[0] - point1[0])%curve[0] , 1, curve[0])) % curve[0]
    elif point1[0] == point2[0] and point1[1] == point2[1]:
        k = ((3*point1[0]*point1[0] + curve[1]) * linear_comparison_solution(2*point1[1] , 1, curve[0])) % curve[0]
    x3 = (k*k - (point1[0] + point2[0])) % curve[0]
    y3 = (k*(point1[0] - x3) - point1[1]) % curve[0]
    point3 = (x3, y3)
    return point3
    
def mult(curve, point, n):
    result_point = point
    for i in range(n - 1):
        result_point = sum(curve, result_point, point)
        print(result_point)
    return result_point

def quick_mult(curve, point, n):
    result_point = ('inf', 'inf')
    n_bin = []
    tmp = n
    while tmp != 0:
        n_bin.append(tmp % 2)
        tmp //= 2
    points = [point]
    for i in range(1, len(n_bin)):
        points.append(mult(curve, points[i - 1], 2))
    for i in range(len(n_bin)):
        if n_bin[i] == 1:
            result_point = sum(curve, result_point, points[i])
    return result_point

# Вычисление символа Лежандра
def legendre(a, p):
    if a >= p or a < 0:
        return legendre(a % p, p)
    elif a == 0 or a == 1:
        return a
    elif a == 2:
        if p % 8 == 1 or p % 8 == 7:
            return 1
        else:
            return -1
    elif a == p - 1:
        if p % 4 == 1:
            return 1
        else:
            return -1
    elif not is_prime(a):
        factors = factorize(a)
        product = 1
        for pi in factors:
            product *= legendre(pi, p)
        return product
    else:
        if ((p - 1) / 2) % 2 == 0 or ((a - 1) / 2) % 2 == 0:
            return legendre(p, a)
        else:
            return (-1) * legendre(p, a)

def num_of_point(curve):
    num = 0
    for i in range(0, curve[0]):
        if legendre(i**3+curve[1]*i+curve[2], curve[0]) == 1:
            num += 2
        if legendre(i**3+curve[1]*i+curve[2], curve[0]) == 0:
            num += 1
    num += 1
    return num

def point_order(curve, point):
    result = point
    order = 1
    while result != ('inf', 'inf'):
        result = sum(curve, result, point)
        order += 1
    return order

def main():
    p = int(input('p: '))
    a = int(input('a: '))
    b = int(input('b: '))
    curve = (p, a, b)
    while True:
        key = int(input('1 - Сложение\n2 - Умножение "в лоб"\n3 - Умножение с помощью быстрого алгоритма\n4 - Количество точек\n5 - Порядок точки\n6 - Выход\n'))
        if key == 1:
            x1 = int(input('x1: '))
            y1 = int(input('y1: '))
            point1 = (x1 % p, y1 % p)
            if (y1*y1)%p != (x1*x1*x1+a*x1+b)%p:
                print('Точка', point1, 'не принадлежит кривой!\n')
                input()
                continue
            x2 = int(input('x2: '))
            y2 = int(input('y2: '))
            point2 = (x2 % p, y2 % p)
            if (y2*y2)%p != (x2*x2*x2+a*x2+b)%p:
                print('Точка', point2, 'не принадлежит кривой!\n')
                input()
                continue
            result_point = sum(curve, point1, point2)
            print(point1, ' + ', point2, ' = ', result_point, sep='')
        if key == 2:
            n = int(input('n: '))
            x1 = int(input('x: '))
            y1 = int(input('y: '))
            point = (x1 % p, y1 % p)
            if (y1*y1)%p != (x1*x1*x1+a*x1+b)%p:
                print('Точка', point, 'не принадлежит кривой!\n')
                input()
                continue
            start_time = time.time()
            result_point = mult(curve, point, n)
            timer = time.time() - start_time
            print(n, '*', point, ' = ', result_point, sep='')
            print('Время выполнения:', timer)
        if key == 3:
            n = int(input('n: '))
            x1 = int(input('x: '))
            y1 = int(input('y: '))
            point = (x1 % p, y1 % p)
            if (y1*y1)%p != (x1*x1*x1+a*x1+b)%p:
                print('Точка', point, 'не принадлежит кривой!\n')
                input()
                continue
            start_time = time.time()
            result_point = quick_mult(curve, point, n)
            timer = time.time() - start_time
            print(n, '*', point, ' = ', result_point, sep='')
            print('Время выполнения:', timer)
        if key == 4:
            print('Количество точек кривой:', num_of_point(curve))
        if key == 5:
            x1 = int(input('x: '))
            y1 = int(input('y: '))
            point = (x1 % p, y1 % p)
            if (y1*y1)%p != (x1*x1*x1+a*x1+b)%p:
                print('Точка', point, 'не принадлежит кривой!\n')
                input()
                continue
            print('Порядок точки', point, '\b:', point_order(curve, point))
        if key == 6:
            break;
        input()
    
if __name__ == '__main__':
    main()
