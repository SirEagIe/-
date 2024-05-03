# 1. Показать основные операции с целочисленным типом
x = 5
y = 2
print('x =', x, ', y =', y)
print('Сложение: x + y =', x + y)
print('Вычитание: x - y =', x - y)
print('Умножение: x * y =', x * y)
print('Деление: x / y =', x / y)
print('Целочисленное деление: x // y =', x // y)
print('Возведение в степень: x ** y =', x ** y)
print('Остаток от деления: x % y =', x % y)

# 2. Вычислить сумму цифр случайного четырехзначного числа
import random

num = int(random.random()*10000)
print('Случайное четырехзначное число:', num)
temp_num = num
sum_of_digits = 0
while temp_num > 0:
    sum_of_digits += temp_num % 10
    temp_num //= 10
print('Сумма цифр числа', num, '-', sum_of_digits)

# 3. Показать побитовые операции
print('Битовый оператор & (И, AND):')
print('0 & 0 =', 0 & 0)
print('0 & 1 =', 0 & 1)
print('1 & 0 =', 1 & 0)
print('1 & 1 =', 1 & 1)
print('Битовый оператор | (ИЛИ, OR):')
print('0 | 0 =', 0 | 0)
print('0 | 1 =', 0 | 1)
print('1 | 0 =', 1 | 0)
print('1 | 1 =', 1 | 1)
print('Битовый оператор ^ (Исключающее ИЛИ, XOR):')
print('0 ^ 0 =', 0 ^ 0)
print('0 ^ 1 =', 0 ^ 1)
print('1 ^ 0 =', 1 ^ 0)
print('1 ^ 1 =', 1 ^ 1)

# 4. Показать основные операции со строками
string1 = 'Hello'
string2 = 'World'
print('string1 =', string1, ', string2 =', string2)
print('Конкатенация строк (string1 + string2):', string1 + string2)
print('Дублирование (string1 * 4):', string1 * 4)
print('Длина строки (len(string1)):', len(string1))
print('Доступ по индексу:')
print('string1[0] -', string1[0])
print('string1[3] -', string1[3])
print('string1[-1] -', string1[-1])

# 5. Найти самое длинное слово в случайной строке
string = 'Cтрока для поиска самого длинного слова в ней'
words = []
lenghts = []
word = ''
lenght = 0
for i in range(0, len(string)):
    if string[i] != ' ':
        word += string[i]
        lenght += 1
    if string[i] == ' ' or i == len(string) - 1:
        words.append(word)
        lenghts.append(lenght)
        word = ''
        lenght = 0
print('Самое длинное слово в строке \'', string, '\': ', words[lenghts.index(max(lenghts))], sep='')

# 6. Создать список из 5 элементов, произвести добавление элемента в конец списка, добавление по индексу,
# удаление по индексу, по значению, воспроизвести функцию pop и показать сохраненную переменную
list = [1, 2, 3, 5, 6]
print('Исходный список', list)
list.append(7)
print('Добавление в конец списка (list.append(7)):', list)
list.insert(3, 4)
print('Добавление по индексу (list.insert(3, 4)):', list)
list.pop(0)
print('Удаление по индексу (list.pop(0)):', list)
list.remove(5)
print('Удаление по значению (list.remove(5)):', list)
element = list.pop()
print('Воспроизвдение функции pop (list.pop()):', list, ', сохранённая переменная:', element)

# 7. Найти значение списка, которое встречается чаще всего
list = [1, 5, 3, 6, 7, 5, 6, 3, 1, 4, 5, 6, 2, 6]
list_without_repeat = []
num_of_elements = []
for elem in list:
    if elem not in list_without_repeat:
        list_without_repeat.append(elem)
for elem in list_without_repeat:
    num_of_elements.append(list.count(elem))
print('Значение в списке ', list, ', которое встречается чаще всего - ',
    list_without_repeat[num_of_elements.index(max(num_of_elements))], sep='')




