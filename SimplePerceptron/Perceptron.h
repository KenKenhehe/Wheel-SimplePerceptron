#pragma once
#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

class Perceptron
{
public:
	Perceptron(int input_size);

	void train(const std::vector<float>& inputs, int target);

	float sign(float num);

	int predict(const std::vector<float>& inputs);
private:
	int guess(const std::vector<float>& inputs);
	std::vector<float> m_weights;
	std::vector<float> m_inputs;
	float m_learning_rate = 0.4f;

};

#endif // !PERCEPTRON_H



