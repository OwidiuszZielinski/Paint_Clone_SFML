#include "square.h"
void square::DrawToolbarIcon(sf::RenderTexture& canvas)
{

    sf::Texture iconTexture;
    iconTexture.loadFromFile("square2.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;

}
void square::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set square2 tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("square2.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
}
void square::process(int x, int y, sf::RenderTexture& canvas)
{
    if (isCenterSet == false)
    {
        this->centx = x;
        this->centy = y;
        this->isCenterSet = true;

        while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        }

    }
    else
    {
        float r, a, c;
        a = y - centy;
        c = x - centx;
        r = sqrt((a * a) + (c * c));
        sf::RectangleShape brush(sf::Vector2f(centx, centy));
        brush.setOutlineColor(this->color);
        brush.setFillColor(sf::Color::Transparent);
        brush.setOutlineThickness(10.f);
        brush.setSize(sf::Vector2f(r, r));
        brush.setPosition(centx, centy);
        brush.setRotation( atan2(y - centy, x - centx) * 180 / 3.141592);
        canvas.draw(brush);
        this->isCenterSet = false;

    }
}