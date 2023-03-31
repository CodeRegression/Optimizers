//--------------------------------------------------
// The base problem that we are working with
//
// @author: Wild Boar
//
// @date: 2023-03-31
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

namespace NVL_App
{
	class ProblemBase
	{
	private:
		vector<double> _arguments;

	public:
		ProblemBase(vector<double>& arguments) : _arguments(arguments) {}

		virtual int GetTestCount() = 0;
		virtual void Evaluate(vector<double>& inputs, vector<double>& errors) = 0;

		inline vector<double>& GetArguments() { return _arguments; }
	};
}
