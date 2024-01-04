#pragma once
// pow.hpp: pow functions for positos
//
// Copyright (C) 2017 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.

namespace sw { namespace universal {

// the current shims are NON-COMPLIANT with the posito standard, which says that every function must be
// correctly rounded for every input value. Anything less sacrifices bitwise reproducibility of results.

template<unsigned nbits, unsigned es>
posito<nbits,es> pow(posito<nbits,es> x, posito<nbits, es> y) {
	return posito<nbits,es>(std::pow(double(x), double(y)));
}
		
template<unsigned nbits, unsigned es>
posito<nbits,es> pow(posito<nbits,es> x, int y) {
	return posito<nbits,es>(std::pow(double(x), double(y)));
}
		
template<unsigned nbits, unsigned es>
posito<nbits,es> pow(posito<nbits,es> x, double y) {
	return posito<nbits,es>(std::pow(double(x), y));
}

}} // namespace sw::universal