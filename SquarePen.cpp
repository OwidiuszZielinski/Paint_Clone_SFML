#include "SquarePen.h"

void SquarePen::DrawToolbarIcon(sf::RenderTexture& canvas)
{
    sf::Texture iconTexture;
    iconTexture.loadFromFile("square.jpg");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;
}

void SquarePen::process(int x, int y, sf::RenderTexture& canvas)
{
    std::cout << "square tool";
    sf::RectangleShape rectangle(sf::Vector2f(this->pozX, this->pozY));
    rectangle.setSize(sf::Vector2f(20, 20));
    rectangle.setFillColor(this->color);
    rectangle.setPosition(x, y);
    canvas.draw(rectangle);

}

void SquarePen::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set square tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("square.jpg");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
}