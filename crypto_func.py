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

# Нахождение НОД
def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a % b)

# Функция вычисления a^x (mod m) с помощью быстрого алгоритма
def quick_pow(a, x, m):
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

# Тест Ферма на простоту
def ferma_test(num):
    if num == 2:
        return True
    for i in range(0, 100):
        a = random.randint(0, num)
        if gcd(a ,num) != 1:
            return False
        if quick_pow(a, num - 1, num) != 1:
            return False
    return True

# Функция для получения подходящих дробей
def get_convergents_fractions(num1, num2):
    continued_fraction = []
    while num1 > 1:
        continued_fraction.append(num1 // num2)
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

# y^2=x^3+ax+b, GF(p); curve=(p, a, b)
def sum_curve(curve, point1, point2):
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
    
def mult_curve(curve, point, n):
    s = 1
    if n < 0:
        n *= -1
        s = -1
    result_point = point
    for i in range(n - 1):
        result_point = sum_curve(curve, result_point, point)
    result_point = (result_point[0], s * result_point[1] % curve[0])
    return result_point

def quick_mult_curve(curve, point, n):
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
        result = sum_curve(curve, result, point)
        order += 1
    return order
