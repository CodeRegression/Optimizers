//--------------------------------------------------
// Unit Tests for class Refiner
//
// @author: Wild Boar
//
// @date: 2023-04-01
//--------------------------------------------------

#include <gtest/gtest.h>

#include <GradDescLib/Refiner.h>
#include <GradDescLib/Problems/PolyProblem.h>
using namespace NVL_App;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Add the logic to solve a sequence of polynomials
 */
TEST(Refiner_Test, polynomial_test)
{
	// Setup
	auto c = vector<double> { 2, -3, 5}; auto initC = vector<double> { 1, 1, 1 };
	auto x = vector<double>(); auto s = vector<double>();

	for (auto i = 1; i < 10; i++) 
	{
		x.push_back(i);
		auto answer = c[2] * i * i + c[1] * i + c[0];
		s.push_back(answer);
	}

	auto problem = unique_ptr<ProblemBase>(new PolyProblem(initC, x, s));

	// Execute
	auto refiner = Refiner(problem.get());
	auto solution = refiner.Solve();

	// Confirm
	ASSERT_NEAR(solution->GetSolution()[0], 2, 1e-4);
	ASSERT_NEAR(solution->GetSolution()[1], -3, 1e-4);
	ASSERT_NEAR(solution->GetSolution()[2], 5, 1e-4);
}
