#pragma once
#include "Types.h"
#include <SFML/Graphics.hpp>

class Render
{

	sf::Font font;
	void init();
	rectangle l_b;
	rectangle r_b;
	

public:

	Render(rectangle l_button, rectangle r_button);
	void buttons(std::string s, sf::RenderWindow& w);
	void solution(input_data d, rectangle solution, sf::RenderWindow& w);

};

