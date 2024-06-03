import random
import matplotlib.pyplot as plt
import math


class Perceptron():
    def __init__(self):
        self.b = {
            'A1': random.random(),
            'A2': random.random(),
            'A3': random.random(),
            'R': random.random(),
        }
        self.w = {
            'S1': {
                'A1': random.random(),
                'A2': random.random(),
                'A3': random.random(),
            },
            'S2': {
                'A1': random.random(),
                'A2': random.random(),
                'A3': random.random(),
            },
            'A1': {
                'R': random.random(),
            },
            'A2': {
                'R': random.random(),
            },
            'A3': {
                'R': random.random(),
            },
        }
        self.iterations = 0
        self.errors = []


    def activation(self, x):
        # sigmoid
        return 1 / (1 + math.exp(-x))

    
    def derivative_activation(self, x):
        # sigmoid derivative
        return self.activation(x) * (1 - self.activation(x))


    def output(self, input):
        input_A1 = self.w['S1']['A1'] * input[0] + self.w['S2']['A1'] * input[1]
        output_A1 = self.activation(input_A1 + self.b['A1'])

        input_A2 = self.w['S1']['A2'] * input[0] + self.w['S2']['A2'] * input[1]
        output_A2 = self.activation(input_A2 + self.b['A2'])

        input_A3 = self.w['S1']['A3'] * input[0] + self.w['S2']['A3'] * input[1]
        output_A3 = self.activation(input_A3 + self.b['A3'])

        input_R = self.w['A1']['R'] * output_A1 + self.w['A2']['R'] * output_A2 + self.w['A3']['R'] * output_A3
        output_R = self.activation(input_R + self.b['R'])

        return output_R


    def training(self, training_sets, alpha, E_m):
        self.iterations = 0
        self.errors = []
        while True:
            E = 0
            for training_set in training_sets:
                input = training_set[0]
                expected_output = training_set[1]

                # Прямое распространение
                output_R = self.output(training_set[0])
                
                # Вычисление ошибки
                net_error = expected_output - output_R
                E += net_error ** 2
                
                # Входные и выходные сигналы нейронов A1, A2, A3, R
                input_A1 = self.w['S1']['A1'] * input[0] + self.w['S2']['A1'] * input[1]
                output_A1 = self.activation(input_A1 + self.b['A1'])
                input_A2 = self.w['S1']['A2'] * input[0] + self.w['S2']['A2'] * input[1]
                output_A2 = self.activation(input_A2 + self.b['A2'])
                input_A3 = self.w['S1']['A3'] * input[0] + self.w['S2']['A3'] * input[1]
                output_A3 = self.activation(input_A3 + self.b['A3'])
                input_R = self.w['A1']['R'] * output_A1 + self.w['A2']['R'] * output_A2 + self.w['A3']['R'] * output_A3

                # Подсчёт ошибок каждого нейрона
                error_R = net_error
                error_A1 = error_R * self.derivative_activation(input_R + self.b['R']) * self.w['A1']['R']
                error_A2 = error_R * self.derivative_activation(input_R + self.b['R']) * self.w['A2']['R']
                error_A3 = error_R * self.derivative_activation(input_R + self.b['R']) * self.w['A3']['R']
                
                # Обновление весов A - R и смещения нейрона R
                self.w['A1']['R'] += alpha * error_R * self.derivative_activation(input_R + self.b['R']) * output_A1
                self.w['A2']['R'] += alpha * error_R * self.derivative_activation(input_R + self.b['R']) * output_A2
                self.w['A3']['R'] += alpha * error_R * self.derivative_activation(input_R + self.b['R']) * output_A3
                self.b['R'] += alpha * error_R * self.derivative_activation(input_R + self.b['R'])

                # Обновление весов S - A и смещения нейронов A
                self.w['S1']['A1'] += alpha * error_A1 * self.derivative_activation(input_A1 + self.b['A1']) * input[0]
                self.w['S2']['A1'] += alpha * error_A1 * self.derivative_activation(input_A1 + self.b['A1']) * input[1]
                self.w['S1']['A2'] += alpha * error_A2 * self.derivative_activation(input_A2 + self.b['A2']) * input[0]
                self.w['S2']['A2'] += alpha * error_A2 * self.derivative_activation(input_A2 + self.b['A2']) * input[1]
                self.w['S1']['A3'] += alpha * error_A3 * self.derivative_activation(input_A3 + self.b['A3']) * input[0]
                self.w['S2']['A3'] += alpha * error_A3 * self.derivative_activation(input_A3 + self.b['A3']) * input[1]
                self.b['A1'] += alpha * error_A1 * self.derivative_activation(input_A1 + self.b['A1'])
                self.b['A2'] += alpha * error_A2 * self.derivative_activation(input_A1 + self.b['A2'])
                self.b['A3'] += alpha * error_A3 * self.derivative_activation(input_A2 + self.b['A3'])

            self.iterations += 1
            self.errors.append(E)
            if E < E_m:
                break


perceptron_XOR = Perceptron()

training_sets = [([0, 0],  0),
                 ([0, 1],  1),
                 ([1, 0],  1),
                 ([1, 1],  0)]

perceptron_XOR.training(training_sets, 0.1, E_m = 0.01)

print('Weights:')
print('S1 - A1:', perceptron_XOR.w['S1']['A1'])
print('S1 - A2:', perceptron_XOR.w['S1']['A2'])
print('S1 - A3:', perceptron_XOR.w['S1']['A3'])
print('S2 - A1:', perceptron_XOR.w['S2']['A1'])
print('S2 - A2:', perceptron_XOR.w['S2']['A2'])
print('S2 - A3:', perceptron_XOR.w['S2']['A3'])
print('A1 - R:', perceptron_XOR.w['A1']['R'])
print('A2 - R:', perceptron_XOR.w['A2']['R'])
print('A3 - R:', perceptron_XOR.w['A3']['R'])

print('Bias:')
print('A1:', perceptron_XOR.b['A1'])
print('A2:', perceptron_XOR.b['A2'])
print('A3:', perceptron_XOR.b['A3'])
print('R:', perceptron_XOR.b['R'])

for training_set in training_sets:
    print(f'Input: {training_set[0]}, Output: {training_set[1]}, Perceptron Output: {perceptron_XOR.output(training_set[0])}')

plt.plot(list(range(perceptron_XOR.iterations)), perceptron_XOR.errors)
plt.show()
