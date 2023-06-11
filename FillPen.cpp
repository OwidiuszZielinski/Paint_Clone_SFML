#include "FillPen.h"
#include <stack>
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


void FillPen::floodFill(sf::RenderTexture &canvas_image, int x,int y, sf::Color actual,sf::Color newColor)
    {
   
    }
    



void FillPen::process(int x, int y, sf::RenderTexture& canvas)
{
    sf::Image image = canvas.getTexture().copyToImage();
    sf::Vector2u textureSize = image.getSize();
    sf::Color targetColor = canvas.getTexture().copyToImage().getPixel(x, y);
    sf::CircleShape brush(1.0f);

    brush.setFillColor(this->color);

    for (int i = x; i < textureSize.x; i++) {
        brush.setPosition(i, y);
        canvas.draw(brush);
    }

    for (int i = x; i >= 0; i--) {
        brush.setPosition(i, y);
        canvas.draw(brush);
    }

    for (int j = y; j < textureSize.y; j++) {
        brush.setPosition(x, j);
        canvas.draw(brush);
    }

    for (int j = y; j >= 100; j--) {
        brush.setPosition(x, j);
        canvas.draw(brush);
    }
}

void FillPen::SetTool(sf::RenderTexture& canvas)
{
    
   

   

}