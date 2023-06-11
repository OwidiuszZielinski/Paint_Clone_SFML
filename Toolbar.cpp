#include "Toolbar.h"

Toolbar::Toolbar()
{

}

void Toolbar::DrawToolbarIcons(sf::RenderTexture& canvas)
{
    for (auto& tool : Tools) {
        tool->DrawToolbarIcon(canvas);
    }

    //canvas.display();
}
Tool* Toolbar::GetToolFromCord(int x, int y)
{
    for (auto& tool : Tools)
    {
        //tool->isToolClicked(x, y);
        if (tool->pozX + tool->sizex > x
            && tool->pozX < x
            && tool->pozY < y 
            && tool->sizey + tool->pozY > y)
        {
            return tool;
         }
    }
    return nullptr;
}
