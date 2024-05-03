d = int(input())
x0 = 0
y0 = 0
i = 1
while True:
    x0 = (1+i*i*d)**0.5
    if int(x0) == float(x0):
        x0 = int(x0)
        y0 = i
        break
    i += 1
print('(', x0, ', ', y0, ')', sep='')
last_x = x0
last_y = y0
for i in range(0, 9):
    x = last_x*x0+d*last_y*y0
    y = last_x*y0+last_y*x0
    last_x = x
    last_y = y
    print('(', x, ', ', y, ')', sep='')
