import random
import math

X = []
for _ in range(50):
    U1, U2 = random.randint(0,100)/100, random.randint(0,100)/100
    V1 = 2*U1 - 1
    V2 = 2*U2 - 1
    S = V1**2 + V2**2
    if S < 1:
        X1 = V1*(-2*math.log(S)/S)**0.5
        X2 = V2*(-2*math.log(S)/S)**0.5
        X.append(round(X1, 2))
        X.append(round(X2, 2))
        print(f'U1 = {U1}, U2 = {U2}, V1 = {round(V1, 2)}, V2 = {round(V2, 2)}, X1 = {round(X1, 2)}, X2 = {round(X2, 2)}')

print('Сгенерированная последовательность, имеющая нормальное распределение (методом полярных координат) с параметрами 𝑎 = 0, 𝜎 = 1:')
print(X)

M = round(sum(X)/len(X), 3)
D = round(sum(list([Xi**2 for Xi in X]))/len(X) - (sum(X)/len(X))**2, 3)

print(f'Выборочное среднее M = {M}\nВыборочная дисперсия D = {D}')