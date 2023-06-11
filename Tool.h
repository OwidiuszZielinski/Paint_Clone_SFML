#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Tool
{
public:
	int pozX;
	int pozY;
	int sizex = 10;
	int sizey = 10;
	sf::Color color;

	Tool(int x, int y);
	bool isToolClicked(int x, int y);
	virtual void process(int x, int y, sf::RenderTexture& canvas);
	void SetColor(sf::Color color);
	void ClearToolbarIcon(sf::RenderTexture& canvas);
	virtual void DrawToolbarIcon(sf::RenderTexture& canvas);
	virtual void SetTool(sf::RenderTexture& canvas);

};

