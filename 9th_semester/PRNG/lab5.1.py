# n = 100
# ksi = 1 2 3 4 5 6 7 8 9
# p = 0.07 0.07 0.19 0.13 0.1 0.02 0.1 0.11 0.21
# Y = 6 4 21 11 12 4 12 13 17

print('\nВведите количество испытаний n:')
while True:
    n = input('>>> ')
    if not n.isdigit():
        print('Неверный ввод')
    else:
        break
n = int(n)

print('\nВведите значения случайной величины:')
while True:
    ksi = input('>>> ')
    if list(set([True for x in ksi.split(' ') if x.isdigit()])) != [True]:
        print('Неверный ввод')
    else:
        break
ksi = [int(x) for x in ksi.split(' ')]
ksi.sort()

print('\nВведите вероятности pi:')
while True:
    p = input('>>> ')
    if list(set([True for x in p.split(' ') if x.replace('0.', '').isdigit()])) != [True]:
        print('Неверный ввод')
    else:
        p = [float(x) for x in p.split(' ')]
        if len(p) != len(ksi):
            print('Неверный ввод (неверное количество значений)')
        else:
            if sum(p) != 1:
                print('Неверный ввод (сумма pi не равна 1)')
            else:
                break

table = [(ksi_i, p_i) for ksi_i, p_i in zip(ksi, p)]

for i in range(len(table)):
    table[i] = (table[i][0], table[i][1], int(table[i][1] * n))

print('ksi  ', end='')
for i in table:
    print('|', str(i[0]).rjust(7, ' '), sep='', end='')
print('\npi   ', end='')
for i in table:
    print('|', str(i[1]).rjust(7, ' '), sep='', end='')
print('\nnpi  ', end='')
for i in table:
    print('|', str(i[2]).rjust(7, ' '), sep='', end='')

print('\nВведите наблюдаемые значения Yi:')
while True:
    Y = input('>>> ')
    if list(set([True for x in Y.split(' ') if x.isdigit()])) != [True]:
        print('Неверный ввод')
    else:
        Y = [int(x) for x in Y.split(' ')]
        if len(Y) != len(ksi):
            print('Неверный ввод (неверное количество значений)')
        else:
            if sum(Y) != n:
                print('Неверный ввод (сумма Yi не равна n)')
            else:
                break

print('Yi   ', end='')
for i in Y:
    print('|', str(i).rjust(7, ' '), sep='', end='')

V = 0
for i in range(len(table)):
    V += (Y[i] - table[i][2]) ** 2 / table[i][2]

print(f'\nV = {round(V, 2)}')

knut_column = {0: '1%', 1: '5%', 2: '25%', 3: '50%', 4: '75%', 5: '95%', 6: '99%'}
knut_table = {
    1: [0.00016, 0.00393, 0.1015, 0.4549, 1.323, 3.841, 6.635],
    2: [0.02010, 0.1026, 0.5754, 1.386, 2.773, 5.991, 9.210],
    3: [0.1148, 0.3518, 1.213, 2.366, 4.108, 7.815, 11.34],
    4: [0.2971, 0.7107, 1.923, 3.357, 5.385, 9.488, 13.28],
    5: [0.5543, 1.1455, 2.675, 4.351, 6.626, 11.07, 15.09],
    6: [0.8721, 1.635, 3.455, 5.348, 7.841, 12.59, 16.81],
    7: [1.239, 2.167, 4.255, 6.346, 9.037, 14.07, 18.48],
    8: [1.646, 2.733, 5.071, 7.344, 10.22, 15.51, 20.09],
    9: [2.088, 3.325, 5.899, 8.343, 11.39, 16.92, 21.67],
    10: [2.558, 3.940, 6.737, 9.342, 12.55, 18.31, 23.21],
    11: [3.053, 4.575, 7.584, 10.34, 13.70, 19.68, 24.72],
    12: [3.571, 5.226, 8.438, 11.34, 14.85, 21.03, 26.22],
    15: [5.229, 7.261, 11.04, 14.34, 18.25, 25.00, 30.58],
    20: [8.260, 10.85, 15.45, 19.34, 23.83, 31.41, 37.57],
    30: [14.95, 18.49, 24.48, 29.34, 34.80, 43.77, 50.89],
    50: [29.71, 34.76, 42.94, 49.33, 56.33, 67.50, 76.15]
}

k = len(table)
print(f'k - 1 = {k - 1}')
v = k - 1
if v in list(knut_table.keys()):
    row_knut = knut_table[v]
else:
    x = [-2.33, -1.64, -0.674, 0, 0.674, 1.64, 2.33]
    row_knut = [v + (2*v)**0.5 * x_p + 2/3*x_p**2 - 2/3 for x_p in x]
res = []
if V < row_knut[0]:
    res = ['0%', knut_column[0]]
    print(f'{round(V, 2)} < {row_knut[0]}')
for i in range(len(row_knut) - 1):
    if row_knut[i] < V and V < row_knut[i + 1]:
        print(f'{row_knut[i]} < {round(V, 2)} < {row_knut[i+1]}')
        res = [knut_column[i], knut_column[i + 1]]
if V > row_knut[6]:
    res = [knut_column[6], '100%']
    print(f'{row_knut[6]} < {round(V, 2)}')
print(res)
if res == ['0%', '1%'] or res == ['99%', '100%']:
    print('Значения недостаточно случайные')
if res == ['1%', '5%'] or res == ['95%', '99%']:
    print('Значения подозрительны')
if res == ['5%', '25%'] or res == ['75%', '95%']:
    print('Значения почти подозрительны')
if res == ['25%', '50%'] or res == ['50%', '75%']:
    print('Значения удовлетворительно случайные')