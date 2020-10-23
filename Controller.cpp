/*#include "Controller.h"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include <fstream>
// константы для кнопок

static const rectangle l_b = { {10,10}, {20,20} };
static const rectangle r_b = { {40,10}, {50, 20} };

Controller::Controller() {


}

void Controller::run() {

	rectangle left_button = l_b;
	rectangle right_button = r_b;

	Render render(left_button, right_button);
	sf::Event event;

	int input = 0;
	while (render.is_window_open() && (!input)) {

		render.start();

		while (render.poll_event(event)) {

			if (event.type == sf::Event::Closed) {

				render.close();

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localPosition = render.get_mouse_position();

				if ((localPosition.x > 300)) {

					input = 1;

				}

				else if (localPosition.x <= 300) {

					input = -1;

				}

			}

		}

	}

	std::string fname_input = "input.txt";
	if (input == 1) {

		std::cin >> fname_input;

	}
	std::ifstream ifs(fname_input, std::ifstream::in);
	std::istream& is = input == -1 ? ifs : std::cin;

	Reader reader(is);
	Converter converter;
	MERSolver solver;

	input_data id = reader.read_input_data();
	MERdata md = converter.get_converted_data(id, 1);
	rectangle solution = solver.get_solution(md);

	input = 0;
	while (render.is_window_open() && (!input)) {

		render.end();

		while (render.poll_event(event)) {

			if (event.type == sf::Event::Closed) {

				render.close();

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localPosition = render.get_mouse_position();

				if ((localPosition.x > 300)) {

					input = 1;

				}

				else if (localPosition.x <= 300) {

					input = -1;

				}

			}

		}

	}

	std::string fname_output = "output.txt";
	if (input == 1) {

		std::cin >> fname_output;

	}
	std::ofstream ofs(fname_output, std::ofstream::out);
	std::ostream& os = input == -1 ? ofs : std::cout;

	Writer writer(os);

	while (render.is_window_open()) {

		if (event.type == sf::Event::Closed) {

			render.close();

		}

		render.solution(id, solution);

	}

}
*/