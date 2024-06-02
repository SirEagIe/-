import tkinter as tk

class TabsList(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, **kwargs)
        self.tabs = []
        self.num_of_tabs = len(args)
        for i in range(0, self.num_of_tabs):
            self.tabs.append(tk.Label(self, text=args[i], width=30, height=2))
        for i in range(0, self.num_of_tabs):
            self.tabs[i].pack(side='left', fill="both", expand=True)

    def get_tabs(self):
        return self.tabs