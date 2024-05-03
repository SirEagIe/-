alphabet = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя '
message = 'в осеннее ненастье семь погод на дворе'
p = 241
q = 307
n = p*q
phi = (p - 1) * (q - 1)

def gcd(a, b):
	while a != 0 and b != 0:
		if a > b:
			a = a % b
		else:
			b = b % a
	return a or b

key = int(input('1. Шифрование\n2. Расшифровка\n'))
if key == 1:
    e = 0
    while e == 0:
        e = int(input('Введите любое е взаимно простое с ' + str(phi) + ': '))
        if gcd(e, phi) != 1:
            print('e должно быть взаимно простым с', phi)
            e = 0
    d = 0
    for i in range(0, phi):
        if (e*i)%phi == 1:
            d = i
            break
    print('Для расшифровки: d =', d)
    ciphertext = ''
    for i in range(0, len(message)):
        ch = message[i]
        int_ch = alphabet.index(ch.lower())
        crypt_int_ch = (int_ch**e) % n
        ciphertext += str(crypt_int_ch) + ' '
    print(ciphertext)
    
if key == 2:
    ciphertext = input('Введите шифротекст\n')
    ciphertext = [int(i) for i in ciphertext.split()]
    d = int(input('Введите d: '))
    plaintext = ''
    for i in ciphertext:
        ch = (i**d)%n
        plaintext += str(alphabet[ch])
    print(plaintext)