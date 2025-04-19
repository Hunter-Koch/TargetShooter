#pragma once
#ifndef OBJ
#define OBJ

#include "miscFunctions.hpp"
#include <string>
#include <SFML/Graphics.hpp>

class GameObject// : public sf::Sprite
{
public:
	virtual void update() = 0;
};

#endif 