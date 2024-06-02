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
                'A1': 1,
                'A2': 1,
                'A3': 1,
            },
            'S2': {
                'A1': 1,
                'A2': 1,
                'A3': 1,
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
        return self.activation(x) * (1 - self.activation(x))


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
        E = E_m + 1
        while E > E_m:
            E = 0
            for training_set in training_sets:
                r_output = self.output(training_set[0])
                error = training_set[1] - r_output
                E += 1/2 * error ** 2
                input_A1 = self.w['S1']['A1'] * training_set[0][0] + self.w['S2']['A1'] * training_set[0][1]
                input_A2 = self.w['S1']['A2'] * training_set[0][0] + self.w['S2']['A2'] * training_set[0][1]
                input_A3 = self.w['S1']['A3'] * training_set[0][0] + self.w['S2']['A3'] * training_set[0][1]

                output_A1 = self.activation(input_A1 - self.b['A1'])
                output_A2 = self.activation(input_A2 - self.b['A2'])
                output_A3 = self.activation(input_A3 - self.b['A3'])

                error_A1 = error * self.derivative_activation(input_A1)
                error_A2 = error * self.derivative_activation(input_A2)
                error_A3 = error * self.derivative_activation(input_A3)

                self.w['A1']['R'] -= alpha * error_A1 * self.derivative_activation(input_A1) * output_A1
                self.w['A2']['R'] -= alpha * error_A2 * self.derivative_activation(input_A2) * output_A2
                self.w['A3']['R'] -= alpha * error_A3 * self.derivative_activation(input_A3) * output_A3

                self.b['A1'] += alpha * error_A1 * self.derivative_activation(input_A1)
                self.b['A2'] += alpha * error_A2 * self.derivative_activation(input_A2)
                self.b['A3'] += alpha * error_A3 * self.derivative_activation(input_A3)

                input_R = self.w['A1']['R'] * output_A1 + self.w['A2']['R'] * output_A2 + self.w['A3']['R'] * output_A3
                error_R = error * self.derivative_activation(input_R)
                self.b['R'] += alpha * error_R * self.derivative_activation(input_R)

                # self.errors.append(delta)
            E /= 4
            print(E)

perceptron_XOR = Perceptron()

training_sets = [([0, 0],  0),
                 ([0, 1],  1),
                 ([1, 0],  1),
                 ([1, 1],  0)]

print(perceptron_XOR.w)
print(perceptron_XOR.b)

perceptron_XOR.training(training_sets, 0.1, E_m = 0.1)

print(perceptron_XOR.w)
print(perceptron_XOR.b)

for training_set in training_sets:
    print(f'Input: {training_set[0]}, Output: {training_set[1]}, Perceptron Output: {perceptron_XOR.output(training_set[0])}')

# plt.plot(range(num_iterations:=10*4), perceptron_XOR.errors)
# plt.show()
