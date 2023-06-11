#include "triangle.h"
void triangle::DrawToolbarIcon(sf::RenderTexture& canvas)
{

    sf::Texture iconTexture;
    iconTexture.loadFromFile("triangle.jpg");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;

}
void triangle::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set triangle tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("triangle.jpg");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
}
void triangle::process(int x, int y, sf::RenderTexture& canvas)
{
    this->vertices[this->VertexNumber].position = sf::Vector2f(x, y);
    this->vertices[this->VertexNumber].color = this->color;
    this->VertexNumber++;
 
    while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
    }

    if (this->VertexNumber == 3)
    {
        this->vertices[this->VertexNumber] = this->vertices[0];
        canvas.draw(this->vertices, sf::RenderStates());
        this->VertexNumber = 0;
    }
}