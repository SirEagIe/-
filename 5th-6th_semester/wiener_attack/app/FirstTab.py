import tkinter as tk
from tkinter import messagebox
import math, re

class FirstTab(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        tk.Label(self, text='Шифротекст:').grid(row=0, column=0, pady=2)
        self.input_entry = tk.Entry(self)
        self.input_entry.grid(row=0, column=1, pady=2)

        tk.Label(self, text='e:').grid(row=1, column=0, pady=2)
        self.public_key_e_entry = tk.Entry(self)
        self.public_key_e_entry.grid(row=1, column=1, pady=2)
        tk.Label(self, text='m:').grid(row=2, column=0, pady=2)
        self.public_key_m_entry = tk.Entry(self)
        self.public_key_m_entry.grid(row=2, column=1, pady=2)

        self.button_attack = tk.Button(self, text='Атака Винера', command=self.wiener_attack)
        self.button_attack.grid(row=3, column=0, columnspan=2, pady=2)

        tk.Label(self, text='Открытый текст:').grid(row=4, column=0, pady=2)
        self.output_entry = tk.Entry(self)
        self.output_entry.grid(row=4, column=1, pady=2)
        tk.Label(self, text='Закрытая экспонента d:').grid(row=5, column=0, pady=2)
        self.private_key_d_entry = tk.Entry(self)
        self.private_key_d_entry.grid(row=5, column=1, pady=2)

    def wiener_attack(self):
        ciphertext = self.input_entry.get()
        e = self.public_key_e_entry.get()
        m = self.public_key_m_entry.get()
        if not re.match(r'^[0-9]+$', e) or not re.match(r'^[0-9]+$', m) or not re.match(r'^[0-9]*$', ciphertext):
            tk.messagebox.showerror(title='Ошибка!', message='Неверно введены данные')
            return
        if ciphertext != '':
            ciphertext = int(ciphertext)
        e = int(e)
        m = int(m)
        d = -1
        try:
            convergents_fractions = self.get_convergents_fractions(e, m)
            for i in range(1, len(convergents_fractions)):
                phi = (e*convergents_fractions[i][1]-1) // convergents_fractions[i][0]
                p, q = self.quadratic_equation(1, -(m-phi+1), m)
                if p != None and q != None and p*q == m:
                    d = convergents_fractions[i][1]
                    break
        except:
            tk.messagebox.showerror(title='Ошибка!', message='Атака Винера не применима')
            return
        if d == -1:
            tk.messagebox.showerror(title='Ошибка!', message='Атака Винера не применима')
            return
        if ciphertext != '':
            self.output_entry.delete(0, 'end')
            self.output_entry.insert(0, str(self.quick_pow(ciphertext, d, m)))
        self.private_key_d_entry.delete(0, 'end')
        self.private_key_d_entry.insert(0, str(d))

    def isqrt(self, x):
        N = 0
        a = 0
        L = x.bit_length()
        L += (L % 2)
        for i in range(L, -1, -1):
            n = (x >> (2*i)) & 0b11
            if ((N - a*a) << 2) + n >= (a << 2) + 1:
                b = 1
            else:
                b = 0
            a = (a << 1) | b
            N = (N << 2) | n
        return a, N-a*a

    def quadratic_equation(self, a, b, c):
        sqrt_d = self.isqrt(b**2 - 4*a*c)
        if sqrt_d[1] != 0:
            return (None, None)
        elif (-b + sqrt_d[0]) % (2*a) != 0 or (-b - sqrt_d[0]) % (2*a) != 0:
            return (None, None)
        else:
            x1 = (-b + sqrt_d[0])//(2*a)
            x2 = (-b - sqrt_d[0])//(2*a)
            return x1, x2

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
