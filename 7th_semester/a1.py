import tkinter
from tkinter import *
from PIL import Image, ImageTk
import random

root = Tk()

# Create a photoimage object of the image in the path
img = Image.new('RGB', (100, 100), color = 'white')

#gen field
field = []
for i in range(100):
    field.append([])
    for j in range(100):
        if random.randint(0,10) == 1:
            field[i].append(1)
        else:
            field[i].append(0)
print(field)

def field_to_img(filed, img):
    img = Image.new('RGB', (100, 100), color = 'white')
    for i in range(100):
        for j in range(100):
            if field[i][j] == 1:
                img.putpixel((i,j),(0,0,0))
    return img
    

test = ImageTk.PhotoImage(img)

label1 = tkinter.Label(image=test)
label1.image = test
label1.place(x=0, y=0)

def callback(e):
    global img
    img = field_to_img(field, img)
    
    test = ImageTk.PhotoImage(img)
    label1.configure(image=test)
    label1.image = test

root.bind("<Return>", callback)
root.mainloop()