#include "FillPen.h"
#include <queue>
sf::RectangleShape pixel(sf::Vector2f(1, 1));


void FillPen::DrawToolbarIcon(sf::RenderTexture& canvas)
{
	sf::Texture iconTexture;
	iconTexture.loadFromFile("fill.jpg");
	sf::Sprite icon;
	icon.setTexture(iconTexture);
	icon.setPosition(this->pozX, this->pozY);
	icon.setScale(0.15f, 0.15f);
	canvas.draw(icon);



}


void FillPen::floodFill(sf::Image& image, const sf::Vector2i& relCordsi, const sf::Color& fillColor)
{
	//std::cout << "FROM METHOD : X :" << relCordsi.x << " Y: " << relCordsi.y << std::endl;
	if (relCordsi.x >= image.getSize().x || relCordsi.y >= image.getSize().y)
		return;

	std::queue<sf::Vector2i> fillStack;


	fillStack.push(relCordsi);


	sf::Color target = image.getPixel(relCordsi.x, relCordsi.y);
	std::cout << "Target Color: R:" << static_cast<int>(target.r)
          << " G:" << static_cast<int>(target.g)
          << " B:" << static_cast<int>(target.b)
          << " A:" << static_cast<int>(target.a) << std::endl;

	while (!fillStack.empty())
	{

		sf::Vector2i currentPos = fillStack.front();

		fillStack.pop();


		if (currentPos.x < image.getSize().x && currentPos.y < image.getSize().y)
		{

			if (currentPos.y > 100)
			{

				sf::Color currentColor = image.getPixel(currentPos.x, currentPos.y);
				
				if (currentColor == target && currentColor != fillColor)
				{
					image.setPixel(currentPos.x, currentPos.y, fillColor);
					if (currentColor == target) {
						fillStack.push(sf::Vector2i(currentPos.x, currentPos.y - 1)); // Up	
						fillStack.push(sf::Vector2i(currentPos.x, currentPos.y + 1)); // Down
						fillStack.push(sf::Vector2i(currentPos.x - 1, currentPos.y)); // Left
						fillStack.push(sf::Vector2i(currentPos.x + 1, currentPos.y)); // Right
					}
				}

			}
		}
	}
}




void FillPen::process(int x, int y, sf::RenderTexture& canvas)
{
	
	
}

void FillPen::SetTool(sf::RenderTexture& canvas)
{





}