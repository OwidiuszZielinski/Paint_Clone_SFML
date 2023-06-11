#pragma once
#include "Tool.h"
class triangle :
    public Tool
{
public:
    triangle(int x, int y) :
        Tool(x, y) {};
    void DrawToolbarIcon(sf::RenderTexture& canvas) override;
    void process(int x, int y, sf::RenderTexture& canvas) override;
    void SetTool(sf::RenderTexture& canvas) override;

private:
    int VertexNumber = 0;
    sf::VertexArray vertices{ sf::PrimitiveType::LinesStrip, 4 };
};

