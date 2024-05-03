import tkinter as tk
import math

class TabsList(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.tabs = []
        self.num_of_tabs = len(args)
        for i in range(0, self.num_of_tabs):
            self.tabs.append(tk.Label(self, text=args[i], width=30, height=2))
        for i in range(0, self.num_of_tabs):
            self.tabs[i].pack(side='left', fill="both", expand=True)

    def get_tabs(self):
        return self.tabs






# Проверка на простоту
def is_prime(n):
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n and n % d != 0:
        d += 2
    return d * d > n

# Нахождение НОД
def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a % b)

# Получение числа в двоичной системе исчисления
def to_bin(num):
    binary = []
    while num != 0:
        binary.insert(0, num % 2)
        num //= 2
    return binary

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

# Тест Ферма на простоту
def ferma_test(num):
    if num == 2:
        return True
    for i in range(0, 100):
        a = random.randint(0, 10**300)
        if gcd(a ,num) != 1:
            return False
        if quick_pow(a, num - 1, num) != 1:
            return False
    return True

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
