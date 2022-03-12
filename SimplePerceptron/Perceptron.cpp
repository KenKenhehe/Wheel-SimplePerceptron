#include "Perceptron.h"

Perceptron::Perceptron(int input_size)
{
	for (int i = 0; i < input_size; ++i)
	{
		m_weights.emplace_back((float(rand()) / float((RAND_MAX)) * 2 - 1));
		std::cout << m_weights[i] << std::endl;
	}
}

int Perceptron::guess(const std::vector<float>& inputs)
{
	float sum = 0.0f;

	for (int i = 0; i < m_weights.size(); ++i)
	{
		sum += inputs[i] * m_weights[i];
	}

	return sign(sum);
}

void Perceptron::train(const std::vector<float>& inputs, int target)
{
	int guess_value = guess(inputs);
	int error = target - guess_value;

	for (int i = 0; i < m_weights.size(); ++i)
	{
		m_weights[i] += error * inputs[i] * m_learning_rate;
	}
}

float Perceptron::sign(float num)
{
	return num > 0 ? 1 : -1;
}

int Perceptron::predict(const std::vector<float>& inputs)
{
	int prediction = guess(inputs);
	return prediction;
}
