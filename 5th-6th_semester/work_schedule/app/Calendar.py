import tkinter as tk
import calendar as cldr
import datetime as dt
import sqlite3 as sql
import os, sys

class Calendar(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.now = dt.datetime.date(dt.datetime.today())
        self.current_date = self.now
        self.calendar = cldr.Calendar(firstweekday=0)
        self.form_head()
        self.form_weeks()
        self.form_days()

    def form_head(self):
        self.head = tk.Frame(self, bg='#3300CC')
        self.month_and_year = tk.Label(self.head,
            text=self.current_date.strftime('%B')+', '+self.current_date.strftime('%Y'),
            bg='#6633FF', width=45, height=2)
        self.button_left = tk.Button(self.head, text='<', borderwidth=0, bg='#6633FF')
        self.button_left.config(command=self.left)
        self.button_right = tk.Button(self.head, text='>', borderwidth=0, bg='#6633FF')
        self.button_right.config(command=self.right)
        self.button_left.pack(side='left', fill='both', padx=1, pady=1, expand=True)  
        self.month_and_year.pack(side='left', fill='both', padx=1, pady=1)
        self.button_right.pack(side='left', fill='both', padx=1, pady=1, expand=True)
        self.name_of_weeks_frame = tk.Frame(self, bg='#3300CC')
        self.name_of_weeks = []
        i = 0
        for name_of_week in ['Пн', 'Вт', 'Ср', 'Чт', 'Пт', 'Сб', 'Вс']:
            self.name_of_weeks.append(tk.Label(self.name_of_weeks_frame, text=name_of_week,
                width=7, height=1, bg='#6666FF'))
            self.name_of_weeks[i].pack(side='left', padx=1, pady=1)
            i += 1
        self.head.pack(fill='both')
        self.name_of_weeks_frame.pack(fill='both')
        
    def form_weeks(self):
        num_of_weeks = len(self.calendar.monthdatescalendar(self.current_date.year, self.current_date.month))
        self.weeks = [tk.Frame(self) for i in range(num_of_weeks)]
        for week in self.weeks:
            week.pack(fill='both', expand=True)
            
    def form_days(self):
        self.days = []
        i = 0
        for day in self.calendar.itermonthdates(self.current_date.year, self.current_date.month):
            self.days.append(tk.Label(self.weeks[i//7], text=day.day,
                width=7, height=2, bg='#CCCCCC'))
            if day.year == self.now.year and day.month == self.now.month and day.day == self.now.day:
                self.days[i].config(borderwidth=2, relief='solid')
            if day.month != self.current_date.month:
                self.days[i].config(bg = '#999999')
            i += 1
        for day in self.days:
            day.pack(side='left', fill='both', expand=True, padx=1, pady=1)
    
    def update_(self):
        self.month_and_year.config(text=self.current_date.strftime('%B')+', '+self.current_date.strftime('%Y'))
        num_of_weeks = len(self.calendar.monthdatescalendar(self.current_date.year, self.current_date.month))
        while len(self.weeks) != num_of_weeks:
            if len(self.weeks) > num_of_weeks:
                self.weeks[-1].pack_forget()
                self.weeks.remove(self.weeks[-1])
            elif len(self.weeks) < num_of_weeks:
                self.weeks.append(tk.Frame(self))
                self.weeks[-1].pack(fill='both', expand=True)
        for day in self.days:
            day.destroy()
        self.form_days()
            
    def left(self):
        self.current_date = self.current_date.replace(day=1) - dt.timedelta(days=1)
        self.update_()
        
    def right(self):
        self.current_date = self.current_date.replace(
            day=cldr.monthrange(self.current_date.year, self.current_date.month)[1]) + dt.timedelta(days=1)
        self.update_()


class AddCalendar(Calendar):
    def __init__(self, parent, *args, **kwargs):
        self.choosen_days = []
        Calendar.__init__(self, parent, *args, **kwargs)
        
    def form_days(self):
        super().form_days()
        i = 0
        for day in self.calendar.itermonthdates(self.current_date.year, self.current_date.month):
            if day.month == self.current_date.month:
                if day in self.choosen_days:
                    self.days[i].config(bg = '#6666FF')
                self.days[i].bind('<Button-1>', lambda e, i=i, day=day: self.choose(self.days[i], day))
            i += 1

    def choose(self, label, day):
        if not day in self.choosen_days:
            label.config(bg='#6666FF')
            self.choosen_days.append(day)
        else:
            label.config(bg='#CCCCCC')
            self.choosen_days.remove(day)
    
    def get_choosen(self):
        return self.choosen_days
        
class ViewAllCalendar(Calendar):
    def __init__(self, parent, *args, **kwargs):
        Calendar.__init__(self, parent, *args, **kwargs)
        
    def form_days(self):
        super().form_days()
        i = 0
        for day in self.calendar.itermonthdates(self.current_date.year, self.current_date.month):
            if day.month == self.current_date.month:
                self.days[i].bind('<Button-1>', lambda e, i=i, day=day: self.view_schedule(self.days[i], day))
            i += 1
            
    def view_schedule(self, event, day):
        self.new_window = tk.Toplevel()
        self.new_window.focus_force()
        self.schedule_frame = tk.Frame(self.new_window)
        date_label = tk.Label(self.schedule_frame, text=day.strftime('%d %B %Y'))
        date_label.grid(row=0, column=0, padx=5, pady=5, columnspan=5)
        self.schedule = []
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            cursor.execute(f"SELECT * FROM `work_schedule` WHERE date='{day}' ORDER BY name")
            rows = list(cursor.fetchall())
            for row in rows:
                self.schedule.append([tk.Label(self.schedule_frame, text=str(row[0])),
                    tk.Label(self.schedule_frame, text=str(row[2])),
                    tk.Label(self.schedule_frame, text='-'),
                    tk.Label(self.schedule_frame, text=str(row[3])),
                    tk.Button(self.schedule_frame, text='X')])
            if not self.schedule:
                tk.Label(self.schedule_frame, text='Записи отсутствуют').grid(row=1, column=0, padx=5, pady=5, columnspan=4)
            for i in range(len(self.schedule)):
                self.schedule[i][0].grid(row=i+1, column=0, padx=5, pady=5)
                self.schedule[i][1].grid(row=i+1, column=1, padx=5, pady=5)
                self.schedule[i][2].grid(row=i+1, column=2, padx=5, pady=5)
                self.schedule[i][3].grid(row=i+1, column=3, padx=5, pady=5)
                self.schedule[i][4].config(command=lambda row=rows[i], i=i: self.delete(row, i))
                self.schedule[i][4].grid(row=i+1, column=4, padx=5, pady=5)
        self.schedule_frame.pack(expand=True, padx=10, pady=10)
        x_pos = (self.new_window.winfo_screenwidth() - self.new_window.winfo_width())//2
        y_pos = (self.new_window.winfo_screenheight() - self.new_window.winfo_height())//2
        self.new_window.geometry('+' + str(x_pos) + '+' + str(y_pos))
        self.new_window.update()
        self.new_window.minsize(self.new_window.winfo_width(), self.new_window.winfo_height())
        self.new_window.bind("<Escape>", lambda event: self.new_window.destroy())
    
    def delete(self, row, i):
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            cursor.execute(f"DELETE FROM `work_schedule` WHERE name='{row[0]}' AND date='{row[1]}' AND time1='{row[2]}' AND time2='{row[3]}'")
            connection.commit()
        for j in range(len(self.schedule[i])):
            self.schedule[i][j].grid_forget()
        restore_button = tk.Button(self.schedule_frame, text='Восстановить')
        restore_button.config(command=lambda restore_button=restore_button, row=row, i=i: self.restore(restore_button, row, i))
        restore_button.grid(row=i+1, column=0, padx=5, pady=5, columnspan=5)
    
    def restore(self, r_btn, row, i):
        r_btn.grid_forget()
        self.schedule[i][0].grid(row=i+1, column=0, padx=5, pady=5)
        self.schedule[i][1].grid(row=i+1, column=1, padx=5, pady=5)
        self.schedule[i][2].grid(row=i+1, column=2, padx=5, pady=5)
        self.schedule[i][3].grid(row=i+1, column=3, padx=5, pady=5)
        self.schedule[i][4].config(command=lambda row=row, i=i: self.delete(row, i))
        self.schedule[i][4].grid(row=i+1, column=4, padx=5, pady=5)
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            cursor.execute(f"INSERT INTO `work_schedule` VALUES ('{row[0]}', '{row[1]}', '{row[2]}', '{row[3]}')")
            connection.commit()


class ViewCalendar(Calendar):
    def __init__(self, parent, name, *args, **kwargs):
        self.name = name
        Calendar.__init__(self, parent, *args, **kwargs)
    
    def form_head(self):
        super().form_head()
        self.month_and_year.config(width=65)
        
    def form_weeks(self):
        super().form_weeks()
        for name_of_week in self.name_of_weeks:
            name_of_week.config(width=10)
    
    def form_days(self):
        super().form_days()
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        rows = []
        with connection:
            cursor = connection.cursor()
            cursor.execute(f"SELECT * FROM `work_schedule` WHERE name='{self.name}'")
            rows_ = cursor.fetchall()
            for row in rows_:
                rows.append(list(row))
        i = 0
        for day in self.calendar.itermonthdates(self.current_date.year, self.current_date.month):
            self.days[i].config(width=10)
            for row in rows:
                if str(day) in row:
                    self.days[i].config(text=str(day.day) + f'\n{row[2]}-{row[3]}')
            i += 1
        label_text = 'Количество часов по неделям: '
        for i in range(len(self.weeks)):
            label_text += str(i + 1) + ' - ' + self.get_week_time()[i] + '; '
        label_text = label_text[:-2]
        self.week_time_label = tk.Label(self, text=label_text)
        label_text = 'Количество часов в месяц: ' + self.get_month_time()
        self.month_time_label = tk.Label(self, text=label_text)
        self.month_time_label.pack(side='bottom', pady=5)
        self.week_time_label.pack(side='bottom', pady=5)
        
    def update_(self):
        self.week_time_label.destroy()
        self.month_time_label.destroy()
        super().update_()
    
    def get_week_time(self):
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            self.week_time = []
            for week in self.calendar.monthdatescalendar(self.current_date.year, self.current_date.month):
                week_time = dt.timedelta(hours=0, minutes=0)
                for day in week:
                    cursor.execute(f"SELECT * FROM `work_schedule` WHERE name='{self.name}' AND date='{str(day)}'")
                    rows = cursor.fetchall()
                    for row in rows:
                        week_time += dt.timedelta(hours=int(row[3][0]+row[3][1]), minutes=int(row[3][3]+row[3][4])) \
                            - dt.timedelta(hours=int(row[2][0]+row[2][1]), minutes=int(row[2][3]+row[2][4]))
                days = week_time.days
                minutes = week_time.seconds // 60
                hours = str(24 * days + minutes // 60)
                minutes = str(minutes % 60)
                if len(hours) < 2:
                    hours = '0' + hours
                if len(minutes) < 2:
                    minutes = '0' + minutes
                self.week_time.append(hours + ':' + minutes)
        return self.week_time
    
    def get_month_time(self):
        self.month_time = dt.timedelta(hours=0, minutes=0)
        connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
        with connection:
            cursor = connection.cursor()
            for day in self.calendar.itermonthdates(self.current_date.year, self.current_date.month):
                if day.month == self.current_date.month and day.year == self.current_date.year:
                    cursor.execute(f"SELECT * FROM `work_schedule` WHERE name='{self.name}' AND date='{str(day)}'")
                    rows = cursor.fetchall()
                    for row in rows:
                        self.month_time += dt.timedelta(hours=int(row[3][0]+row[3][1]), minutes=int(row[3][3]+row[3][4])) \
                            - dt.timedelta(hours=int(row[2][0]+row[2][1]), minutes=int(row[2][3]+row[2][4]))
            days = self.month_time.days
            minutes = self.month_time.seconds // 60
            hours = str(24 * days + minutes // 60)
            minutes = str(minutes % 60)
            if len(hours) < 2:
                hours = '0' + hours
            if len(minutes) < 2:
                minutes = '0' + minutes
            self.month_time = hours + ':' + minutes
        return self.month_time