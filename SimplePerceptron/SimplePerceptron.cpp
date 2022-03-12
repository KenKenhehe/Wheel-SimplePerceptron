// SimplePerceptron.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Perceptron.h"
#include "CSVParser.h"

int main()
{
	DataPreprocessing::CSVParser data_parser("data.csv");
	auto data = data_parser.GetParsedResult();

	Perceptron p(2);

	for (int i = 1; i < data.size(); ++i)
	{
		std::vector<float> input;
		input.emplace_back(std::atof(data[i][0].c_str()));
		input.emplace_back(std::atof(data[i][1].c_str()));

		int label = std::atoi(data[i][2].c_str());
		p.train(input, label);
	}

	std::vector<std::vector<float>> all_data_to_predict;
	all_data_to_predict.emplace_back(std::vector<float>{ 6, 2 });
	all_data_to_predict.emplace_back(std::vector<float>{ 2, 2 });
	all_data_to_predict.emplace_back(std::vector<float>{ 3, 2 });
	all_data_to_predict.emplace_back(std::vector<float>{ 5, 6 });
	all_data_to_predict.emplace_back(std::vector<float>{ 7, 6 });
	all_data_to_predict.emplace_back(std::vector<float>{ 2, 8 });
	all_data_to_predict.emplace_back(std::vector<float>{ 1, 1 });
	all_data_to_predict.emplace_back(std::vector<float>{ 7, 2 });
	all_data_to_predict.emplace_back(std::vector<float>{ 5, 2 });
	all_data_to_predict.emplace_back(std::vector<float>{ 2, 2 });
	all_data_to_predict.emplace_back(std::vector<float>{ 5, 6 });
	all_data_to_predict.emplace_back(std::vector<float>{ 8, 6 });
	all_data_to_predict.emplace_back(std::vector<float>{ 2, 4 });
	all_data_to_predict.emplace_back(std::vector<float>{ 1, 5 });
	
	for (int i = 0; i < all_data_to_predict.size(); ++i)
	{
		std::cout << "prediction: " << p.predict(all_data_to_predict[i]) << std::endl;
	}
}
