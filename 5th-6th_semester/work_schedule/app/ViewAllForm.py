import tkinter as tk
from tkinter import messagebox, ttk
import sqlite3 as sql
from app.Calendar import ViewAllCalendar
import os, sys

class ViewAllForm(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.calendar = ViewAllCalendar(self)
        self.calendar.pack()