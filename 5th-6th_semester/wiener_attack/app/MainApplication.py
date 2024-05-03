import tkinter as tk
from app.TabsList import TabsList
from app.FirstTab import FirstTab
from app.SecondTab import SecondTab
from app.ThirdTab import ThirdTab

class MainApplication(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame .__init__(self, parent, *args, **kwargs)
        self.parent = parent
        self.tabs_list = TabsList(self, 'Атака Винера', 'Генерация уязвимого ключа', 'Шифр RSA')
        self.tabs_list.grid(row=0, column=0)
        for i in range(len(self.tabs_list.get_tabs())):
            self.tabs_list.get_tabs()[i].bind('<Button-1>', lambda e, i=i: self.view_tab(i))
        self.tabs = []
        self.tabs.append(FirstTab(self))
        self.tabs.append(SecondTab(self))
        self.tabs.append(ThirdTab(self))
        self.view_tab(0)

    def view_tab(self, i):
        for j in range(len(self.tabs)):
            if j != i:
                self.tabs_list.get_tabs()[j].config(bg='#f0f0f0')
                self.tabs[j].grid_forget()
            else:
                self.tabs_list.get_tabs()[j].config(bg='#c0c0c0')
                self.tabs[j].grid(row=1, column=0, padx=20, pady=20)
