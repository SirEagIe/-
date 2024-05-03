import random, math
import matplotlib.pyplot as plt

'''
# проверка связности двух узлов
def has_path(graph, start, end, visited):
    if start == end:
        return True
    visited[start] = True
    for neighbor in graph[start]:
        if not visited[neighbor]:
            if has_path(graph, neighbor, end, visited):
                return True
    return False
    
# проверка связности каждого узла с каждым
def full_connectivity(points, connections):
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

# случайная инициализация связей
def init_random_connections(points):
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

# удаление одной случайной связи и добавление случайной новой при условии сохранения связности
def iter_random_connections(points, connections):
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
'''

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
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            connections.append((points[i], points[j]))
    random.shuffle(connections)
    for i in connections:
        tmp_connections = connections.copy()
        tmp_connections.remove(i)
        if check_connectivity(points, tmp_connections):
            connections = tmp_connections
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
    i = random.randint(0, len(code1))
    return code1[:9] + code2[9:], code2[:9] + code1[9:]
    #return code3, code4

'''
def code_full_connectivity(code, points):
    connections = connections_decoding(points, code)
    points_in_connections = [i[0] for i in connections] + [i[1] for i in connections]
    return points == list(set(points_in_connections))
    #res = []
    #for i in range(num - 1, 0, -1):
    #    res.append(code[:i])
    #    code = code[i:]
    #print(res)
   ''' 


# инициализация параметров алгоритма
population_size = 2**7
# number_of_genes
# individual


# инициализация расположения оборудования и первая итерация соединения
num_of_routers = 30
size_of_map = 30
x = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
y = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
points = [(i, j) for i, j in zip(x, y)]

# отображение расположения оборудования
plt.figure(figsize=(15, 5))
plt.subplot(1, 4, 1)
plt.scatter(x, y)

# формирование начальной популяции
population = []
'''
s = (len(points) * len(points) - len(points)) // 2
r = num_of_routers - 1
random_code = '1' * r + '0' * (s - r)
while len(population) != population_size:
    random_code = list(random_code)
    random.shuffle(random_code)
    random_code = ''.join(random_code)
    if code_full_connectivity(random_code, points):
        print('a')
        population.append(connections_decoding(points, random_code))'''

population = [init_random_connections(points) for _ in range(population_size)]
individuals_grades = [len_of_wire(i) for i in population]
probabilities = [individuals_grade / sum(individuals_grades) for individuals_grade in individuals_grades]

#print(population)
#print(probabilities)


# отображение первого потомка
connections_1 = init_random_connections(points)
print(c1:=connections_encoding(points, connections_1))

plt.subplot(1, 5, 2)
show_conncetions(connections_1)

# отображение второго потомка
connections_2 = init_random_connections(points)
print(c2:=connections_encoding(points, connections_2))

plt.subplot(1, 5, 3)
show_conncetions(connections_2)
plt.show()
'''
# скрещивание потомка

c3, c4 = crossing(c1, c2)
print(c3)
print(c4)
connections_3, connections_4 = connections_decoding(points, c3), connections_decoding(points, c4)

plt.subplot(1, 5, 4)
show_conncetions(connections_3)

plt.subplot(1, 5, 5)
show_conncetions(connections_4)

print(full_connectivity(points, connections_3), full_connectivity(points, connections_4))

plt.show()


'''