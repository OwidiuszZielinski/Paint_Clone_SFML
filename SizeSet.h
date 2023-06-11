#pragma once
#include "Tool.h"
#include <SFML/Graphics.hpp>

class SizeSet :
    public Tool
{
public:
    SizeSet(int x, int y) :
        Tool(x, y) {};
    void DrawToolbarIcon(sf::RenderTexture& canvas);
};