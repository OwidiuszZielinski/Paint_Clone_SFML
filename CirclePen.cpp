#include "CirclePen.h"

void CirclePen::DrawToolbarIcon(sf::RenderTexture& canvas)
{

    sf::Texture iconTexture;
    iconTexture.loadFromFile("kolo.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;

}

void CirclePen::process(int x, int y, sf::RenderTexture& canvas)
{
    std::cout << "kolo tool";
    sf::CircleShape brush(10.f);
    brush.setFillColor(this->color);
    brush.setPosition(x, y);
    canvas.draw(brush);
}

void CirclePen::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set kolo tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("kolo.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
}