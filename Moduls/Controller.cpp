#include "Controller.h"
#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include <fstream>

// константы для кнопок
static rectangle l_b = { {100, 300}, {180, 340} };
static rectangle r_b = { {350, 300}, {485, 340} };

Controller::Controller() {

}

void Controller::run() {

	sf::Event event;
	Render render(l_b, r_b);

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "MER programm");
	window.setFramerateLimit(60);

	int input = 0;
	while (window.isOpen() && (!input)) {

		render.buttons("INPUT", window);

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

			if (event.type = sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape) window.close();

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localPosition =  sf::Mouse::getPosition(window);

				if ((localPosition.x > l_b.lb.x) and (localPosition.x < l_b.rt.x) and (localPosition.y > l_b.lb.y) and (localPosition.y < l_b.rt.y)) {

					input = 1;

				}

				if ((localPosition.x > r_b.lb.x) and (localPosition.x < r_b.rt.x) and (localPosition.y > r_b.lb.y) and (localPosition.y < r_b.rt.y)) {

					input = -1;

				}

			}

		}

	}

	std::string fname_input = "input.txt";
	std::ifstream ifs;
	if (input == 1) {

		ifs.exceptions(std::ifstream::failbit);
		while (!ifs.is_open()) {

			try {

				std::cout << "Введите имя файла с входными данными: ";
				std::getline(std::cin, fname_input);
				ifs.open(fname_input, std::ifstream::out);

			}
			catch (const std::ifstream::failure & e) {

				std::cout << "Невозможно открыть файл, проверьте его имя и попробуйте ещё раз.\n";

			}

		}

	}
	else {

		std::cout << "Введите данные: " << std::endl;

	}

	std::istream& is = input == 1 ? ifs : std::cin;

	Reader reader(is);
	Converter converter;
	MERSolver solver;

	input_data id = reader.read_input_data();
	MERdata md = converter.get_converted_data(id, 1);
	rectangle solution = solver.get_solution(md);

	input = 0;
	while (window.isOpen() && (!input)) {

		render.buttons("OUTPUT", window);

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

			if (event.type = sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape) window.close();

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localPosition =  sf::Mouse::getPosition(window);

				if ((localPosition.x > l_b.lb.x) and (localPosition.x < l_b.rt.x) and (localPosition.y > l_b.lb.y) and (localPosition.y < l_b.rt.y)) {

					input = 1;

				}

				if ((localPosition.x > r_b.lb.x) and (localPosition.x < r_b.rt.x) and (localPosition.y > r_b.lb.y) and (localPosition.y < r_b.rt.y)) {

					input = -1;

				}

			}

		}

	}

	std::string fname_output = "output.txt";
	std::ofstream ofs;
	if (input == 1) {

		ofs.exceptions(std::ofstream::failbit);
		while (!ofs.is_open()) {

			try {

				std::cout << "Введите имя файла для вывода: ";
				std::getline(std::cin, fname_output);
				ofs.open(fname_output, std::ofstream::out);

			}
			catch (std::ios_base::failure & fail) {

				std::cout << "Невозможно открыть файл, попробуйте ещё раз.\n";

			}

		}

	}
	else {

		std::cout << "Решение: " << std::endl;

	}
	std::ostream& os = input == 1 ? ofs : std::cout;

	Writer writer(os);
	writer.write_output_data(solution);

	while (window.isOpen()) {

		if (event.type == sf::Event::Closed) {

			window.close();

		}

		if (event.type = sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Escape) window.close();

		}

		render.solution(id, solution, window);

	}

}