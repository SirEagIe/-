zero_cycles = []
cycles = []

for seed in range(100):
    el = seed
    subsequence = [seed / 100]
    while True:
        el = el ** 2
        el = str(el).zfill(4)
        el = int(str(el).zfill(4)[1:3])
        if el == 0:
            zero_cycles.append(subsequence)
            break
        elif el / 100 in subsequence:
            cycles.append(subsequence)
            break
        else:
            subsequence.append(el / 100)
    print(f'Затравка -- {seed}')
    print(f'Последовательность:\n{subsequence}')
    print(f'Длина: {len(subsequence)}')
    print('Обращается в нуль' if subsequence in zero_cycles else 'Зацикливается')
    print('=================================================')
            
print(f'Количество последовательностей, сводящихся в нуль: {len(zero_cycles)}')
max_len = len(sorted(zero_cycles + cycles, key = len)[-1])
max_subsequences = [subseq for subseq in zero_cycles + cycles if len(subseq) == max_len]
print(f'Последовательность максимальной длины: {max_len}, затравки: {[int(el[0] * 100) for el in max_subsequences]}')