import random

t = 10
p = 0.75
n = 100

N = []
for _ in range(n):
    U = [random.randint(0,100)/100 for _ in range(t)]
    print(f'U = {U}, count(Ui: Ui < {p}) = {len([Ui for Ui in U if Ui < p])}')
    N.append(len([Ui for Ui in U if Ui < p]))

print(f'Сгенерированная последовательность, имеющая биномиальное распределение с параметрами t = {t}, p = {p}:')
print(N)

M = round(sum(N)/len(N), 3)
D = round(sum(list([Ni**2 for Ni in N]))/len(N) - (sum(N)/len(N))**2, 3)

print(f'Выборочное среднее M = {M}\nВыборочная дисперсия D = {D}')