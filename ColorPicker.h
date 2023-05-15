#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <regex>


#define COLORPICKER_H




class ColorPicker {


private:
    int xSize{};
    int ySize{};
    int xPos{};
    int yPos{};
    sf::Color color;
public:
    ColorPicker() {}
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
    sf::CircleShape getRecToDrow(ColorPicker cp) {
        sf::CircleShape rs;
        rs.setRadius((float)cp.getXSize());
        rs.setFillColor(cp.getColor());
        rs.setPosition((float)cp.getXPos(), (float)cp.getYPos());
        rs.setOutlineThickness(2.f);
        rs.setOutlineColor(sf::Color::Black);
        return rs;

    }
    

    std::list<ColorPicker> initListColors() {
       std::list<ColorPicker> initList;
       initList.push_back(ColorPicker(15, 25, 600, 5, sf::Color::Black));
       initList.push_back(ColorPicker (15, 25, 640, 5, sf::Color::Color(127, 127, 127)));
       initList.push_back(ColorPicker (15, 25, 680, 5, sf::Color::Color(136, 0, 21)));
       initList.push_back(ColorPicker (15, 25, 720, 5, sf::Color::Color(237, 28, 36)));
       initList.push_back(ColorPicker (15, 25, 760, 5, sf::Color::Color(255, 127, 39)));
       initList.push_back(ColorPicker (15, 25, 600, 45, sf::Color::Color(255, 242, 0)));
       initList.push_back(ColorPicker (15, 25, 640, 45, sf::Color::Color(34, 177, 76)));
       initList.push_back(ColorPicker (15, 25, 680, 45, sf::Color::Color(0, 162, 232)));
       initList.push_back(ColorPicker (15, 25, 720, 45, sf::Color::Color(63, 72, 204)));
       initList.push_back(ColorPicker (15, 25, 760, 45, sf::Color::Color(163, 73, 164)));
       
       return initList;
    }



    void draw(sf::RenderTexture& canvas) {

        for (auto& elem : initListColors()) {
            sf::CircleShape temp = getRecToDrow(elem);
            canvas.draw(temp);
        }
        
        
       
    }



    sf::RectangleShape drawTextBox(sf::RenderTexture& canvas) {
        sf::Text t;
        sf::Font font;
        font.loadFromFile("./Montserrat-Regular.ttf");
        t.setCharacterSize(20);
        t.setFont(font);
        t.setString("hex : #FFFFFF");
        t.setPosition(sf::Vector2f(810, 5));
        t.setFillColor(sf::Color::Black);

        sf::RectangleShape clear(sf::Vector2f(160, 40));
        clear.setPosition(sf::Vector2f(810, 30));
        clear.setFillColor(sf::Color::White);
        clear.setOutlineThickness(2.f);
        clear.setOutlineColor(sf::Color::Black);
        canvas.draw(clear);
        canvas.draw(t);
        return clear;
    }
    sf::Color makeColorFromHexString(std::string hex) {
        int r = std::stoi(hex.substr(1, 2), nullptr, 16);
        int g = std::stoi(hex.substr(3, 2), nullptr, 16);
        int b = std::stoi(hex.substr(5, 2), nullptr, 16);
        sf::Color color(r, g, b);
        return color;

    }

    bool validateHexColor(const std::string& color) {
        // Utworzenie wyra¿enia regularnego do walidacji formatu koloru
        std::regex colorRegex("#[0-9a-fA-F]{6}");

        // Sprawdzenie, czy ci¹g pasuje do wzorca wyra¿enia regularnego
        return std::regex_match(color, colorRegex);
    }
    


};
