#pragma once
#include "pocisk.h"
/*#include "game.h"*/ // powoduje b³¹d C2440
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	void initTexture();
	void initSprite();

	void initVariables();

public:
	player(float x = 0.f, float y= 0.f);
	virtual ~player();

	const sf::Vector2f& getPos() const;
	const sf::Sprite& getSprite() const;
	const sf::FloatRect getBounds() const;
	void move(const float dirX,const float dirY);
	void playerStop();
	void playerStart();
	const bool canAttack();

	void updateAttack();
	/*void updateWindowCollision();*/
	void update();
	void render(sf::RenderTarget* target);
};

