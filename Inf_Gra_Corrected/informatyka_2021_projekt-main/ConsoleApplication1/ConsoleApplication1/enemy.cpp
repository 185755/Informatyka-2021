#include "enemy.h"

void Enemy::initShape()
{
	this->shape.setRadius(rand()%20 + 20);
	this->shape.setPointCount(rand() % 10 + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));

}

void Enemy::initVariables(float speed)
{
	this->type = 0;
	this->speed = speed;
	this->hp = 0;
	this->hpMax = 3;
	this->damage = 1;
	this->points = 5;

}



Enemy::Enemy(float pos_x, float pos_y, float speed)
{
	this->initShape();
	this->initVariables(speed);
	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}




//Funkcje public
void Enemy::update()
{
	this->shape.move(0.f, this->speed);

}

//void Enemy::move()
//{
//	/*this->sprite.move(this->movementpeed * dirX, this->speed * dirY);*/
//}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Enemy::enemyStop()
{
	/*this->speed= 0.f;*/
}