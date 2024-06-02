import tkinter as tk
from app.ViewForm import ViewForm

class ThirdTab(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.view_form = ViewForm(self)
        self.view_form.pack(expand=True)