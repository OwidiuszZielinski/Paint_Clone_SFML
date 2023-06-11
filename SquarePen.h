#pragma once
#include "Tool.h"
class SquarePen :
    public Tool
{

public:
    SquarePen(int x, int y) :
        Tool(x, y) {};
    void DrawToolbarIcon(sf::RenderTexture& canvas) override;
    void process(int x, int y, sf::RenderTexture& canvas)override;
    void SetTool(sf::RenderTexture& canvas)override;
};

