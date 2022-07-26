#pragma once
// complex.hpp: functions for complex lns
//
// Copyright (C) 2017-2022 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.
#include <complex>

namespace sw { namespace universal {

// Real component of a complex lns
template<size_t nbits, size_t rbits, typename bt>
lns<nbits, rbits, bt> 
real(std::complex< lns<nbits, rbits, bt> > x) {
	return lns<nbits, rbits, bt>(std::real(x));
}

// Imaginary component of a complex lns
template<size_t nbits, size_t rbits, typename bt>
lns<nbits, rbits, bt> 
imag(std::complex< lns<nbits, rbits, bt> > x) {
	return lns<nbits, rbits, bt>(std::imag(x));
}

// Conjucate of a complex lns
template<size_t nbits, size_t rbits, typename bt>
std::complex< lns<nbits, rbits, bt> > 
conj(std::complex< lns<nbits, rbits, bt> > x) {
	return lns<nbits, rbits, bt>(std::conj(x));
}

}} // namespace sw::universal