// SimplePerceptron.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Perceptron.h"
#include "CSVParser.h"

int main()
{
	DataPreprocessing::CSVParser data_parser("data.csv");
	auto data = data_parser.GetParsedResult();

	std::vector<float> inputs{ 2, 14, 12, 9 };
	Perceptron p(4);
}
