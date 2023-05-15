
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>


#define CURRENTPICK_H


class CurrentPick {

private:
        int xSize;
        int ySize;
        int xPos;
        int yPos;
        sf::Color color;
public:
    CurrentPick() {
        this->xSize = 30;
        this->ySize = 25;
        this->xPos = 520;
        this->yPos = 12;
        this->color = sf::Color::White;
    }
    

    sf::Color getColor() const {
        return color;
    }

    void setColor(sf::Color color) {
        this->color = color;
    }

    sf::CircleShape getRecToDrow() {
        sf::CircleShape rs;
        rs.setRadius(this->xSize);
        rs.setFillColor(this->color);
        rs.setPosition(this->xPos, this->yPos);
        rs.setOutlineThickness(2.f);
        rs.setOutlineColor(sf::Color::Black);
        return rs;

    }
    void draw(sf::RenderTexture& canvas) {

        sf::CircleShape cs = getRecToDrow();
        canvas.draw(cs);


    }

};
