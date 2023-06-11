#include "Tool.h"

Tool::Tool(int x, int y)
{
	this->pozX = x;
	this->pozY = y;
}

bool Tool::isToolClicked(int x, int y)
{
    if (this->pozX < x
        && this->pozY < y
        && this->sizex + this->pozX > x
        && this->sizey + this->pozY > y)
    {
        return true;
    }
    return false;
}

void Tool::process(int x, int y, sf::RenderTexture &canvas)
{
    std::cout << "Tool";
}

void Tool::SetColor(sf::Color color)
{
    this->color = color;

}

void Tool::ClearToolbarIcon(sf::RenderTexture& canvas)
{
    sf::RectangleShape rs;
    rs.setSize(sf::Vector2f(100, 20));
    rs.setFillColor(sf::Color::White);
    rs.setPosition(0, 0);
    rs.setOutlineThickness(2.f);
    rs.setOutlineColor(sf::Color::White);
    canvas.draw(rs);
}

void Tool::DrawToolbarIcon(sf::RenderTexture& canvas)
{

    sf::RectangleShape rs;
    rs.setSize(sf::Vector2f(sizex, sizey));
    rs.setFillColor(sf::Color::White);
    rs.setPosition(this->pozX, this->pozY);
    rs.setOutlineThickness(2.f);
    rs.setOutlineColor(sf::Color::White);
    canvas.draw(rs);
}

void Tool::SetTool(sf::RenderTexture& canvas)
{
    std::cout << "Set Tool";
}
