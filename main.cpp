#include <SFML/Graphics.hpp>
#include <iostream>
#include "ColorPicker.cpp"

sf::CircleShape brush(10.f);
sf::RenderWindow window(sf::VideoMode(1000, 768), "Paint Clone");
sf::RenderTexture canvas;


sf::CircleShape getRecToDrow(ColorPicker cp) {
	sf::CircleShape rs;
	rs.setRadius(cp.getXSize());
	rs.setFillColor(cp.getColor());
	rs.setPosition(cp.getXPos(), cp.getYPos());
	return rs;

}


void drawColorPicker() {
	ColorPicker redPic(15, 25, 0, 0, sf::Color::Red);
	ColorPicker bluePic(15, 25, 40, 0, sf::Color::Blue);
	ColorPicker blackPic(15, 25, 80, 0, sf::Color::Black);
	ColorPicker greePic(15, 25, 120, 0, sf::Color::Green);
	ColorPicker yelPic(15, 25, 160, 0, sf::Color::Yellow);
	ColorPicker cyPic(15, 25, 200, 0, sf::Color::Cyan);
	ColorPicker magPic(15, 25, 240, 0, sf::Color::Magenta);
	ColorPicker orangePic(15, 25, 280, 0, sf::Color(255, 128, 0));

	sf::CircleShape red = getRecToDrow(redPic);
	sf::CircleShape blue = getRecToDrow(bluePic);
	sf::CircleShape black = getRecToDrow(blackPic);
	sf::CircleShape green = getRecToDrow(greePic);
	sf::CircleShape yellow = getRecToDrow(yelPic);
	sf::CircleShape cyan = getRecToDrow(cyPic);
	sf::CircleShape magenta = getRecToDrow(magPic);
	sf::CircleShape orange = getRecToDrow(orangePic);
	canvas.draw(red);
	canvas.draw(blue);
	canvas.draw(black);
	canvas.draw(green);
	canvas.draw(yellow);
	canvas.draw(cyan);
	canvas.draw(magenta);
	canvas.draw(orange);
}

bool checkCords() {
	sf::Vector2i relCordsi = sf::Mouse::getPosition(window);
	if (relCordsi.x < 25 && relCordsi.y < 25) {
		brush.setFillColor(sf::Color::Red);
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	sf::View view = window.getDefaultView();
	view.setSize(1000, -768);
	window.setView(view);
	window.setFramerateLimit(240);

	
	canvas.create(1000, 768);
	canvas.clear(sf::Color::White);

	drawColorPicker();

	brush.setFillColor(sf::Color::Black);

	while (window.isOpen())
	{
		sf::Event event;

		window.pollEvent(event);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			if (!checkCords()) {

				sf::Vector2f ms = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

				brush.setPosition(ms);
				canvas.draw(brush);

				sf::Sprite canvasSprite(canvas.getTexture());
				window.draw(canvasSprite);

				window.display();
			}
		}
	}

	return 0;
}


