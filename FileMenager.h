#pragma once
#include <string.h>
#include <SFML/Graphics.hpp>

bool saveCanvasToFile(const std::string& filename, sf::RenderTexture& canvas) {
    sf::Image screenshot = canvas.getTexture().copyToImage();
    return screenshot.saveToFile(filename);
}

bool loadCanvasFromFile(const std::string& filename, sf::RenderTexture& canvas) {
    sf::Image image;
    if (image.loadFromFile(filename)) {
        // Poprawka: Odwrócenie wczytanego obrazu
        image.flipVertically();

        sf::Texture texture;
        texture.loadFromImage(image);
        canvas.clear();
        canvas.draw(sf::Sprite(texture));
        return true;
    }
    return false;
}
