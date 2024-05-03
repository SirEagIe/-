import math

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

# Функция для получения цепной дроби
def get_continued_fraction(num1, num2):
    continued_fraction = []
    while num1 > 1:
        continued_fraction.append(math.floor(num1 / num2))
        num1 = num1 % num2
        num2, num1 = num1, num2
    return continued_fraction
    
# Функция для получения подходящих дробей
def get_convergents_fractions(num1, num2):
    continued_fraction = get_continued_fraction(num1, num2)
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

def main():
    key = int(input('1 - получение подходящих дробей\n2 - решение линейного сравнения\n'))
    if key == 1:
        num1 = int(input('Числитель: '))
        num2 = int(input('Знаменатель: '))
        print(get_convergents_fractions(num1, num2))
    if key == 2:
        a = int(input('a: '))
        b = int(input('b: '))
        m = int(input('m: '))
        print('x =', linear_comparison_solution(a, b, m))
    input()
    
if __name__ == '__main__':
    main()