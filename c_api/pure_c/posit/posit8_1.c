// create the correct C11 infrastructure
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>  // for INFINITY

// pull in the specialized posit C definitions
#include <specialized/posit_8_1.h>

// pull in the source code to be compiled as a C library
#include <specialized/posit_8_1.h>

// elementary functions
posit8_1_t posit8_1_sqrt(posit8_1_t a) {
	posit8_1_t p;
	float f = posit8_1_tof(a);
	float root = sqrtf(f);
	p = posit8_1_fromf(root);
	return p;
}
posit8_1_t posit8_1_log(posit8_1_t a) {
	posit8_1_t p;
	float f = posit8_1_tof(a);
	float logarithm = logf(f);
	p = posit8_1_fromf(logarithm);
	return p;
}
posit8_1_t posit8_1_exp(posit8_1_t a) {
	posit8_1_t p;
	float f = posit8_1_tof(a);
	float exponent = expf(f);
	p = posit8_1_fromf(exponent);
	return p;
}
// logic functions
// cmp returns -1 if a < b, 0 if a == b, and 1 if a > b
int posit8_1_cmpp8(posit8_1_t a, posit8_1_t b) {
	// have to deal with the special case of NAR
	if (a.v == b.v) return 0;
	posit8_1_t diff = posit8_1_subp8(a, b);
	if (posit8_1_iszero(diff)) {
		return 0;
	}
	else if (posit8_1_isneg(diff)) {
		return -1;
	}
	return 1;
}

// string conversion functions
void posit8_1_str(char* str, posit8_1_t a) {
	float f = posit8_1_tof(a);
	sprintf(str, "%f", f);
}