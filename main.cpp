#include <SFML/Graphics.hpp>
#include <iostream>
#include "ColorPicker.h"
#include "CurrentPick.h"
#include "TextBox.h"
#include <sstream>

sf::CircleShape brush(10.f);
sf::RenderWindow window(sf::VideoMode(1000, 768), "Paint Clone");
sf::RenderTexture canvas;
ColorPicker picker;
CurrentPick pick;



bool checkCords() {
	sf::Vector2i relCordsi = sf::Mouse::getPosition(window);
	//std::cout << "X :" << relCordsi.x << " Y: " << relCordsi.y<<std::endl;
	for (auto& elem : picker.initListColors()) {
	if (relCordsi.x < elem.getXPos()+30 && relCordsi.y < elem.getYPos()+30)
	{
			brush.setFillColor(elem.getColor());
			pick.setColor(elem.getColor());
			pick.draw(canvas);
			
			return true;
		}
	}
	return false;
	
}

int main()
{
	sf::View view = window.getDefaultView();
	view.setSize(1000, -768);
	brush.setFillColor(sf::Color::Black);
	window.setView(view);
	window.setFramerateLimit(60);
	canvas.create(1000, 768);
	canvas.clear(sf::Color::White);
	picker.draw(canvas);
	pick.draw(canvas);
	sf::RectangleShape clear = picker.drawTextBox(canvas);

	sf::Font font;
	font.loadFromFile("./Montserrat-Regular.ttf");
	sf::Text t;
	t.setFillColor(sf::Color::Black);
	t.setFont(font);
	t.setPosition(812, 32);
	std::string s = "";
	std::string setHex = "";
	t.setString(s);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (!checkCords()) {
				sf::Vector2f ms = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
				if (ms.y > 100) {
					brush.setPosition(ms);
					canvas.draw(brush);
				}
			}
		}
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					if (event.text.unicode == 8 && !s.empty()) {
						// Obs³uga klawisza "backspace" (usuwanie znaków)
						s = s.erase(s.size() - 1, 1);
						t.setString(s);
						canvas.draw(clear);
						canvas.draw(t);
						
					}
					else if (event.text.unicode == '\r' || event.text.unicode == '\n') {
						setHex = s;
						s = "";
						if (picker.validateHexColor(setHex)) {
							std::cout << "Color is valid!" << std::endl;
							canvas.draw(clear);
							sf::Color color = picker.makeColorFromHexString(setHex);
							brush.setFillColor(color);
							pick.setColor(color);
							pick.draw(canvas);
						}
						else {
							std::cout << "Color is invalid!" << std::endl;
							canvas.draw(clear);
						}
					}
					else {
						// Dodawanie wpisanych znaków
						s += event.text.unicode;
						t.setString(s);
						canvas.draw(t);
					}
				}
			}
		}
		sf::Sprite canvasSprite(canvas.getTexture());
		window.draw(canvasSprite);
		window.display();
	}
	return 0;
}


