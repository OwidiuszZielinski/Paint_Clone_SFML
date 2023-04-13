#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>




class ColorPicker {


private:
    int xSize;
    int ySize;
    int xPos;
    int yPos;
    sf::Color color;
public:
    ColorPicker(int xSize, int ySize,int xPos,int yPos, sf::Color color) {
        this->xSize = xSize;
        this->ySize = ySize;
        this->xPos = xPos;
        this->yPos = yPos;
        this->color = color;
    }

    int getXSize() const {
        return xSize;
    }
    int getXPos() const {
        return xPos;
    }

    void setXSize(int x) {
        this->xSize = x;
    }
    void setXPos(int x) {
        this->xPos = x;
    }

    int getYSize() const {
        return ySize;
    }
    int getYPos() const {
        return yPos;
    }

    void setYSize(int y) {
        this->ySize = y;
    }
    void setYPos(int y) {
        this->yPos = y;
    }

    sf::Color getColor() const {
        return color;
    }

    void setColor(sf::Color color) {
        this->color = color;
    }
    

};
