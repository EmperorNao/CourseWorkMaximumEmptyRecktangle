#pragma once
#include "Types.h"
#include <SFML/Graphics.hpp>

class Render
{

	sf::Font font;
	void init();
	sf::Window window;
	rectangle l_b;
	rectangle r_b;
	

public:

	Render(rectangle l_button, rectangle r_button);
	void start();
	void end();
	void solution(input_data d, rectangle solution);
	void close();
	sf::Vector2i get_mouse_position();
	bool is_window_open();
	bool poll_event(sf::Event& e);

};

