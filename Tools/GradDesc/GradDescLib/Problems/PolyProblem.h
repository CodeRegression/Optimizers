//--------------------------------------------------
// A generic polynomal problem
//
// @author: Wild Boar
//
// @date: 2023-04-01
//--------------------------------------------------

#pragma once

#include "cmath"
#include <iostream>
using namespace std;

#include "ProblemBase.h"

namespace NVL_App
{
	class PolyProblem : public ProblemBase
	{
		private:
			vector<double> _x, _s;
		public:

			/**
			 * @brief Main Constructor
			 * @param initials The initial guess of the coefficients
			 * @param x The test case input values
			 * @param s The test case output values
			 */
			PolyProblem(const vector<double>& initials, const vector<double>& x, const vector<double>& s) : ProblemBase(initials), _x(x), _s(s) {}

			virtual int GetTestCount() override { return _s.size(); }

			virtual void Evaluate(vector<double>& inputs, vector<double>& errors) 
			{
				// Get the counts
				auto inputCount = (int) inputs.size();
				auto testCount = GetTestCount();

				// Determine the results
				for (auto test = 0; test < testCount; test++) 
				{
					auto x = _x[test]; auto total = 0.0;

					for (auto i = inputCount - 1; i >= 0; i--) 
					{
						total += inputs[i] * pow(x, i);
					}

					auto error = abs(_s[test] - total);
					errors.push_back(error);
				}
			}
	};
}
