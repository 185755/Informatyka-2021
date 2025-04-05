#include "player.h"
#include "game.h"
#include "pocisk.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>



void player::initTexture()
{
	if(!this->texture.loadFromFile("pokeball.png"));
	{
		std::cout << "nie dzia³a";
	}

}

void player::initSprite()
{
	this->sprite.setTexture(this->texture);
}

void player::initVariables()
{
	this->movementSpeed = 2.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->sprite.setPosition(200.f, 200.f);
}


player::player(float x, float y)
{
	
	
	this->initVariables();
	this->initTexture();
	this->initSprite();
	
}
player::~player()
{

}

const sf::Vector2f& player::getPos() const
{
	return this->sprite.getPosition();	
}

const sf::Sprite& player::getSprite() const
{
	return this->sprite;
}

const sf::FloatRect player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}



const bool player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}



void player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.3f;
}

//void player::updateWindowCollision(const sf::RenderTarget* target)
//{
//
//	//lewo
//	if (this->sprite.getGlobalBounds().left <= 0.f)
//		this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
//	//prawo
//	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
//		this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
//	//góra
//	if (this->sprite.getGlobalBounds().top <= 0.f)
//		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
//	//dó³
//	if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
//		this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
//}





void player::update()
{
	
	/*this->updateWindowCollision(target);*/
	this->updateAttack();
}

void player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}


void player::playerStop()
{
	/*this->movementSpeed = 0.f;*/
}

void player::playerStart()
{
	/*this->movementSpeed = 2.f;*/
}
