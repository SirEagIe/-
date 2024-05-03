import tkinter as tk
import random, math

class SecondTab(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        tk.Label(self, text='Генерация ключей порядка 1024 бит (с маленьким d)').grid(row=0, column=0, columnspan=4, pady=2)

        tk.Label(self, text='Открытый ключ').grid(row=1, column=1, pady=2)
        tk.Label(self, text='e:').grid(row=2, column=0, pady=2)
        self.public_key_e_entry = tk.Entry(self)
        self.public_key_e_entry.grid(row=2, column=1, pady=2)
        tk.Label(self, text='m:').grid(row=3, column=0, pady=2)
        self.public_key_m_entry = tk.Entry(self)
        self.public_key_m_entry.grid(row=3, column=1, pady=2)

        tk.Label(self, text='Закрытый ключ').grid(row=1, column=3, pady=2)
        tk.Label(self, text='d:').grid(row=2, column=2, pady=2)
        self.private_key_d_entry = tk.Entry(self)
        self.private_key_d_entry.grid(row=2, column=3, pady=2)
        tk.Label(self, text='m:').grid(row=3, column=2, pady=2)
        self.private_key_m_entry = tk.Entry(self)
        self.private_key_m_entry.grid(row=3, column=3, pady=2)

        self.button_gen = tk.Button(self, text='Сгенерировать', command=self.generate)
        self.button_gen.grid(row=4, column=0, columnspan=4, pady=2)


    def generate(self):
        public_key, private_key = self.generate_vulnerable_key()
        self.public_key_e_entry.delete(0, 'end')
        self.public_key_m_entry.delete(0, 'end')
        self.private_key_d_entry.delete(0, 'end')
        self.private_key_m_entry.delete(0, 'end')
        self.public_key_e_entry.insert(0, public_key[0])
        self.public_key_m_entry.insert(0, public_key[1])
        self.private_key_d_entry.insert(0, private_key[0])
        self.private_key_m_entry.insert(0, private_key[1])

    # Нахождение НОД
    def gcd(self, a, b):
        if b==0:
            return a
        return self.gcd(b, a % b)

    # Функция вычисления a^x (mod m) с помощью быстрого алгоритма
    def quick_pow(self, a, x, m):
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
    def ferma_test(self, num):
        if num == 2:
            return True
        for i in range(0, 100):
            a = random.randint(0, num)
            if self.gcd(a ,num) != 1:
                return False
            if self.quick_pow(a, num - 1, num) != 1:
                return False
        return True

    # Функция для получения подходящих дробей
    def get_convergents_fractions(self, num1, num2):
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
    def linear_comparison_solution(self, a, b, m):
        convergents_fractions = self.get_convergents_fractions(m, a)
        n = len(convergents_fractions)
        x = (pow(-1, n - 1, m) * convergents_fractions[-2][0] * b) % m
        return x

    def generate_vulnerable_key(self):
        p_bin = [1]
        for i in range(0, 511):
            p_bin.append(round(random.random()*10)%2)
        p = ''
        for i in range(0, len(p_bin)):
            p += str(p_bin[i])
        p = int(p, 2)
        while not self.ferma_test(p):
            p += 1
        q_bin = [1]
        for i in range(0, 511):
            q_bin.append(round(random.random()*10)%2)
        q = ''
        for i in range(0, len(q_bin)):
            q += str(q_bin[i])
        q = int(q, 2)
        while not self.ferma_test(q):
            q += 1
        m = p*q
        phi = (p - 1)*(q - 1)
        d = random.randint(2, math.floor(1/3*m**(1/4)))
        while self.gcd(d, phi) != 1:
            d += 1
        e = self.linear_comparison_solution(d, 1, phi)
        return (e, m), (d, m)
