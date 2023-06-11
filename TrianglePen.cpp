#include "TrianglePen.h"

void TrianglePen::DrawToolbarIcon(sf::RenderTexture& canvas)
{
    sf::Texture iconTexture;
    iconTexture.loadFromFile("Triangle.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;
}
void TrianglePen::process(int x, int y, sf::RenderTexture& canvas)
{
    this->vertices[this->VertexNumber].position = sf::Vector2f(x, y);
    this->vertices[this->VertexNumber].color = this->color;
    this->VertexNumber++;

    while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
    }

    if (this->VertexNumber == 3)
    {
        canvas.draw(this->vertices);
        this->VertexNumber = 0;
    }
}

void TrianglePen::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set Triangle tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("Triangle.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
    this->VertexNumber = 0;
}