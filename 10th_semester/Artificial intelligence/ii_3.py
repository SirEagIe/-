import random, math
import matplotlib.pyplot as plt


def check_connectivity(points, connections):
    graph = {}
    for p1, p2 in connections:
        if p1 not in graph:
            graph[p1] = []
        graph[p1].append(p2)
        if p2 not in graph:
            graph[p2] = []
        graph[p2].append(p1)
    visited = set()
    def dfs(node):
        visited.add(node)
        if node in graph:
            for neighbor in graph[node]:
                if neighbor not in visited:
                    dfs(neighbor)
    dfs(points[0])
    return len(visited) == len(points)


# случайная инициализация связей
def init_random_connections(points):
    connections = []
    components = []
    unused_points = points.copy()
    while unused_points:
        f_point = random.choice(unused_points)
        unused_points.remove(f_point)
        s_point = random.choice(unused_points)
        unused_points.remove(s_point)
        connections.append((f_point, s_point))
        components.append([f_point, s_point])
    random.shuffle(components)
    for _ in range(len(components) - 1):
        f_point = random.choice(components[0])
        s_point = random.choice(components[1])
        connections.append((f_point, s_point))
        components[0] = components[0] + components[1]
        del components[1]
    return connections


# отобразить график
def show_conncetions(connections):
    plt.scatter(x, y)
    for i in connections:
        plt.plot([i[0][0], i[1][0]], [i[0][1], i[1][1]])


# метрика, длина всех проводов
def len_of_wire(connections):
    len_ = 0
    for i in connections:
        len_ += ((i[1][0] - i[0][0])**2 + (i[1][1] - i[0][1])**2) ** 0.5
    return len_


def connections_encoding(points, connections):
    code = ''
    all_possible_connections = []
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            all_possible_connections.append((points[i], points[j]))
    for connection in all_possible_connections:
        if connection in connections or connection[::-1] in connections:
            code += '1'
        else:
            code += '0'
    return code


def connections_decoding(points, code):
    connections = []
    all_possible_connections = []
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            all_possible_connections.append((points[i], points[j]))
    for i in range(len(code)):
        if code[i] == '1':
            connections.append(all_possible_connections[i])
    return connections


# на выходе не всегда решение, мб накрутить проверок
def crossing(code1, code2):
    #code3, code4 = '', ''
    #while code3.count('1') != code1.count('1') and code4.count('1') != code2.count('1'):1
    # for _ in range(100):
    i = random.randint(0, len(code1))
    code3, code4 = code1[:i] + code2[i:], code2[:i] + code1[i:]
    if check_connectivity(points, connections_decoding(points, code3)) and check_connectivity(points, connections_decoding(points, code4)):
        return code3, code4
    return code1, code2
    #     if check_connectivity(points, connections_decoding(points, code3)) and check_connectivity(points, connections_decoding(points, code4)):
    #         break
    #     else:
    #         code3, code4 = None, None
    # if code3 and code4:
    #     return code3, code4
    # else:
    #     return code1, code2
    

# инициализация параметров алгоритма
population_size = 2**10
# number_of_genes
# individual
probability_of_crossing = 0.5

# инициализация расположения оборудования и первая итерация соединения
num_of_routers = 16
size_of_map = 30
x = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
y = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
points = [(i, j) for i, j in zip(x, y)]
while len(list(set(points))) != num_of_routers:
    points = list(set(points))
    points.append((random.randint(1, size_of_map), random.randint(1, size_of_map)))

# отображение расположения оборудования
plt.figure(figsize=(15, 5))
plt.subplot(1, 3, 1)
plt.scatter(x, y)

# формирование начальной популяции
population = [init_random_connections(points) for _ in range(population_size)]
result_pre = sorted(population, key=lambda x: len_of_wire(x))[0]

# while len(population) > 2:
for _i in range(100):
    print(_i)
    # оценка каждой особи популяции
    population_grades = [len_of_wire(i) for i in population]

    # селекция
    selected_population = []
    for i in range(0, len(population), 2):
        if population_grades[i] < population_grades[i + 1]:
            selected_population.append(population[i])
        else:
            selected_population.append(population[i + 1])

    # скрещивание
    random.shuffle(selected_population)
    crossed_population = []
    for i in range(0, len(selected_population), 2):
        if random.random() < probability_of_crossing:
            code_1 = connections_encoding(points, selected_population[i])
            code_2 = connections_encoding(points, selected_population[i + 1])
            code_1, code_2 = crossing(code_1, code_2)
            crossed_population.append(connections_decoding(points, code_1))
            crossed_population.append(connections_decoding(points, code_2))
        else:
            crossed_population.append(selected_population[i])
            crossed_population.append(selected_population[i + 1])

    population = crossed_population*2
    random.shuffle(population)

result = sorted(population, key=lambda x: len_of_wire(x))[0]

# отображение первого потомка
plt.subplot(1, 3, 2)
show_conncetions(result_pre)
plt.subplot(1, 3, 3)
show_conncetions(result)
print(len_of_wire(result_pre), len_of_wire(result))
plt.show()