print('Введите разрядность k')
while True:
    k = input('>>> ')
    if not k.isdigit():
        print('Неверный ввод')
    else:
        break
k = int(k)

print('Введите количество генерируемых чисел')
while True:
    length = input('>>> ')
    if not length.isdigit():
        print('Неверный ввод')
    else:
        break
length = int(length)

print('Введите затравку')
while True:
    seed = input('>>> ')
    if not seed.isdigit() or \
            (seed.isdigit() and (int(seed) < 0 or int(seed) > 10**(2*k))):
        print('Неверный ввод')
    else:
        break
seed = int(seed)

print('x0\tx0^2\tu0\n--------------------')
el = seed
subsequence = []
for _ in range(length):
    print(el, end='\t')
    next_el = el ** 2
    next_el = str(next_el).zfill(4*k)
    print(next_el, end='\t')
    next_el = int(str(next_el).zfill(4)[k:3*k])
    norm_el = el / 10**(2*k)
    print(norm_el, end='\n')
    subsequence.append(norm_el)
    if next_el == 0:
        print('Обращение в нуль. Введите новую затравку')
        while True:
            next_el = input('>>> ')
            if not next_el.isdigit() or \
                    (next_el.isdigit() and (int(next_el) < 0 or int(next_el) > 10**(2*k))):
                print('Неверный ввод')
            else:
                break
        next_el = int(next_el)
    elif next_el / 10**(2*k) in subsequence:
        print('Зацикливание. Введите новую затравку')
        while True:
            next_el = input('>>> ')
            if not next_el.isdigit() or \
                    (next_el.isdigit() and (int(next_el) < 0 or int(next_el) > 10**(2*k))):
                print('Неверный ввод')
            else:
                break
        next_el = int(next_el)
    el = next_el
    
print(f'Итоговая последовательность: {subsequence}')