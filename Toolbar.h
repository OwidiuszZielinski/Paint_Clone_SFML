#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Tool.h"

class Toolbar
{

public:
	std::vector<Tool*> Tools;
	Toolbar();

	void DrawToolbarIcons(sf::RenderTexture& canvas);

	Tool* GetToolFromCord(int x, int y);

private:
	


};

