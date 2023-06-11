#include "EraserTool.h"

void EraserTool::DrawToolbarIcon(sf::RenderTexture& canvas) 
{    
    sf::Texture iconTexture;
    iconTexture.loadFromFile("eraser.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(this->pozX, this->pozY);
    canvas.draw(icon);
    this->sizex = iconTexture.getSize().x;
    this->sizey = iconTexture.getSize().y;
}

void EraserTool::process(int x, int y, sf::RenderTexture& canvas)
{
    std::cout << "eraser tool";
    sf::CircleShape brush(10.f);
    brush.setFillColor(sf::Color::White);
    brush.setPosition(x, y);
    canvas.draw(brush);
}

void EraserTool::SetTool(sf::RenderTexture& canvas)
{
    this->ClearToolbarIcon(canvas);
    std::cout << "set eraser tool";

    sf::Texture iconTexture;
    iconTexture.loadFromFile("eraser.png");
    sf::Sprite icon;
    icon.setTexture(iconTexture);
    icon.setPosition(60, 0);
    canvas.draw(icon);
}
