#pragma once
#include "Tool.h"
class FillPen :
public Tool
{

public:
    FillPen(int x, int y) :
        Tool(x, y) {};
    
    void DrawToolbarIcon(sf::RenderTexture& canvas) override;
    void process(int x, int y, sf::RenderTexture& canvas)override;
    void SetTool(sf::RenderTexture& canvas)override;
    void floodFill(sf::Image& image, const sf::Vector2i& seedPos,  const sf::Color& fillColor);
};