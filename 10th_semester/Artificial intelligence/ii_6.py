# Исходные данные
X = [
    [0, 1, 0, 1],
    [1, 1, 0, 0],
    [0, 0, 1, 1],
    [1, 0, 1, 0],
]

# Начальные весовые значения
W = [
    [0.2, 0.9, 0.3, 0.4],
    [0.4, 0.9, 0.4, 0.3]
]

# Норма обучения
n = 0.5

# Цикл обучения
for k in range(50):
    clusters = []
    for i in range(len(X)):
        # Подсчёт выходов нейронов (евклидова метрика)
        r_1 = sum([(x - w)**2 for x, w in zip(X[i], W[0])])
        r_2 = sum([(x - w)**2 for x, w in zip(X[i], W[1])])
        
        # Определение "победителя"
        clusters.append(1 if r_1 < r_2 else 2)
        
        # Корректировка весов "выигравшего" нейрона
        if r_1 < r_2:
            W[0] = [w + n * (x - w) for x, w in zip(X[i], W[0])]
        else:
            W[1] = [w + n * (x - w) for x, w in zip(X[i], W[1])]
    if k == 0:
        print(clusters)
        print('Весовые значения после первого цикла обработки данных:')
        print([round(w, 5) for w in W[0]])
        print([round(w, 5) for w in W[1]])

print('')
print(clusters)
print('Весовые значения после обучения:')
print([round(w, 5) for w in W[0]])
print([round(w, 5) for w in W[1]])