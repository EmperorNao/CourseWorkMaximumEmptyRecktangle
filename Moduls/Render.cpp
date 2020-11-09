#include "Render.h"

void Render::init() {

	if (!font.loadFromFile("font.ttf")) throw;

}

Render::Render(rectangle l_button, rectangle r_button) {

	l_b = l_button;
	r_b = r_button;
	init();

}

void Render::buttons(std::string s, sf::RenderWindow& w) {

	w.clear();
	sf::RectangleShape shape(sf::Vector2f(l_b.rt.x - l_b.lb.x, l_b.rt.y - l_b.lb.y ));
	shape.setOutlineThickness(2.f);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setPosition(l_b.lb.x, l_b.lb.y);
	w.draw(shape);
	shape.setSize(sf::Vector2f(r_b.rt.x - r_b.lb.x, r_b.rt.y - r_b.lb.y));
	shape.setPosition(r_b.lb.x, r_b.lb.y);
	w.draw(shape);
	sf::Text text("FILE", font);
	text.setPosition(l_b.lb.x, l_b.lb.y);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	w.draw(text);
	text.setString("CONSOLE");
	text.setPosition(r_b.lb.x, r_b.lb.y);
	w.draw(text);
	text.setString(s);
	text.setPosition(0,0);
	w.draw(text);
	w.display();

}

void Render::solution(input_data d, rectangle solution, sf::RenderWindow& w) {

	w.clear();
	int shape_size = (d.A.rt.x - d.A.lb.x) > (d.A.rt.y - d.A.lb.y) ? (d.A.rt.x - d.A.lb.x) : (d.A.rt.y - d.A.lb.y);
	shape_size = WINDOW_SIZE / shape_size;

	sf::RectangleShape shape(sf::Vector2f((d.A.rt.x - d.A.lb.x) * shape_size, (d.A.rt.y - d.A.lb.y) * shape_size));
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color::White);
	w.draw(shape);
	
	shape.setSize(sf::Vector2f((solution.rt.x - solution.lb.x) * shape_size, (solution.rt.y - solution.lb.y) * shape_size));
	shape.setPosition(solution.lb.x * shape_size, WINDOW_SIZE - solution.rt.y * shape_size);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1.f);
	shape.setFillColor(sf::Color::Red);
	w.draw(shape);
	
	sf::CircleShape circle(shape_size/4);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(1.f);
	for (auto p : d.T) {

		circle.setPosition(sf::Vector2f((p.x * shape_size) - shape_size/4, WINDOW_SIZE - p.y * shape_size - shape_size/4));
		w.draw(circle);

	}

	shape.setFillColor(sf::Color::Blue);
	for (auto b : d.B) {

		shape.setSize(sf::Vector2f((b.rt.x - b.lb.x) * shape_size, (b.rt.y - b.lb.y) * shape_size));
		shape.setPosition(b.lb.x * shape_size, WINDOW_SIZE - b.rt.y * shape_size);
		w.draw(shape);

	}

	w.display();

}