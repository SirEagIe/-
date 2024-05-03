import random
import math
import numpy

L = 5
n = 100

N = []
for _ in range(n):
    U = [random.randint(0,100)/100]
    while numpy.prod(U) > math.exp(-L):
        U.append(random.randint(0,100)/100)
    print(f'U = {U}, prod(U) <= e^-λ = {round(math.exp(-L), 10)}, m - 1 = {len(U) - 1}')
    N.append(len(U) - 1)

print(f'Сгенерированная последовательность, имеющая пуассоновское распределение с параметром λ = {L}:')
print(N)

M = round(sum(N)/len(N), 3)
D = round(sum(list([Ni**2 for Ni in N]))/len(N) - (sum(N)/len(N))**2, 3)

print(f'Выборочное среднее M = {M}\nВыборочная дисперсия D = {D}')