#include <SFML/Graphics.hpp>
//#include "Controller.h"
#include "Converter.h"
#include <iostream>

int main()
{
	Converter converter;
	rectangle r = { {0,0}, {9,9} };
	std::vector<point> T = { {0,0} };
	std::vector<rectangle> B = { {{8,2}, {9,6}} };
	input_data id;
	id.A = r;
	id.T = T;
	id.B = B;
	MERdata md = converter.get_converted_data(id, 1);
	for (auto p : md.S) {

		std::cout << p.x << " " << p.y<< std::endl;

	}

	//Controller controller;
	//controller.run();
	/*
	MERSolver solver;
	MERdata md;
	md.A = { {0, 0}, {7, 6} };
	md.S = { {1,1},{1,5},{2,2},{2,4},{3,5},{6,1},{6,5},{4,1},{4,5},{6,3},{6,4}};
	rectangle r = solver.get_solution(md);
	std::cout  << r.lb.x << r.rt.x << r.lb.y  << r.rt.y <<" " << abs((r.lb.x - r.rt.x) * (r.lb.y - r.rt.y)) ;
	*/
	/*
	// —оздаем окно размером 600 на 600 и частотой обновлени€ 60 кадров в секунду
	sf::RenderWindow window(sf::VideoMode(600, 600), "15");
	window.setFramerateLimit(60);
	window.clear();
	window.display();

	sf::Event event;

	//while (window.isOpen())
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// ѕолучаем нажатую клавишу - выполн€ем соответствующее действие
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
		}

		std::string str;
		std::getline(std::cin, str);

		sf::Font font;
		font.loadFromFile("1278.ttf");
		// Create a text
		sf::Text text(str, font);
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::Red);


		// ¬ыполн€ем необходимые действи€ по отрисовке
		window.clear();
		window.draw(text);
		window.display();
	}

	return 0;
	*/

}