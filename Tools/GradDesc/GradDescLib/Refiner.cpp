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
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param problem The problem that we are processing
 */
Refiner::Refiner(ProblemBase * problem)
{
	_problem = problem;
}

/**
 * @brief Defines the main terminator associated with the application
 */
Refiner::~Refiner() 
{
	delete _problem;
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
  	int m = _problem->GetTestCount();
  	int n = _problem->GetArguments().size();
	int lwa = (m * n) + (5 * n) + m;

	// Declare working variables
	int info, iwa[n], one=1;
  	double tol, fnorm, x[n], fvec[m], wa[lwa];

	// Setup the initial guess
	for (auto i = 0; i < n; i++) x[i] = _problem->GetArguments()[i];

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
	_problem->Evaluate(inputs, errors);
	copy(errors.begin(), errors.end(), fvec);
}