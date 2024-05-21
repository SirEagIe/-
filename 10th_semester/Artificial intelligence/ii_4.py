import random
import matplotlib.pyplot as plt
import numpy as np

class Single_Layer_Perceptron():
    def __init__(self, r_threshold, w, n):
        self.r_threshold = r_threshold # пороговое значение для R
        self.w = w # веса A-R связей
        self.n = n # норма обучения
        self.errors = [] # значение ошибок


    def output(self, input):
        # return 1 if np.tanh(self.w[0] * input[0] + self.w[1] * input[1]) >= self.r_threshold else 0
        return 1 if self.w[0] * input[0] + self.w[1] * input[1] >= self.r_threshold else 0


    def training(self, training_sets, num_of_iters=10):
        for _ in range(num_of_iters):
            for training_set in training_sets:
                r_output = self.output(training_set[0])
                delta = training_set[1] - r_output
                self.w[0] += self.n * delta * training_set[0][0]
                self.w[1] += self.n * delta * training_set[0][1]
                self.errors.append(delta)


print('Логическое И:')
perceptron_AND = Single_Layer_Perceptron(
    r_threshold = 0.5,
    w = [random.random() for _ in range(2)],
    n = 0.1
)

training_sets = [([0, 0],   0),
                 ([0, 1],   0),
                 ([1, 0],   0),
                 ([1, 1],   1)]
perceptron_AND.training(training_sets, num_of_iters = 10)
print(perceptron_AND.w)
for training_set in training_sets:
    print(f'Input: {training_set[0]}, Output: {training_set[1]}, Perceptron Output: {perceptron_AND.output(training_set[0])}')

plt.plot(range(num_iterations:=10*4), perceptron_AND.errors)
plt.show()

################################################################################################################################

print('Логическое ИЛИ:')
perceptron_OR = Single_Layer_Perceptron(
    r_threshold = 0.5,
    w = [random.random() for _ in range(2)],
    n = 0.1
)

training_sets = [([0, 0],   0),
                 ([0, 1],   1),
                 ([1, 0],   1),
                 ([1, 1],   1)]
perceptron_OR.training(training_sets, num_of_iters = 10)
print(perceptron_OR.w)
for training_set in training_sets:
    print(f'Input: {training_set[0]}, Output: {training_set[1]}, Perceptron Output: {perceptron_OR.output(training_set[0])}')

plt.plot(range(num_iterations:=10*4), perceptron_OR.errors)
plt.show()

################################################################################################################################

class Single_Layer_Perceptron():
    def __init__(self, w, n):
        self.w = w # веса A-R связей
        self.n = n # норма обучения
        self.errors = [] # значение ошибок


    def output(self, input):
        return self.w[0] * input + self.w[1]


    def training(self, training_sets, num_of_iters=10):
        for _ in range(num_of_iters):
            for training_set in training_sets:
                r_output = self.output(training_set[0])
                delta = training_set[1] - r_output
                self.w[0] += self.n * delta * training_set[0]
                self.w[1] += self.n * delta * training_set[0]
                self.errors.append(delta)
        

print('Линейная функция:')
perceptron = Single_Layer_Perceptron(
    w = [random.random() for _ in range(2)],
    n = 0.1
)

training_sets = [(-3,   5),
                 (-2,   3),
                 (-1,   1),
                 ( 0,  -1),
                 ( 1,  -3),
                 ( 2,  -5),
                 ( 3,  -7)]
perceptron.training(training_sets, num_of_iters = 1000)
print(perceptron.w)
for training_set in training_sets:
    print(f'Input: {training_set[0]}, Output: {training_set[1]}, Perceptron Output: {perceptron.output(training_set[0])}')
