#include <SFML/Graphics.hpp>
#include <iostream>
#include "ColorPicker.h"
#include "CurrentPick.h"
#include "TextBox.h"
#include <sstream>
#include "ola.h"
#include "Toolbar.h"
#include "EraserTool.h"
#include "CirclePen.h"
#include "SquarePen.h"
#include "TrianglePen.h"
#include "Line.h"
#include "FileMenager.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

sf::CircleShape brush(10.f);
sf::RenderWindow window(sf::VideoMode(1000, 768), "Paint Clone");
sf::RenderTexture canvas;
sf::RenderWindow windowToolbar(sf::VideoMode(200, 300), "Toolbar");
sf::RenderTexture canvasToolbar;
sf::Color lineColor = sf::Color::Black;

ColorPicker picker;
CurrentPick pick;

Toolbar toolbar;
Tool* currentTool;
int currentWindow;


void initToolbar()
{
	toolbar.Tools.push_back(new CirclePen(35, 30));
	toolbar.Tools.push_back(new SquarePen(75, 30));
	toolbar.Tools.push_back(new TrianglePen(115, 30));
	toolbar.Tools.push_back(new EraserTool(35, 70));
	toolbar.Tools.push_back(new circle(35, 110));
	toolbar.Tools.push_back(new square(75, 110));
	toolbar.Tools.push_back(new triangle(115, 105));


	toolbar.DrawToolbarIcons(canvasToolbar);

	sf::Sprite canvasSpritex(canvasToolbar.getTexture());
	windowToolbar.draw(canvasSpritex);
	windowToolbar.display();
}


bool checkCords() {
	sf::Vector2i relCordsi = sf::Mouse::getPosition(window);
	std::cout << "X :" << relCordsi.x << " Y: " << relCordsi.y << std::endl;
	for (auto& elem : picker.initListColors()) {
		if (relCordsi.x < elem.getXPos() + 30 && relCordsi.y < elem.getYPos() + 30)
		{	
			
			brush.setFillColor(elem.getColor());
			pick.setColor(elem.getColor());
			pick.draw(canvas);
			lineColor = elem.getColor();

			if (currentTool != nullptr)
			{
				currentTool->SetColor(elem.getColor());
			}

			return true;
		}
	}
	return false;
}

bool saveCanvasToFile(const std::string& filename) {
	sf::Image screenshot = canvas.getTexture().copyToImage();
	return screenshot.saveToFile(filename);
}

bool loadCanvasFromFile(const std::string& filename) {
	sf::Image image;
	if (image.loadFromFile(filename)) {
		sf::Texture texture;
		texture.loadFromImage(image);
		canvas.clear();
		canvas.draw(sf::Sprite(texture));
		return true;
	}
	return false;
}

