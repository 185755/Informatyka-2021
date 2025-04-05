#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
private:
	sf::CircleShape shape;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	


	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	
	void initShape();
	void initVariables(float speed);
	
	
public:
	
	void enemyStop();
	Enemy(float pos_x, float pos_y, float speed);
	virtual ~Enemy();

	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};
