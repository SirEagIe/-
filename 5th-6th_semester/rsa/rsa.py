import tkinter as tk
from app import MainApplication
import sys
import locale

if sys.platform == 'win32':
    locale.setlocale(locale.LC_ALL, 'rus_rus')
else:
    locale.setlocale(locale.LC_ALL, 'ru_RU.UTF-8')

root = tk.Tk()
MainApplication(root).pack(side='top', fill='both', expand=True)
root.update()
root.minsize(root.winfo_width(), root.winfo_height())
root.mainloop()
