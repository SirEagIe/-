import random

n = 100
X = []
for _ in range(n):
    print(U := [random.randint(0,100)/100 for _ in range(12)], f'sum(U) - 6 = {round(sum(U) - 6, 2)}', sep=', ')
    x = round(sum(U) - 6, 2)
    X.append(x)

print('Сгенерированная последовательность, имеющая нормальное распределение (по формуле ΣRi - 6) с параметрами 𝑎 = 0, 𝜎 = 1:')
print(X)

M = round(sum(X)/len(X), 3)
D = round(sum(list([Xi**2 for Xi in X]))/len(X) - (sum(X)/len(X))**2, 3)

print(f'Выборочное среднее M = {M}\nВыборочная дисперсия D = {D}')