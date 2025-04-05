#include "pocisk.h"

pocisk::pocisk()
{
}

pocisk::pocisk(sf::Texture * texture, float dir_x, float dir_y, float pos_x, float pos_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.scale(0.08f, 0.08f);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

pocisk::~pocisk()
{

}



const sf::FloatRect pocisk::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void pocisk::update()
{
	
	this->shape.move(this->movementSpeed * this->direction);

}

void pocisk::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
