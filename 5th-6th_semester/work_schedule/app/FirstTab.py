import tkinter as tk
from app.AddForm import AddForm

class FirstTab(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.add_form = AddForm(self)
        self.add_form.pack(expand=True)