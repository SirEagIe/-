a = int(input('Введите генератор a: '))
b = int(input('Введите число b: '))
n = int(input('Введите порядок n циклической группы G: '))

a %= n
b %= n

def quick_pow(a, x, n):
    x_bin = []
    while x != 0:
        x_bin.insert(0, x % 2)
        x //= 2
    res = a
    for i in x_bin[1::]:
        if i == 1:
            res = res*res*a
        else:
            res = res*res
        res %= n
    return res

m = int(n**0.5) + 1

gammas = []
gamma = 1
pow_of_a = quick_pow(a, m, n)

for i in range(1, m + 1):
    gamma *= pow_of_a
    gamma %= n
    gammas.append(gamma)

res = -1
tmp = b
for j in range(0, m):
    if tmp in gammas:
        res = (gammas.index(tmp) + 1)*m - j
        break
    tmp *= a
    tmp %= n

if res != -1:
    print(f'{a}^{res} = {b} (mod {n})')
    print('Ответ:', res)
else:
    print('Решение не найдено!')
