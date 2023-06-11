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
    void drawPlusIcon(sf::RenderTexture& canvas, sf::Font font, int x, int y) {

        sf::Text test("\U0000002B", font, 86);
        test.setPosition(x, y);
        test.setFillColor(sf::Color::Black);
        canvas.draw(test);

    }
    void drawMinusIcon(sf::RenderTexture& canvas, sf::Font font, int x, int y) {

        sf::Text test("\u002D", font, 86);
        test.setPosition(x, y);
        test.setFillColor(sf::Color::Black);
        canvas.draw(test);

    }
    void drawPngButton(sf::RenderTexture& canvas, sf::Font font, int x, int y) {
        sf::RectangleShape button(sf::Vector2f(150, 30));

        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(2.0f);
        button.setOutlineColor(sf::Color::Black);
        button.setPosition(x, y);
        sf::Text buttonText("Save as PNG", font, 16);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setPosition(button.getPosition().x + button.getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
        button.getPosition().y + button.getSize().y / 2 - buttonText.getGlobalBounds().height / 2);

        canvas.draw(button);
        canvas.draw(buttonText);
    }
    void drawJpgButton(sf::RenderTexture& canvas, sf::Font font, int x, int y) {
        sf::RectangleShape button(sf::Vector2f(150, 30));
 
        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(2.0f);
        button.setOutlineColor(sf::Color::Black);
        button.setPosition(x, y);
        button.setFillColor(sf::Color::White);
        sf::Text buttonText("Save as JPEG", font, 16);

        buttonText.setFillColor(sf::Color::Black);
        buttonText.setPosition(button.getPosition().x + button.getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
        button.getPosition().y + button.getSize().y / 2 - buttonText.getGlobalBounds().height / 2);

        canvas.draw(button);
        canvas.draw(buttonText);
    }
    void drawLoadJpgButton(sf::RenderTexture& canvas, sf::Font font, int x, int y) {
        sf::RectangleShape button(sf::Vector2f(150, 30));

        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(2.0f);
        button.setOutlineColor(sf::Color::Black);
        button.setPosition(x, y);
        button.setFillColor(sf::Color::White);
        sf::Text buttonText("Load a JPEG", font, 16);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setPosition(button.getPosition().x + button.getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
        button.getPosition().y + button.getSize().y / 2 - buttonText.getGlobalBounds().height / 2);

        canvas.draw(button);
        canvas.draw(buttonText);
    }
    void drawLoadPngButton(sf::RenderTexture& canvas, sf::Font font, int x, int y) {
        sf::RectangleShape button(sf::Vector2f(150, 30));

        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(2.0f);
        button.setOutlineColor(sf::Color::Black);
        button.setPosition(x, y);
        sf::Text buttonText("Load a PNG", font, 16);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setPosition(button.getPosition().x + button.getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
        button.getPosition().y + button.getSize().y / 2 - buttonText.getGlobalBounds().height / 2);

        canvas.draw(button);
        canvas.draw(buttonText);
    }
    
    void drawFillUpIcon(sf::RenderTexture& canvas, sf::Font font, int x, int y) {
            sf::Texture iconTexture;
            iconTexture.loadFromFile("fill.jpg");
            sf::Sprite icon;
            icon.setTexture(iconTexture);
            icon.setPosition(x, y);
            icon.setScale(0.15f, 0.15f);
            canvas.draw(icon);
        

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
