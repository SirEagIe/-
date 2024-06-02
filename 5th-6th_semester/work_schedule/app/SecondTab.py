import tkinter as tk
from app.ViewAllForm import ViewAllForm

class SecondTab(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.view_all_form = ViewAllForm(self)
        self.view_all_form.pack(expand=True)