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

	//Train the perceptron with input data and a target label, this step will tweak the weights
	//of the perceptron
	void train(const std::vector<float>& inputs, int target);

	//Returns -1 if num is less than 0, other wise return 1 
	int sign(float num);

	//Given a set of inputs, produce a prediction
	int predict(const std::vector<float>& inputs);
private:
	int guess(const std::vector<float>& inputs);
	std::vector<float> m_weights;
	std::vector<float> m_inputs;
	float m_learning_rate = 0.4f;

};

#endif // !PERCEPTRON_H



