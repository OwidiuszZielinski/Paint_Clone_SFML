#pragma once
#include "Tool.h"

class circle :
    public Tool
{
public:
    circle(int x, int y) :
        Tool(x, y) {};
    void DrawToolbarIcon(sf::RenderTexture& canvas) override;
    void process(int x, int y, sf::RenderTexture& canvas) override;
    void SetTool(sf::RenderTexture& canvas) override;

private:
    int centx ;
    int centy ;
    bool isCenterSet=false;
};

