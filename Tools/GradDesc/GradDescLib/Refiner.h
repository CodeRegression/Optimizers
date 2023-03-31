//--------------------------------------------------
// Add the logic to perform the refinement of parameters
//
// @author: Wild Boar
//
// @date: 2023-04-01
//--------------------------------------------------

#pragma once

#include <cmath>
#include <memory>
#include <iostream>
using namespace std;

#include <minpack.h>
#include "ProblemBase.h"
#include "Result.h"

namespace NVL_App
{
	class Refiner
	{
	private:
		static ProblemBase * _problem;
	public:
		Refiner(ProblemBase * problem);
		virtual ~Refiner();

		unique_ptr<Result> Solve();

		inline ProblemBase *& GetProblem() { return _problem; }
	private:
		static void Callback(int *m, int *n, double *x, double *fvec, int *iflag);
	};
}
