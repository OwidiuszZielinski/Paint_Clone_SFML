#pragma once
#include "Tool.h"
#include <SFML/Graphics.hpp>

class EraserTool :
    public Tool
{
public:
    EraserTool(int x, int y) :
        Tool(x, y) {};
    void DrawToolbarIcon(sf::RenderTexture& canvas) override;
    void process(int x, int y, sf::RenderTexture& canvas) override;
    void SetTool(sf::RenderTexture& canvas) override;
};

