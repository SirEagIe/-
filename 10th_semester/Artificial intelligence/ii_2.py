import random, math
import matplotlib.pyplot as plt


# метрика, длина всех проводов
def len_of_wires(connections):
    tmp_connections = []
    for conn in connections:
        if [conn[0], conn[1]] not in tmp_connections and \
           [conn[1], conn[0]] not in tmp_connections:
            tmp_connections.append(conn)
    connections = tmp_connections.copy()
    len_ = 0
    for i in connections:
        len_ += ((i[1][0] - i[0][0])**2 + (i[1][1] - i[0][1])**2) ** 0.5
    return len_

# отобразить график
def show_conncetions(connections):
    plt.scatter(x, y)
    for i in connections:
        plt.plot([i[0][0], i[1][0]], [i[0][1], i[1][1]])

# длина маршрута
def len_of_wire(point_1, point_2):
    return ((point_2[0] - point_1[0])**2 + (point_2[1] - point_1[1])**2) ** 0.5

# случайный выбор пути
def select_way(probabilities):
    rand = random.random()
    s = 0
    for point, probability in probabilities:
        s += probability
        if rand <= s:
            return point


alpha = 1
betta = 3
Q = 0.1
p = 0.5
num_of_iters = 1000

# инициализация расположения оборудования и первая итерация соединения
num_of_routers = 15
size_of_map = 15
x = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
y = [random.randint(1, size_of_map) for _ in range(num_of_routers)]
points = [(i, j) for i, j in zip(x, y)]
points = list(set(points))


# отображение расположения оборудования
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.scatter(x, y)


# инициализация феромонов для каждого возможного ребра
T = {}
for point in points:
    T[point] = {}
    tmp_points = points.copy()
    tmp_points.remove(point)
    for tmp_point in tmp_points:
        T[point][tmp_point] = 1


best_connections = []

# цикл алгоритма
for i in range(num_of_iters):
    print('Оставшееся количество итераций:', str(num_of_iters - i).rjust(6), end='\b'*50, flush=True)
    current_position = points[random.randint(0, len(points) - 1)]
    connections = []

    unused_points = points.copy()
    unused_points.remove(current_position)

    while unused_points:
        probabilities = []

        available_positions = points.copy()
        available_positions.remove(current_position)
        #available_positions = unused_points.copy()

        # желание муравья пойти в каждую точку
        desires = []
        for available_position in available_positions:
            t = T[current_position][available_position]
            n = 1 / len_of_wire(current_position, available_position)
            desires.append(t ** alpha + n ** betta)
        
        # вертоятности перехода муравья в каждую точку
        for i in range(len(available_positions)):
            probability = desires[i] / sum(desires)
            probabilities.append((available_positions[i], probability))
        
        # выбор точки для перехода
        new_position = select_way(probabilities)
        if [current_position, new_position] not in connections:
            connections.append([current_position, new_position])
        
        if new_position in unused_points:
            unused_points.remove(new_position)
        current_position = new_position
        
        
    T_new = T.copy()
    
    # локальное обновление феромона
    for connection in connections:
        T_new[connection[0]][connection[1]] += Q / len_of_wire(connection[0], connection[1])
        

    # глобальное обновление феромона
    for t1 in T.keys():
        for t2 in T[t1]:
            T_new[t1][t2] = (1 - p) * T_new[t1][t2]

    T = T_new.copy()
    
    # выбор лучшего решения
    if best_connections == [] or len_of_wires(connections) < len_of_wires(best_connections):
        best_connections = connections.copy()

# отображение результата работы алгоритма
plt.subplot(1, 2, 2)
show_conncetions(best_connections)
plt.show()