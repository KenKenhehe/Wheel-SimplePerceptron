#include "Perceptron.h"

Perceptron::Perceptron(int input_size)
{
	for (int i = 0; i < input_size; ++i)
	{
		//initialize weights with random number, number of weights should be the same number of input, 
		//since each input is asscioated with 1 weight
		float ran_num = float(rand());
		m_weights.emplace_back(ran_num / float((RAND_MAX)) * 2 - 1);
		std::cout << m_weights[i] << std::endl;
	}
}

int Perceptron::guess(const std::vector<float>& inputs)
{
	//sum all the inputs and weights to produce a guess
	float sum = 0.0f;

	for (int i = 0; i < m_weights.size(); ++i)
	{
		sum += inputs[i] * m_weights[i];
	}

	return sign(sum);
}

void Perceptron::train(const std::vector<float>& inputs, int target)
{
	//tune the weights based on the produced error
	int guess_value = guess(inputs);
	int error = target - guess_value;

	for (int i = 0; i < m_weights.size(); ++i)
	{
		m_weights[i] += error * inputs[i] * m_learning_rate;
		std::cout << "weights, " << i << " after this training: " << m_weights[i] << std::endl;
	}
}

int Perceptron::sign(float num)
{
	return num > 0 ? 1 : -1;
}

int Perceptron::predict(const std::vector<float>& inputs)
{
	int prediction = guess(inputs);
	return prediction;
}
