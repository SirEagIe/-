# 1. Написать функцию, проверки числа на простоту (тест Ферма)
import random

def is_prime(num, num_of_tests):
    if num == 1:
        return False
    for i in range(num_of_tests):
        if random.randint(1, num - 1)**(num - 1)%num != 1:
            return False
    return True
    
x = int(input('Введите натуральное число: '))
if x < 1:
    print(x, '- не натуральное число')
elif is_prime(x, 50):
    print(x, '- простое число')
else:
    print(x, '- составное число')
    
# 2. Написать функцию, заполняющую список рандомными числами (от 0 до 100)
import random

def random_list(lenght):
    list = []
    for i in range(0, lenght):
        list.append(random.randint(0, 100))
    return list

lenght = int(input('Введите длину списка: '))
list = random_list(lenght)
print(list)

# 3. Написать функцию, выводящую числа Фибоначчи
def fibonacci_number(lenght):
    number_1 = 0
    number_2 = 1
    number_3 = number_1 + number_2
    for i in range(0, lenght):
        print(number_1, end=' ')
        number_1 = number_2
        number_2 = number_3
        number_3 = number_1 + number_2

lenght = int(input('Количество чисел Фибоначчи: '))
fibonacci_number(lenght)

# 4. Сортировка словаря по убыванию\возрастаниюimport random
def dict_ascending_sort(dict):
    dict_list = list(dict.items())
    for i in range(len(dict_list) - 1):
        for j in range(len(dict_list) - 1 - i):
            if dict_list[j][1] > dict_list[j+1][1]:
                dict_list[j], dict_list[j+1] = dict_list[j+1], dict_list[j]
    dict = {}
    for i in range(len(dict_list)):
        dict[dict_list[i][0]] = dict_list[i][1]
    return dict

def dict_descending_sort(dict):
    dict_list = list(dict.items())
    for i in range(len(dict_list) - 1):
        for j in range(len(dict_list) - 1 - i):
            if dict_list[j][1] < dict_list[j+1][1]:
                dict_list[j], dict_list[j+1] = dict_list[j+1], dict_list[j]
    dict = {}
    for i in range(len(dict_list)):
        dict[dict_list[i][0]] = dict_list[i][1]
    return dict

dict = {'a': 67, 'b': 75, 'c': 40, 'd': 41, 'e': 88, 'f': 3, 'g': 81, 'h': 45, 'i': 29, 'j': 0}
dict_1 = dict_ascending_sort(dict)
dict_2 = dict_descending_sort(dict)
print('Словарь:', dict)
print('Отсортированный словарь по возрастанию: ', dict_1)
print('Отсортированный словарь по убыванию: ', dict_2)
