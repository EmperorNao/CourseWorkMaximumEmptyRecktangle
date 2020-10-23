#pragma once
#include "Types.h"

class MERSolver
{

private:

	point best_low;
	point best_high;
	int max_s;

	void MGAP(std::vector<int> arr, int* left_best, int* right_best);
	void sort_by_coord(std::vector<point>& arr, bool x, bool asc);
	void save_best_params(int x_left_best, int x_right_best, int y_bottom_best, int y_top_best);
	rectangle solve(MERdata md);

public:

	MERSolver();
	rectangle get_solution(MERdata md);

};

