#include "Converter.h"

MERdata Converter::convert(input_data d, int dist) {

	MERdata md;
	md.A.lb = d.A.lb;
	md.A.rt = d.A.rt;

	bool l = true, r = true, t = true, b = true;

	for (auto p : d.T) {

		if (p.x == d.A.lb.x) {

			l = false;

		}

		else if (p.x == d.A.rt.x) {

			r = false;

		}

		if (p.y == d.A.lb.y) {

			b = false;

		}

		else if (p.y == d.A.rt.y) {

			t = false;

		}

		if (l) {

			md.S.push_back({ p.x - dist, p.y });
			if (t) {

				md.S.push_back({ p.x - dist, p.y + dist });

			}

			if (b) {

				md.S.push_back({ p.x - dist, p.y - dist });

			}


		}

		if (t) {

			md.S.push_back({ p.x, p.y + dist });

		}

		if (b) {

			md.S.push_back({ p.x, p.y - dist });

		}

		if (r) {

			md.S.push_back({ p.x + dist, p.y });
			if (t) {

				md.S.push_back({ p.x + dist, p.y + dist });

			}

			if (b) {

				md.S.push_back({ p.x + dist, p.y - dist });

			}

		}

		l = true, r = true, t = true, b = true;

	}

	for (auto rect : d.B) {

		if (rect.lb.x == d.A.lb.x) {

			l = false;

		}

		else if (rect.rt.x == d.A.rt.x) {

			r = false;

		}

		if (rect.lb.y == d.A.lb.y) {

			b = false;

		}

		else if (rect.rt.y == d.A.rt.y) {

			t = false;

		}

		if (l) {

			int diff = rect.rt.y - rect.lb.y;

			for (int y = 0; y <= diff; y++) {

				md.S.push_back({rect.lb.x - dist, rect.lb.y + y});

			}

			diff = rect.rt.x - rect.lb.x;
			if (t) {

				md.S.push_back({rect.lb.x - dist, rect.rt.y + dist});

			}

			if (b) {

				md.S.push_back({rect.lb.x - dist, rect.lb.y - dist});

			}


		}

		int diff = rect.rt.x - rect.lb.x;
		if (t) {

			for (int x = 0; x <= diff; x++) {

				md.S.push_back({ rect.lb.x + x, rect.rt.y + dist });

			}

		}

		if (b) {

			for (int x = 0; x <= diff; x++) {

				md.S.push_back({ rect.lb.x + x, rect.lb.y - dist });

			}

		}


		if (r) {

			int diff = rect.rt.y - rect.lb.y;

			for (int y = 0; y <= diff; y++) {

				md.S.push_back({rect.rt.x + dist, rect.lb.y + y});

			}

			if (t) {

				md.S.push_back({rect.rt.x + dist, rect.rt.y + dist});

			}

			if (b) {

				md.S.push_back({rect.rt.x + dist, rect.lb.y - dist});

			}

		}

		l = true, r = true, t = true, b = true;

	}

	return md;

}

Converter::Converter() {

}

MERdata Converter::get_converted_data(input_data d, int dist) {

	return convert(d, dist);

}