#pragma once


#include<iostream>
#include <SFML/System.hpp> 
#include <SFML/Graphics.hpp>


class pocisk
{private:
	
	sf::Sprite shape;

	/*sf::Texture* texture;*/
	sf::Vector2f direction;

	float movementSpeed;
public:
	pocisk();
	pocisk(sf::Texture* texture, float dir_x, float dir_y, float pos_x, float pos_y , float movement_speed);
	virtual ~pocisk();
	
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);

};

