alphabet = 'абвгдежзийклмнопрстуфхцчшщъыьэюя'
frequency_letters = 'оеаинтсрвлкмдпуяыьгзбчйхжшюцщэфъ'


# Поменять в строке n и n+1 символы (ф-ия для сортировки)
def switch_sym_with_next(string, n):
    string = ''.join([string[:n], string[n + 1], string[n], string[n + 2:len(string)]])
    return string


# Получение ключа из последовательности, упорядоченной по частоте встречаемости букв в шифротексте
def get_key(frequency_letters_in_text_):
    frequency_letters_ = 'оеаинтсрвлкмдпуяыьгзбчйхжшюцщэфъ'
    for i in range(0, len(alphabet)):
        for j in range(0, len(alphabet) - 1):
            if frequency_letters_[j] > frequency_letters_[j + 1]:
                frequency_letters_ = switch_sym_with_next(frequency_letters_, j)
                frequency_letters_in_text_ = switch_sym_with_next(frequency_letters_in_text_, j)
    return frequency_letters_in_text_


# Дешифровка текста, зашифрованного с помощью шифра замены
def decrypt_substitution_cipher(ciphertext_, key_):
    plaintext_ = ''
    for i in range(0, len(ciphertext_)):
        if alphabet.find(ciphertext_[i]) != -1:
            plaintext_ += alphabet[key_.find(ciphertext_[i])]
        elif alphabet.upper().find(ciphertext_[i]) != -1:
            plaintext_ += alphabet[key_.upper().find(ciphertext_[i])].upper()
        else:
            plaintext_ += ciphertext_[i]
    return plaintext_


# Считывание текста из файла
try:
    file_ciphertext = open('ciphertext.txt', 'r', encoding="utf-8")
except IOError as e:
    print('Не удалось открыть файл!')
    exit()
ciphertext = ''
while True:
    ch = file_ciphertext.read(1)
    if ch == '':
        break
    ciphertext += ch
file_ciphertext.close()
# Подсчёт встречаемости букв в заданном тексте
frequency_letters_in_text = alphabet
amount = [0] * 33
for i in range(0, len(ciphertext)):
    for j in range(0, len(alphabet)):
        if ciphertext[i] == alphabet[j] or ciphertext[i] == alphabet[j].upper():
            amount[j] += 1
# Сортировка
for i in range(0, len(alphabet)):
    for j in range(0, len(alphabet) - 1):
        if amount[j] < amount[j + 1]:
            amount[j], amount[j + 1] = amount[j + 1], amount[j]
            frequency_letters_in_text = switch_sym_with_next(frequency_letters_in_text, j)
# Получение гипотезы о возможном ключе и исползование его для дешифровки
key = get_key(frequency_letters_in_text)
plaintext = decrypt_substitution_cipher(ciphertext, key)
print(plaintext)
print("Ключ:")
print(alphabet)
print(key)
# Дополнительные замены букв в тексте
while True:
    print('\nДополнительные замены букв в тексте ("exit" для выхода)')
    print("Заменить: ")
    first_char = input().lower()
    if first_char == 'exit':
        file_plaintext = open('plaintext.txt', 'w', encoding='utf-8')
        file_plaintext.write(plaintext)
        file_plaintext.close()
        exit()
    print("И: ")
    second_char = input().lower()
    if len(first_char) != 1 or len(second_char) != 1 or alphabet.find(first_char) == -1 or alphabet.find(
            second_char) == -1:
        print("Данные введены неверно\n")
        input()
    else:
        first_char = key[alphabet.find(first_char)]
        second_char = key[alphabet.find(second_char)]
        key = key.replace(first_char, '*').replace(second_char, first_char).replace('*', second_char)
        plaintext = decrypt_substitution_cipher(ciphertext, key)
    print(plaintext)
    print("Ключ:")
    print(alphabet)
    print(key)
