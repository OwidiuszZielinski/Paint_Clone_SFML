#include <SFML/Graphics.hpp>


void linia(sf::RenderWindow& window,sf::CircleShape brush, sf::Event event, sf::RenderTexture& canvas, sf::Color lineColor)
{
    static bool isDrawing = false;
    static sf::Vector2f startPoint;
    sf::VertexArray line(sf::Quads, 4); // Specify the number of vertices as 4
    sf::Vector2f ms = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
    {
        startPoint = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        isDrawing = true;
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right && isDrawing)
    {
        sf::Vector2f endPoint = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        sf::Vector2f direction = endPoint - startPoint;
        sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
        sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

        float lineThickness = 10.0f; // Set the thickness of the line

        sf::Vector2f offset = (brush.getRadius() / 2.0f) * unitPerpendicular;
        
        line[0].position = startPoint + offset;
        line[1].position = endPoint + offset;
        line[2].position = endPoint - offset;
        line[3].position = startPoint - offset;



        line[0].color = lineColor;
        line[1].color = lineColor;
        line[2].color = lineColor;
        line[3].color = lineColor;

        isDrawing = false;

        if (ms.y > 100) {
            
            canvas.draw(line);
        }
         // Draw the line on the canvas
        window.clear();
        sf::Sprite canvasSprite(canvas.getTexture());
        window.draw(canvasSprite);
        window.display();
    }
}
