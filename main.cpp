#include <SFML/Graphics.hpp>
#include <iostream>

sf::CircleShape brush(10.f);
sf::RenderWindow window(sf::VideoMode(800, 600), "Paint Clone");


bool checkCords() {
	sf::Vector2i relCordsi = sf::Mouse::getPosition(window);
	if (relCordsi.x < 50 && relCordsi.y < 50) {
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
	view.setSize(800, -600);
	window.setView(view);
	window.setFramerateLimit(240);

	sf::RenderTexture canvas;
	canvas.create(800, 600);
	canvas.clear(sf::Color::White);

	sf::RectangleShape red;
	red.setSize(sf::Vector2f(50, 50));
	red.setFillColor(sf::Color::Red);
	red.setOutlineColor(sf::Color::Red);
	red.setOutlineThickness(5);
	red.setPosition(0, 0);

	canvas.draw(red);

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


