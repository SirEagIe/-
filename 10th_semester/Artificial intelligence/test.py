import random

# Функция активации (сигмоида)
def sigmoid(x):
    return 1 / (1 + pow(2.71828, -x))

# Производная функции активации
def sigmoid_derivative(x):
    return x * (1 - x)

# Инициализация весов и смещений
input_layer_neurons = 2
hidden_layer_neurons = 2
output_layer_neurons = 1

hidden_weights = [[random.uniform(-1, 1) for _ in range(input_layer_neurons)] for _ in range(hidden_layer_neurons)]
output_weights = [random.uniform(-1, 1) for _ in range(hidden_layer_neurons)]

hidden_biases = [random.uniform(-1, 1) for _ in range(hidden_layer_neurons)]
output_bias = random.uniform(-1, 1)

# Входные данные XOR
X = [[0, 0], [0, 1], [1, 0], [1, 1]]
y = [0, 1, 1, 0]

# Обучение нейронной сети
epochs = 10000
learning_rate = 0.1

for epoch in range(epochs):
    for i in range(len(X)):
        # Прямое распространение
        hidden_layer_input = [sum([X[i][j] * hidden_weights[k][j] for j in range(input_layer_neurons)]) + hidden_biases[k] for k in range(hidden_layer_neurons)]

        hidden_layer_output = [sigmoid(val) for val in hidden_layer_input]

        output_layer_input = sum([hidden_layer_output[k] * output_weights[k] for k in range(hidden_layer_neurons) + output_bias])
        output = sigmoid(output_layer_input)

        # Обратное распространение
        error = y[i] - output
        output_delta = error * sigmoid_derivative(output)

        hidden_errors = [output_delta * output_weights[k] for k in range(hidden_layer_neurons)]
        hidden_deltas = [hidden_errors[k] * sigmoid_derivative(hidden_layer_output[k]) for k in range(hidden_layer_neurons)]

        # Обновление весов и смещений
        for k in range(hidden_layer_neurons):
            output_weights[k] += hidden_layer_output[k] * output_delta * learning_rate
            hidden_biases[k] += hidden_deltas[k] * learning_rate
            for j in range(input_layer_neurons):
                hidden_weights[k][j] += X[i][j] * hidden_deltas[k] * learning_rate

        output_bias += output_delta * learning_rate

# Тестирование нейронной сети
print("Результаты после обучения:")
for i in range(len(X)):
    hidden_layer_input = [sum([X[i][j] * hidden_weights[k][j] for j in range(input_layer_neurons)]) + hidden_biases[k] for k in range(hidden_layer_neurons)]

    hidden_layer_output = [sigmoid(val) for val in hidden_layer_input]

    output_layer_input = sum([hidden_layer_output[k] * output_weights[k] for k in range(hidden_layer_neurons)] + output_bias)
    output = sigmoid(output_layer_input)

    print(f"Входные значения: {X[i]}, Предсказание: {output}")
