import tkinter as tk
from tkinter import messagebox, ttk
import sqlite3 as sql
from app.Calendar import ViewCalendar
import os, sys

class ViewForm(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.enter_frame = tk.Frame(self)
        self.names = []
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            cursor.execute("SELECT name FROM `work_schedule`")
            rows = cursor.fetchall()
            for row in rows:
                self.names.append(row[0])
        self.names = list(set(self.names))
        self.names.sort()
        self.name_entry = ttk.Combobox(self.enter_frame, values=self.names, width=45)
        self.name_entry.bind('<Button-1>', self.search)
        self.name_entry.pack(fill='both', expand=True, pady=10)
        self.apply_btn = tk.Button(self.enter_frame, text='Посмотреть график', command=self.view_scedule)
        self.apply_btn.pack(fill='both', expand=True, pady=10)
        self.enter_frame.pack(fill='both', expand=True)
        
    def view_scedule(self):
        if self.name_entry.get() in self.names:
            self.enter_frame.pack_forget()
            self.schedule_frame = tk.Frame(self)
            self.calendar = ViewCalendar(self.schedule_frame, self.name_entry.get())
            self.calendar.pack()
            self.back_btn = tk.Button(self.schedule_frame, text='Назад', width=30, command=self.back)
            self.back_btn.pack(pady=5)
            self.schedule_frame.pack(fill='both', expand=True)
        else:
            tk.messagebox.showerror(title='Error', message='Сотрудник не найден')

    def back(self):
        self.schedule_frame.destroy()
        self.enter_frame.pack(fill='both', expand=True)
    
    def search(self, event):
        values = []
        for name in self.names:
            if self.name_entry.get().lower() in name.lower():
                values.append(name)
        self.name_entry.config(values=values)
        
    def update_(self):
        self.names = []
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            cursor.execute("SELECT name FROM `work_schedule`")
            rows = cursor.fetchall()
            for row in rows:
                self.names.append(row[0])
        self.names = list(set(self.names))
        self.names.sort()
        self.name_entry.config(values=self.names)