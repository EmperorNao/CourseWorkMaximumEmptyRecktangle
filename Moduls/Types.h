#pragma once
#include <iostream>
#include <vector>

static const int WINDOW_SIZE = 600;

struct point {

	int x;
	int y;

};

struct rectangle {

	point lb;
	point rt;

};

struct  input_data {

	rectangle A;
	std::vector<point> T;
	std::vector<rectangle> B;

};

struct MERdata {

	rectangle A;
	std::vector<point> S;

};
