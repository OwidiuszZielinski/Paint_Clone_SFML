#include "circle.h"

void circle::DrawToolbarIcon(sf::RenderTexture& canvas)
{

    sf::Texture iconTexture;
    iconTexture.loadFromFile("cirklo.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;

}
void circle::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set cirklo tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("cirklo.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
}
void circle::process(int x, int y, sf::RenderTexture& canvas)
{
    if (isCenterSet == false)
    {
        this->centx = x;
        this->centy = y;
        this->isCenterSet = true;
        
        while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        { }

    }
    else
    {
        float r, a, c;
        a = y - centy;
        c = x - centx;
        r = sqrt((a * a) + (c * c));
        
            sf::CircleShape brush(r);
            brush.setOutlineColor(this->color);
            brush.setFillColor(sf::Color::Transparent);
            brush.setOutlineThickness(10.f);
            brush.setPosition(centx - r, centy - r);
           
                canvas.draw(brush);
           
            this->isCenterSet = false;
        
    }
}