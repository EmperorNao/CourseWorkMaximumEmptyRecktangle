#include "MERSolver.h"
#include <algorithm>

MERSolver::MERSolver() {

}

void MERSolver::save_best_params(int x_left_best, int x_right_best, int y_bottom_best, int y_top_best) {

	int t = (x_right_best - x_left_best) * (y_top_best - y_bottom_best);
	if (t > max_s) {

		// сохраняем лучшие параметры
		best_low.x = x_left_best;
		best_low.y = y_bottom_best;

		best_high.x = x_right_best;
		best_high.y = y_top_best;

		max_s = t;

	}

}

void MERSolver::sort_by_coord(std::vector<point>& arr, bool x, bool asc) {

	int i, j;
	point key;

	int param = 1;
	if (!asc) {
	
		param = -1;

	}

	if (x) {

		for (i = 1; i < arr.size(); i++)
		{

			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j].x * param > key.x * param)
			{

				arr[j + 1] = arr[j];
				j = j - 1;

			}
			arr[j + 1] = key;

		}

	}

	else {

		for (i = 1; i < arr.size(); i++)
		{

			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j].y * param > key.y * param)
			{

				arr[j + 1] = arr[j];
				j = j - 1;

			}

			arr[j + 1] = key;

		}

	}

}

void MERSolver::MGAP(std::vector<int> arr, int* left_best, int* right_best) {

	int max_gap = 0;
	int t;

	for (int i = 0; i < arr.size() - 1; i++) {

		t = arr[i + 1] - arr[i];
		if (t > max_gap) {

			*left_best = arr[i];
			*right_best = arr[i + 1];
			max_gap = t;

		}

	}

}

rectangle MERSolver::solve(MERdata md) {

	max_s = 0;

	int x_l, x_r;
	sort_by_coord(md.S, true, true);

	std::vector<int> x_points;
	x_points.push_back(md.A.lb.x);
	for (auto p : md.S) {

		x_points.push_back(p.x);

	}
	x_points.push_back(md.A.rt.x);

	MGAP(x_points, &x_l, &x_r);
	save_best_params(x_l, x_r, md.A.lb.y, md.A.rt.y);

	sort_by_coord(md.S, false, false);

	for (int i = 0; i < md.S.size(); i++) {

		x_l = md.A.lb.x;
		x_r = md.A.rt.x;
		
		for (int j = i + 1; j < md.S.size(); j++) {

			if ((x_l < md.S[j].x) and ( md.S[j].x < x_r)) {

				save_best_params(x_l, x_r, md.S[j].y, md.S[i].y);

				if (md.S[j].x > md.S[i].x) {

					x_r = md.S[j].x;

				}

				else {

					x_l = md.S[j].x;

				}

			}

		}

		save_best_params(x_r, x_l, md.A.lb.y, md.S[i].y);

	}

	for (int i = 0; i < md.S.size(); i++) {

		std::vector<int> points;

		for (int j = 0; j < md.S.size(); j++) {

			if ((md.S[j].y > md.S[i].y) and (md.S[j].x > md.S[i].x)) {

				points.push_back(md.S[j].x);

			}

		}

		points.push_back(md.A.rt.x); 

		int l = *std::min_element(points.begin(), points.end());

		points.resize(0);

		for (int j = 0; j < md.S.size(); j++) {

			if ((md.S[j].y > md.S[i].y) and (md.S[j].x < md.S[i].x)) {

				points.push_back(md.S[j].x);

			}

		}

		points.push_back(md.A.lb.x); 

		int r = *std::max_element(points.begin(), points.end());

		save_best_params(l, r,  md.S[i].y, md.A.rt.y);

	}

	return { best_low, best_high };


}
	
rectangle MERSolver::get_solution(MERdata md) {

	return solve(md);

}