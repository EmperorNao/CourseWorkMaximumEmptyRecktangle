#include "Reader.h"
#define CATCH_CONFIG_MAIN
#include <iostream>

Reader::Reader(std::istream& input_stream) : is(input_stream) {

}

input_data Reader::read() {

	input_data d;
	is >> d.A.lb.x;
	is >> d.A.lb.y;

	int n;
	is >> n;
	d.T.resize(n);

	for (auto p: d.T) {
		
		is >> p.x;
		is >> p.y;

	}

	int k;
	is >> k;
	d.B.resize(k);

	for (auto b : d.B) {

		is >> b.lb.x;
		is >> b.lb.y;
		is >> b.rt.x;
		is >> b.rt.y;

	}

	return d;

}

input_data Reader::read_input_data() {

		return read();

}
