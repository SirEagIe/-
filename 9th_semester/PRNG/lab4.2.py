#m = 2**32
#a = 1664525
#c = 1013904223

m = 1000
a = 377
c = 41

print(f'Параметры линейного конгруэнтного метода:\nm = {m}\na = {a}\nc = {c}')

print('Введите количество генерируемых чисел')
while True:
    length = input('>>> ')
    if not length.isdigit() or \
            (length.isdigit() and int(length) < 55):
        print('Неверный ввод')
    else:
        break
length = int(length)

print('Введите затравку для ЛКМ')
while True:
    seed = input('>>> ')
    if not seed.isdigit():
        print('Неверный ввод')
    else:
        break
seed = int(seed)

subsequence = [seed]
el = seed
for _ in range(54):
    print(f'({a} * {el} + {c}) % {m} = {(a * el + c) % m}')
    el = (a * el + c) % m
    subsequence.append(el)

for _ in range(length - 55):
    el = (subsequence[-24] + subsequence[-55]) % m
    print(f'({subsequence[-24]} + {subsequence[-55]}) % {m} = {el}')
    subsequence.append(el)

print('\nСгенерированная последовательность:')
print(subsequence)