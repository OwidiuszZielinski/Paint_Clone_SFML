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
    void floodFill(sf::RenderTexture& canvas_image, int x, int y, sf::Color actual, sf::Color newColor);
};