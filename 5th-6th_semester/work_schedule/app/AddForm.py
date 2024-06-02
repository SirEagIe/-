import tkinter as tk
from tkinter import messagebox, ttk
import re
import sqlite3 as sql
from app.Calendar import AddCalendar
import datetime as dt
import os, sys

class AddForm(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.calendar = AddCalendar(self)
        self.calendar.pack()
        self.fields_frame = tk.Frame(self)
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
        self.name_label = tk.Label(self.fields_frame, text='ФИО')
        self.time_label_1 = tk.Label(self.fields_frame, text='Время работы с (ЧЧ:ММ)')
        self.time_label_2 = tk.Label(self.fields_frame, text='до (ЧЧ:ММ)')
        self.name_entry = ttk.Combobox(self.fields_frame, values=self.names)
        self.name_entry.bind('<Button-1>', self.search)
        self.time_entry_2 = tk.Entry(self.fields_frame)
        self.time_entry_1 = tk.Entry(self.fields_frame)
        self.apply_btn = tk.Button(self.fields_frame, text='Добавить', command=self.add)
        self.name_label.grid(row=0, column=0, pady=5)
        self.time_label_1.grid(row=1, column=0, pady=5)
        self.time_label_2.grid(row=2, column=0, pady=5)
        self.name_entry.grid(row=0, column=1, pady=5)
        self.time_entry_1.grid(row=1, column=1, pady=5)
        self.time_entry_2.grid(row=2, column=1, pady=5)
        self.apply_btn.grid(row=3, column=0, pady=5, columnspan=2)
        self.fields_frame.pack(expand=True)

    def add(self):
        message_error = ''
        dates = []
        if self.calendar.get_choosen():
            dates = self.calendar.get_choosen()
        else:
            message_error += 'Дата не выбрана\n'
        name = ''
        if self.name_entry.get():
            name = self.name_entry.get()
        else:
            message_error += 'Имя не введено\n'
        time1, time2 = '', ''
        if self.validate_time(self.time_entry_1.get(), self.time_entry_2.get()):
            time1 = self.time_entry_1.get()
            time2 = self.time_entry_2.get()
            time1 = time1[:2] + ':' + time1[2 + 1:]
            time2 = time2[:2] + ':' + time2[2 + 1:]
        else:
            message_error += 'Время введено неверно\n'
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            for date in dates:
                cursor.execute(f"SELECT * FROM `work_schedule` WHERE name='{name}' AND date='{date}'")
                rows = cursor.fetchall()
                if len(rows) != 0:
                    message_error += f'Для данного человека уже записаны часы работы\nна {date.strftime("%d %B %Y")}\n'
        if message_error:
            tk.messagebox.showerror(title='Error', message=message_error)
        else:
            connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
            with connection:
                cursor = connection.cursor()
                for date in dates:
                    cursor.execute(f"INSERT INTO `work_schedule` VALUES ('{name}', '{date}', '{time1}', '{time2}')")
                if not name in self.names:
                    self.names.append(name)
                    self.names.sort()
                    self.name_entry.config(values=self.names)
                connection.commit()

    def search(self, event):
        values = []
        for name in self.names:
            if self.name_entry.get().lower() in name.lower():
                values.append(name)
        self.name_entry.config(values=values)
    
    def validate_time(self, time1, time2):
        try:
            t1 = dt.timedelta(hours=int(time1[0]+time1[1]), minutes=int(time1[3]+time1[4]))
            t2 = dt.timedelta(days=1, hours=int(time2[0]+time2[1]), minutes=int(time2[3]+time2[4]))
            if t1.days != 0 or t2.days != 1 or (t2 - t1).days == 0:
                return False
            else:
                return True            
        except:
            return False
