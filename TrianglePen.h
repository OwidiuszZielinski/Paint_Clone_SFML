#pragma once
#include "Tool.h"
class TrianglePen :
    public Tool
{
public:
    TrianglePen(int x, int y) :
        Tool(x, y) {};
    void DrawToolbarIcon(sf::RenderTexture& canvas) override;
    void process(int x, int y, sf::RenderTexture& canvas);
    void SetTool(sf::RenderTexture& canvas);

private:
    int VertexNumber = 0;
    sf::VertexArray vertices{ sf::PrimitiveType::Triangles, 3 };
};

