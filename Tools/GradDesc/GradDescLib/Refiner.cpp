//--------------------------------------------------
// Implementation of class Refiner
//
// @author: Wild Boar
//
// @date: 2023-04-01
//--------------------------------------------------

#include "Refiner.h"
using namespace NVL_App;

//--------------------------------------------------
// Globals
//--------------------------------------------------

ProblemBase * PROBLEM;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param problem The problem that we are processing
 */
Refiner::Refiner(ProblemBase * problem)
{
	PROBLEM = problem;
}

//--------------------------------------------------
// Solver
//--------------------------------------------------

/**
 * @brief Add the logic to solve the problem
 * @return unique_ptr<Result> Returns a unique_ptr<Result>
 */
unique_ptr<Result> Refiner::Solve()
{
	// Setup the number of inputs and outputs
  	int m = PROBLEM->GetTestCount();
  	int n = PROBLEM->GetArguments().size();
	int lwa = (m * n) + (5 * n) + m;

	// Declare working variables
	int info, iwa[n], one=1;
  	double tol, fnorm, x[n], fvec[m], wa[lwa];

	// Setup the initial guess
	for (auto i = 0; i < n; i++) x[i] = PROBLEM->GetArguments()[i];

	// Perform the determination of a result
  	tol = sqrt((dpmpar_)(&one));
	lmdif1_(&Refiner::Callback, &m, &n, x, fvec, &tol, &info, iwa, wa, &lwa);
  	fnorm = enorm_(&m, fvec);

	// Add error counting logic
	return unique_ptr<Result>(new Result(fnorm, vector<double>(x, x + n)));
}

//--------------------------------------------------
// Callback method
//--------------------------------------------------

/**
 * @brief Add the logic to perform a callback
 * @param m The number of output parameters
 * @param n The number of input parameters
 * @param x The error flags
 * @param fvec An array containing the errors
 * @param iflag Associated flags
 */
void Refiner::Callback(int *m, int *n, double *x, double *fvec, int *iflag) 
{
	auto inputs = vector<double>(x, x + *n); auto errors = vector<double>();
	PROBLEM->Evaluate(inputs, errors);
	copy(errors.begin(), errors.end(), fvec);
}