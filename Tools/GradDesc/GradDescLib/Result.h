//--------------------------------------------------
// The result of the refinement
//
// @author: Wild Boar
//
// @date: 2023-04-01
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

namespace NVL_App
{
	class Result
	{
	private:
		double _error;
		vector<double> _solution;
	public:
		Result(double error, vector<double>& solution) :
			_error(error), _solution(solution) {}

		inline double& GetError() { return _error; }
		inline vector<double>& GetSolution() { return _solution; }
	};
}
