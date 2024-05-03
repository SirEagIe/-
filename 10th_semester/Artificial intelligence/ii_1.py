import random
import math
import matplotlib.pyplot as plt


def has_path(graph, start, end, visited):
    # проверка связности двух узлов
    if start == end:
        return True
    visited[start] = True
    for neighbor in graph[start]:
        if not visited[neighbor]:

            if has_path(graph, neighbor, end, visited):
                return True
    return False


def full_connectivity(points, connections):
    # проверка связности каждого узла с каждым
    graph = {}
    for point in points:
        graph[point] = []
    for connection in connections:
        a, b = connection
        graph[a].append(b)
        graph[b].append(a)
    possible_paths = True
    for point1 in points:
        for point2 in points:
            if point1 != point2:
                visited = {point: False for point in points}
                if not has_path(graph, point1, point2, visited):
                    possible_paths = False
                    break
    return possible_paths


def init_random_connections(points):
    # случайная инициализация связей
    connections = []
    while not full_connectivity(points, connections):
        f_point_index = random.randint(0, len(points) - 1)
        s_point_index = f_point_index
        while s_point_index == f_point_index:
            s_point_index = random.randint(0, len(points) - 1)
        f_point = points[f_point_index]
        s_point = points[s_point_index]
        connections.append((f_point, s_point))
    for i in connections:
        tmp_connections = connections.copy()
        tmp_connections.remove(i)
        if full_connectivity(points, tmp_connections):
            connections = tmp_connections
    return connections


def iter_random_connections(points, connections):
    # удаление одной случайной связи и добавление случайной новой при условии сохранения связности
    i = random.randint(0, len(connections) - 1)
    point1 = connections[i][0]
    point2 = connections[i][1]
    tmp_connections = connections.copy()
    tmp_connections.remove(connections[i])
    while True:
        f_point_index = random.randint(0, len(points) - 1)
        s_point_index = f_point_index
        while s_point_index == f_point_index:
            s_point_index = random.randint(0, len(points) - 1)
        f_point = points[f_point_index]
        s_point = points[s_point_index]
        graph = {}
        for point in points:
            graph[point] = []
        for connection in tmp_connections + [(f_point, s_point)]:
            a, b = connection
            graph[a].append(b)
            graph[b].append(a)
        visited = {point: False for point in points}
        if has_path(graph, point1, point2, visited):
            tmp_connections.append((f_point, s_point))
            break
    return tmp_connections


def show_conncetions(connections):
    # отобразить график
    plt.scatter(x, y)
    for i in connections:
        plt.plot([i[0][0], i[1][0]], [i[0][1], i[1][1]])


def len_of_wire(connections):
    # метрика, длина всех проводов
    len_ = 0
    for i in connections:
        len_ += ((i[1][0] - i[0][0])**2 + (i[1][1] - i[0][1])**2) ** 0.5
    return len_


# инициализация температуры
initial_temp = 10
final_temp = 0.01
alpha = 0.001
current_temp = initial_temp

# инициализация расположения оборудования и первая итерация соединения
num_of_routers = 30
size_of_map = 30
x = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
y = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
points = [(i, j) for i, j in zip(x, y)]
current_connections = init_random_connections(points)

# отображение расположения оборудования
plt.figure(figsize=(15, 5))
plt.subplot(1, 3, 1)
plt.scatter(x, y)

# отображение первой итерации соединения
plt.subplot(1, 3, 2)
show_conncetions(current_connections)

# алгоритм имитации отжига
while current_temp > final_temp:
    print('Текущая температура:', str(
        round(current_temp, 2)).rjust(6), end='\b'*28, flush=True)
    new_connections = iter_random_connections(points, current_connections)
    delta = len_of_wire(new_connections) - len_of_wire(current_connections)
    if delta <= 0:
        current_connections = new_connections
    elif random.uniform(0, 1) <= math.exp(- delta / current_temp):
        current_connections = new_connections
    current_temp -= alpha

# отображение результата работы алгоритма
plt.subplot(1, 3, 3)
show_conncetions(current_connections)
plt.show()
