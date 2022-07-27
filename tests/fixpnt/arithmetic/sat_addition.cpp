// sat_addition.cpp: test suite runner for arbitrary configuration fixed-point Saturate addition
//
// Copyright (C) 2017-2022 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.
#include <universal/utility/directives.hpp>
#include <iostream>
#include <iomanip>

// Configure the fixpnt template environment
// first: enable general or specialized fixed-point configurations
#define FIXPNT_FAST_SPECIALIZATION
// second: enable/disable fixpnt arithmetic exceptions
#define FIXPNT_THROW_ARITHMETIC_EXCEPTION 1
#include <universal/number/fixpnt/fixpnt.hpp>
#include <universal/verification/fixpnt_test_suite.hpp>

// generate specific test case that you can trace with the trace conditions in fixed_point.hpp
// for most bugs they are traceable with _trace_conversion and _trace_add
template<size_t nbits, size_t rbits, typename Ty>
void GenerateTestCase(Ty _a, Ty _b) {
	Ty ref;
	sw::universal::fixpnt<nbits, rbits, sw::universal::Saturate> a, b, cref, result;
	a = _a;
	b = _b;
	result = a + b;
	ref = _a + _b;
	cref = ref;
	std::streamsize oldPrecision = std::cout.precision();
	std::cout << std::setprecision(nbits - 2);
	std::cout << std::setw(nbits) << _a << " + " << std::setw(nbits) << _b << " = " << std::setw(nbits) << ref << std::endl;
	std::cout << a << " + " << b << " = " << result << " (reference: " << cref << ")   " ;
	std::cout << (cref == result ? "PASS" : "FAIL") << std::endl << std::endl;
	std::cout << std::dec << std::setprecision(oldPrecision);
}

// Regression testing guards: typically set by the cmake configuration, but MANUAL_TESTING is an override
#define MANUAL_TESTING 0
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

	std::string test_suite  = "Fixed-point Saturate addition ";
	std::string test_tag    = "Saturate addition";
	bool reportTestCases    = false;
	int nrOfFailedTestCases = 0;

	ReportTestSuiteHeader(test_suite, reportTestCases);

#if MANUAL_TESTING

	fixpnt<8, 4> f;
	f = 3.5f;
	bitset<8> bs(f.getbb().block(0));
	cout << bs << endl;
	cout << f << endl;

	// generate individual testcases to hand trace/debug
	GenerateTestCase<8, 4>(0.5f, 1.0f);

	reportTestCases = true;
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<4, 1, Saturate, uint8_t>(reportTestCases), "fixpnt<4,1,Saturate,uint8_t>", test_tag);


#ifdef REGRESSION_LEVEL_4
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<4, 0, Saturate, uint8_t>(reportTestCases), "fixpnt<4,0,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<4, 1, Saturate, uint8_t>(reportTestCases), "fixpnt<4,1,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<4, 2, Saturate, uint8_t>(reportTestCases), "fixpnt<4,2,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<4, 3, Saturate, uint8_t>(reportTestCases), "fixpnt<4,3,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<4, 4, Saturate, uint8_t>(reportTestCases), "fixpnt<4,4,Saturate,uint8_t>", test_tag);
#endif

	ReportTestSuiteResults(test_suite, nrOfFailedTestCases);
	return EXIT_SUCCESS; // ignore failures
#else

#if REGRESSION_LEVEL_1
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 4, 0, Saturate, uint8_t>(reportTestCases), "fixpnt< 4, 0,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 4, 1, Saturate, uint8_t>(reportTestCases), "fixpnt< 4, 1,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 4, 2, Saturate, uint8_t>(reportTestCases), "fixpnt< 4, 2,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 4, 3, Saturate, uint8_t>(reportTestCases), "fixpnt< 4, 3,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 4, 4, Saturate, uint8_t>(reportTestCases), "fixpnt< 4, 4,Saturate,uint8_t>", test_tag);
#endif

#if REGRESSION_LEVEL_2
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 0, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 0,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 1, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 1,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 2, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 2,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 3, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 3,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 4, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 4,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 5, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 5,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 6, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 6,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 7, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 7,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition< 8, 8, Saturate, uint8_t>(reportTestCases), "fixpnt< 8, 8,Saturate,uint8_t>", test_tag);
#endif

#if REGRESSION_LEVEL_3
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<10, 3, Saturate, uint8_t>(reportTestCases), "fixpnt<10, 3,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<10, 5, Saturate, uint8_t>(reportTestCases), "fixpnt<10, 5,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<10, 7, Saturate, uint8_t>(reportTestCases), "fixpnt<10, 7,Saturate,uint8_t>", test_tag);

	nrOfFailedTestCases += ReportTestResult(VerifyAddition<11, 3, Saturate, uint8_t>(reportTestCases), "fixpnt<11, 3,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<11, 5, Saturate, uint8_t>(reportTestCases), "fixpnt<11, 5,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<11, 7, Saturate, uint8_t>(reportTestCases), "fixpnt<11, 7,Saturate,uint8_t>", test_tag);
#endif

#if REGRESSION_LEVEL_4
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<12, 0, Saturate, uint8_t>(reportTestCases), "fixpnt<12, 0,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<12, 4, Saturate, uint8_t>(reportTestCases), "fixpnt<12, 4,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<12, 8, Saturate, uint8_t>(reportTestCases), "fixpnt<12, 8,Saturate,uint8_t>", test_tag);
	nrOfFailedTestCases += ReportTestResult(VerifyAddition<12,12, Saturate, uint8_t>(reportTestCases), "fixpnt<12,12,Saturate,uint8_t>", test_tag);
#endif

	ReportTestSuiteResults(test_suite, nrOfFailedTestCases);
	return (nrOfFailedTestCases > 0 ? EXIT_FAILURE : EXIT_SUCCESS);
#endif  // MANUAL_TESTING
}
catch (char const* msg) {
	std::cerr << msg << std::endl;
	return EXIT_FAILURE;
}
catch (const sw::universal::fixpnt_arithmetic_exception& err) {
	std::cerr << "Uncaught fixpnt arithmetic exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const sw::universal::fixpnt_internal_exception& err) {
	std::cerr << "Uncaught fixpnt internal exception: " << err.what() << std::endl;
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
