import random
import matplotlib.pyplot as plt
import math

class Perceptron():
    def __init__(self):
        self.b = {
            'A1': 0,
            'A2': 0,
            'A3': 0,
            'R': 0,
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

    def activation(self, x):
        # sigmoid
        return 1 / (1 + math.exp(-x))

    def derivative_activation(self, x):
        # sigmoid derivative
        act = self.activation(x)
        return act * (1 - act)

    def output(self, input):
        input_A1 = self.w['S1']['A1'] * input[0] + self.w['S2']['A1'] * input[1]
        output_A1 = self.activation(input_A1 - self.b['A1'])

        input_A2 = self.w['S1']['A2'] * input[0] + self.w['S2']['A2'] * input[1]
        output_A2 = self.activation(input_A2 - self.b['A2'])

        input_A3 = self.w['S1']['A3'] * input[0] + self.w['S2']['A3'] * input[1]
        output_A3 = self.activation(input_A3 - self.b['A3'])

        input_R = self.w['A1']['R'] * output_A1 + self.w['A2']['R'] * output_A2 + self.w['A3']['R'] * output_A3
        output_R = self.activation(input_R - self.b['R'])

        return output_R

    def training(self, training_sets, alpha, E_m):
        for _ in range(50000):
            total_error = 0
            for training_set in training_sets:
                input = training_set[0]
                expected_output = training_set[1]
                r_output = self.output(input)
                
                error = expected_output - r_output
                total_error += error ** 2

                # Обратное распространение ошибки
                d_r_output = error * self.derivative_activation(r_output)

                input_A1 = self.w['S1']['A1'] * input[0] + self.w['S2']['A1'] * input[1]
                output_A1 = self.activation(input_A1 - self.b['A1'])

                input_A2 = self.w['S1']['A2'] * input[0] + self.w['S2']['A2'] * input[1]
                output_A2 = self.activation(input_A2 - self.b['A2'])

                input_A3 = self.w['S1']['A3'] * input[0] + self.w['S2']['A3'] * input[1]
                output_A3 = self.activation(input_A3 - self.b['A3'])

                error_A1 = d_r_output * self.w['A1']['R']
                error_A2 = d_r_output * self.w['A2']['R']
                error_A3 = d_r_output * self.w['A3']['R']
                
                d_A1_output = error_A1 * self.derivative_activation(input_A1 - self.b['A1'])
                d_A2_output = error_A2 * self.derivative_activation(input_A2 - self.b['A2'])
                d_A3_output = error_A3 * self.derivative_activation(input_A3 - self.b['A3'])

                # Обновление весов
                self.w['A1']['R'] += alpha * output_A1 * d_r_output
                self.w['A2']['R'] += alpha * output_A2 * d_r_output
                self.w['A3']['R'] += alpha * output_A3 * d_r_output

                self.w['S1']['A1'] += alpha * input[0] * d_A1_output
                self.w['S2']['A1'] += alpha * input[1] * d_A1_output
                self.w['S1']['A2'] += alpha * input[0] * d_A2_output
                self.w['S2']['A2'] += alpha * input[1] * d_A2_output
                self.w['S1']['A3'] += alpha * input[0] * d_A3_output
                self.w['S2']['A3'] += alpha * input[1] * d_A3_output

            if total_error < E_m:
                break

perceptron_XOR = Perceptron()

training_sets = [([0, 0],  0),
                 ([0, 1],  1),
                 ([1, 0],  1),
                 ([1, 1],  0)]

print("Initial weights and biases:")
print(perceptron_XOR.w)
print(perceptron_XOR.b)

perceptron_XOR.training(training_sets, 0.1, E_m = 0.01)

print("Trained weights and biases:")
print(perceptron_XOR.w)
print(perceptron_XOR.b)

for training_set in training_sets:
    print(f'Input: {training_set[0]}, Expected Output: {training_set[1]}, Perceptron Output: {perceptron_XOR.output(training_set[0])}')
