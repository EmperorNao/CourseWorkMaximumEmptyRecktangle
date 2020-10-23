#include "Reader.h"
#define CATCH_CONFIG_MAIN
#include <iostream>

Reader::Reader(std::istream& input_stream) : is(input_stream) {

}

input_data Reader::read() {

	input_data d;
	is >> d.A.lb.x;
	is >> d.A.lb.y;
	is >> d.A.rt.x;
	is >> d.A.rt.y;

	int n;
	is >> n;
	d.T.resize(n);

	for (int i = 0; i < n; i++) {
		
		is >> d.T[i].x;
		is >> d.T[i].y;

	}

	int k;
	is >> k;
	d.B.resize(k);

	for (int i = 0; i < k; i++) {

		is >> d.B[i].lb.x;
		is >> d.B[i].lb.y;
		is >> d.B[i].rt.x;
		is >> d.B[i].rt.y;

	}

	return d;

}

input_data Reader::read_input_data() {

		return read();

}