int main()
{
	sf::View view = window.getDefaultView();
	view.setSize(1000, -768);
	brush.setFillColor(sf::Color::Black);
	window.setView(view);
	window.setFramerateLimit(500);
	canvas.create(1000, 768);
	canvas.clear(sf::Color::White);
	picker.draw(canvas);
	pick.draw(canvas);
	sf::RectangleShape clear = picker.drawTextBox(canvas);

	//Toolbar
	sf::View viewToolbar = windowToolbar.getDefaultView();
	viewToolbar.setSize(200, -300);
	windowToolbar.setView(viewToolbar);
	windowToolbar.setFramerateLimit(60);
	canvasToolbar.create(200, 300);
	canvasToolbar.clear(sf::Color::White);
	windowToolbar.clear(sf::Color::White);
	sf::Sprite canvasSpritex(canvasToolbar.getTexture());
	windowToolbar.draw(canvasSpritex);
	windowToolbar.display();

	initToolbar();

	sf::Font font;
	font.loadFromFile("./Montserrat-Regular.ttf");
	sf::Text t;
	t.setFillColor(sf::Color::Black);
	t.setFont(font);
	t.setPosition(812, 32);
	std::string s = "";
	std::string setHex = "";

	

	picker.drawPlusIcon(canvas, font, 460, -10);
	picker.drawMinusIcon(canvas, font, 410, -17);
	picker.drawPngButton(canvas, font, 2, 5);
	picker.drawJpgButton(canvas, font, 2, 37);
	picker.drawLoadPngButton(canvas, font, 152, 5);
	picker.drawLoadJpgButton(canvas, font, 152, 37);
	picker.drawFillUpIcon(canvas, font, 320, 15);



	while (window.isOpen())
	{
		sf::Event event;
		while (windowToolbar.pollEvent(event)) {

			if (event.type == sf::Event::MouseEntered)
			{
				currentWindow = 1;
			}

			if (event.type == sf::Event::MouseLeft)
			{
				currentWindow = 0;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i relCordsi = sf::Mouse::getPosition(windowToolbar);
				std::cout << "Toolbar: X :" << relCordsi.x << " Y: " << relCordsi.y << std::endl;


				if (currentWindow == 1)
				{
					currentTool = toolbar.GetToolFromCord(relCordsi.x, relCordsi.y);

					if (currentTool != nullptr)
					{
						std::cout << "Tool is set to  " << typeid(currentTool).name();
						currentTool->SetTool(canvasToolbar);
					}
				}
			}
		}


		sf::Sprite canvasSpritex(canvasToolbar.getTexture());
		windowToolbar.draw(canvasSpritex);
		windowToolbar.display();


		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			sf::Vector2f ms = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			linia(window, event, canvas, lineColor);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


				if (ms.x < 150 && ms.y < 35) {
					if (saveCanvasToFile("canvas.png", canvas)) {
						std::cout << "Canvas saved to file: canvas.png" << std::endl;
					}
					else {
						std::cout << "Failed to save canvas!" << std::endl;
					}
				}
				if (ms.x > 150 && ms.x < 300 && ms.y < 35) {
					if (loadCanvasFromFile("canvas.png", canvas)) {
						std::cout << "Canvas loaded from file: canvas.png" << std::endl;

						//Odwrócenie canvasu
						sf::Image image = canvas.getTexture().copyToImage();
						image.flipVertically();
						sf::Texture texture;
						texture.loadFromImage(image);
						canvas.clear();
						canvas.draw(sf::Sprite(texture));
					}
					else {
						std::cout << "Failed to load canvas from file!" << std::endl;
					}
				}



					if (ms.x < 150 && ms.y > 35 && ms.y < 70) {
						if (saveCanvasToFile("canvas.jpeg", canvas)) {
							std::cout << "Canvas saved to file: canvas.jpeg" << std::endl;
						}
						else {
							std::cout << "Failed to save canvas!" << std::endl;
						}
					}
					if (ms.x > 150 && ms.x < 300 && ms.y > 35 && ms.y < 70) {
						if (loadCanvasFromFile("canvas.jpeg", canvas)) {
							std::cout << "Canvas loaded from file: canvas.jpeg" << std::endl;

							//Odwrócenie canvasu
							sf::Image image = canvas.getTexture().copyToImage();
							image.flipVertically();
							sf::Texture texture;
							texture.loadFromImage(image);
							canvas.clear();
							canvas.draw(sf::Sprite(texture));
						}
						else {
							std::cout << "Failed to load canvas from file!" << std::endl;
						}

				}

				if (!checkCords()) {

					if (ms.y > 100) {
						
						brush.setPosition(ms);
						
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (!checkCords()) {
					sf::Vector2f ms = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
					if (ms.y > 100) {
						//brush.setPosition(ms);

						if (currentTool != nullptr)
						{
							currentTool->process(ms.x, ms.y, canvas);
						}
						else
						{
							
							canvas.draw(brush);
						}
					}
				}
			}




			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					if (event.text.unicode == 8 && !s.empty()) {
						// Obsługa klawisza "backspace" (usuwanie znaków)
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


