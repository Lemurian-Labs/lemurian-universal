// api.cpp: application programming interface demonstration of fixed-size, arbitrary precision logarithmic number system
//
// Copyright (C) 2017-2022 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.
#include <universal/utility/directives.hpp>
// minimum set of include files to reflect source code dependencies
#include <universal/number/lns/lns.hpp>
#include <universal/number/cfloat/cfloat.hpp>  // bit field comparisons
#include <universal/verification/test_suite.hpp>

template<size_t nbits> 
int VerifyAddition(bool reportTestCases) {
	int nrOfFailedTestCases = 0;

	if (reportTestCases) std::cout << '\n';

	return nrOfFailedTestCases;
}

// Regression testing guards: typically set by the cmake configuration, but MANUAL_TESTING is an override
#define MANUAL_TESTING 1
// REGRESSION_LEVEL_OVERRIDE is set by the cmake file to drive a specific regression intensity
// It is the responsibility of the regression test to organize the tests in a quartile progression.
//#undef REGRESSION_LEVEL_OVERRIDE
#ifndef REGRESSION_LEVEL_OVERRIDE
#undef REGRESSION_LEVEL_1
#undef REGRESSION_LEVEL_2
#undef REGRESSION_LEVEL_3
#undef REGRESSION_LEVEL_4
#define REGRESSION_LEVEL_1 1
#define REGRESSION_LEVEL_2 1
#define REGRESSION_LEVEL_3 1
#define REGRESSION_LEVEL_4 1
#endif

int main()
try {
	using namespace sw::universal;

	std::string test_suite  = "lns API demonstration";
	std::string test_tag    = "api";
	bool reportTestCases    = false;
	int nrOfFailedTestCases = 0;

	ReportTestSuiteHeader(test_suite, reportTestCases);

	// important behavioral traits
	{
		using Real = lns<8, 2>;
		bool isTrivial = bool(std::is_trivial<Real>());
		static_assert(std::is_trivial<Real>(), "lns should be trivial but failed the assertion");
		std::cout << (isTrivial ? "lns is trivial" : "lns failed trivial: FAIL") << '\n';

		bool isTriviallyConstructible = bool(std::is_trivially_constructible<Real>());
		static_assert(std::is_trivially_constructible<Real>(), "lns should be trivially constructible but failed the assertion");
		std::cout << (isTriviallyConstructible ? "lns is trivial constructible" : "lns failed trivial constructible: FAIL") << '\n';

		bool isTriviallyCopyable = bool(std::is_trivially_copyable<Real>());
		static_assert(std::is_trivially_copyable<Real>(), "lns should be trivially copyable but failed the assertion");
		std::cout << (isTriviallyCopyable ? "lns is trivially copyable" : "lns failed trivially copyable: FAIL") << '\n';

		bool isTriviallyCopyAssignable = bool(std::is_trivially_copy_assignable<Real>());
		static_assert(std::is_trivially_copy_assignable<Real>(), "lns should be trivially copy-assignable but failed the assertion");
		std::cout << (isTriviallyCopyAssignable ? "lns is trivially copy-assignable" : "lns failed trivially copy-assignable: FAIL") << '\n';
	}

	{
		using Real = lns<8, 2, std::uint8_t>;
		Real a, b, c;
		a = 1.0f;
		b = 1.0f;
		c = a + b;
		ReportValues(a, "+", b, c);
		c = a - b;
		ReportValues(a, "-", b, c);
		c = a * b;
		ReportValues(a, "*", b, c);
		c = a / b;
		ReportValues(a, "/", b, c);

	}
#if MANUAL_TESTING

	// generate individual testcases to hand trace/debug
	//TestCase< lns<16, 5, uint8_t>, double>(TestCaseOperator::ADD, INFINITY, INFINITY);
	//TestCase< lns<8, 2, uint8_t>, float>(TestCaseOperator::ADD, 0.5f, -0.5f);

	{
		using LNS = lns<16, 8, std::uint16_t>;
		using Real = cfloat<16, 5, std::uint16_t>;
		LNS a;
		Real b;
		static_assert(std::is_trivially_constructible<LNS>(), "lns<> is not trivially constructible");
		a = 1;
		std::cout << std::setw(80) << type_tag(a) << " : " << to_binary(a, true) << " : " << color_print(a, true) << " : " << float(a) << '\n';
		b = 1;
		std::cout << std::setw(80) << type_tag(b) << " : " << to_binary(b, true) << " : " << color_print(b, true) << " : " << float(b) << '\n';
	}
	
	//nrOfFailedTestCases += ReportTestResult(VerifyAddition<8>(reportTestCases), "lns<8>", test_tag);

	ReportTestSuiteResults(test_suite, nrOfFailedTestCases);
	return EXIT_SUCCESS;
#else
#if REGRESSION_LEVEL_1

#endif

#if REGRESSION_LEVEL_2
#endif

#if REGRESSION_LEVEL_3
#endif

#if REGRESSION_LEVEL_4
#endif

	ReportTestSuiteResults(test_suite, nrOfFailedTestCases);
	return (nrOfFailedTestCases > 0 ? EXIT_FAILURE : EXIT_SUCCESS);
#endif  // MANUAL_TESTING
}
catch (char const* msg) {
	std::cerr << msg << std::endl;
	return EXIT_FAILURE;
}
catch (const std::runtime_error& err) {
	std::cerr << "Uncaught runtime exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (...) {
	std::cerr << "Caught unknown exception" << std::endl;
	return EXIT_FAILURE;
}
