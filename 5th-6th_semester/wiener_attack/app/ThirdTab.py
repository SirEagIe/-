import tkinter as tk
from tkinter import messagebox
import random, math, re

class ThirdTab(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        tk.Label(self, text='Ввод').grid(row=0, column=0, columnspan=4, pady=2)
        self.input_entry = tk.Entry(self)
        self.input_entry.grid(row=1, column=0, columnspan=4, pady=2)

        tk.Label(self, text='e:').grid(row=2, column=0, pady=2)
        self.public_key_e_entry = tk.Entry(self)
        self.public_key_e_entry.grid(row=2, column=1, pady=2)
        tk.Label(self, text='m:').grid(row=3, column=0, pady=2)
        self.public_key_m_entry = tk.Entry(self)
        self.public_key_m_entry.grid(row=3, column=1, pady=2)

        tk.Label(self, text='d:').grid(row=2, column=2, pady=2)
        self.private_key_d_entry = tk.Entry(self)
        self.private_key_d_entry.grid(row=2, column=3, pady=2)
        tk.Label(self, text='m:').grid(row=3, column=2, pady=2)
        self.private_key_m_entry = tk.Entry(self)
        self.private_key_m_entry.grid(row=3, column=3, pady=2)

        self.button_encrypt = tk.Button(self, text='Зашифровать', command=self.encrypt)
        self.button_encrypt.grid(row=4, column=1, pady=2)

        self.button_decrypt = tk.Button(self, text='Дешифровать', command=self.decrypt)
        self.button_decrypt.grid(row=4, column=3, pady=2)

        tk.Label(self, text='Вывод').grid(row=5, column=0, columnspan=4, pady=2)
        self.output_entry = tk.Entry(self)
        self.output_entry.grid(row=6, column=0, columnspan=4, pady=2)

    def encrypt(self):
        message = self.input_entry.get()
        e = self.public_key_e_entry.get()
        m = self.public_key_m_entry.get()
        if not re.match(r'^[0-9]+$', e) or not re.match(r'^[0-9]+$', m) or not re.match(r'^[0-9]+$', message):
            tk.messagebox.showerror(title='Ошибка!', message='Неверно введены данные')
            return
        message = int(message)
        e = int(e)
        m = int(m)
        self.output_entry.delete(0, 'end')
        self.output_entry.insert(0, str(self.quick_pow(message, e, m)))

    def decrypt(self):
        ciphertext = self.input_entry.get()
        d = self.private_key_d_entry.get()
        m = self.private_key_m_entry.get()
        if not re.match(r'^[0-9]+$', d) or not re.match(r'^[0-9]+$', m) or not re.match(r'^[0-9]+$', ciphertext):
            tk.messagebox.showerror(title='Ошибка!', message='Неверно введены данные')
            return
        ciphertext = int(ciphertext)
        d = int(d)
        m = int(m)
        self.output_entry.delete(0, 'end')
        self.output_entry.insert(0, str(self.quick_pow(ciphertext, d, m)))

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
