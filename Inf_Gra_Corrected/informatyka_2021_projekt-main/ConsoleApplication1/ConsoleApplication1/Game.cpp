#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "game.h"
#include "player.h"
#include "pocisk.h"
#include "enemy.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <cstdio>







void game::initTextures()
{
	this->textures["POCISK"] = new sf::Texture();
	this->textures["POCISK"]->loadFromFile("pocisk.png");
}
	
void game::initPlayer()
{
	this->Player = new player();
}
void game::initEnemies()
{
	this->enemySpawnTimerMax = 20.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	
}
//Private Funkcje
void game::initVariables()
{
	this->window = nullptr;
	//logic
	this->endGame = false;
	this->do_zapisu.health;
	this->do_zapisu.points = 0;
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->przytrzymywanieMyszki = false;
}

void game::initWindow() 
{
	this->videomode.height = 600;
	this->videomode.width = 800;
	this->window = new sf::RenderWindow(this->videomode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(165);
}

//void game::initEnemies()
//{
//	this->enemy.setPosition(15.f, 15.f);
//	this->enemy.setSize(sf::Vector2f(50.f, 50.f));
//	/*this->enemy.setFillColor(sf::Color::Cyan);*/
//	//this->enemy.setOutlineColor(sf::Color::Green);
//	//this->enemy.setOutlineThickness(10.f);
//}


//Konstruktor
game::game(bool* czy_zapisal)
{
	this->czy_zapisal = czy_zapisal;
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initFont();
	this->initText();
	this->initPlayer();
	this->initTextures();
	this->initBackground();
	this->initobrazek();
	this->initObrazekTextures();
}


//Destruktor
game::~game()
{
	delete this->window;
	delete this->Player;
	//tekstury
	
	for (auto &i : this->textures)
	{
		delete i.second;
	}
	//pociski

	for (auto *i : this->pociski)
	{
		delete i;
	}

	for (auto* i : this->enemies)
	{
		delete i;
	}
	/*this->zapis();*/
}


void game::initFont()
{
	this->font.loadFromFile("arial.ttf");
}

void game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(30);
	this->uiText.setFillColor(sf::Color::White);

}

void game::initBackground()
{
	if(!this->BackgroundTexture.loadFromFile("kosmos.jpg"));
	{
		std::cout << "error";
	}
	this->Background.setTexture(this->BackgroundTexture);
}




// Accesors
const bool game::running() const
{
	return this->window->isOpen();
}






//Public Funkcje
void game::update()
{
	
	this->pollEvents();
	/*this->Player().update(*this->window);*/

	this->updateInputGlobal();

	if (this->endGame == false && this->pomoc == false && this->pomoc2 ==false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemiesAndCombat();

		this->updatePocisk();

		this->updateInput();

		this->Player->update();
	}

	if (this->do_zapisu.health <= 0)
		this->endGame = true;

	
}


void game::updateText()
{
	std::stringstream ss;

	ss << "Punkty" << this->do_zapisu.points;
	ss << "\nZycie" << this->do_zapisu.health;

	this->uiText.setString(ss.str());
}



void game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->Player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->Player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->Player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->Player->move(0.f, 1.f);
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->Player->canAttack())
	{
		this->pociski.push_back(new pocisk(this->textures["POCISK"], 0.f, -1.f, this->Player->getPos().x + this->Player->getBounds().width/2.f, this->Player->getPos().y , 5.f));
	}

}

void game::updateInputGlobal()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		if (F1 == false)
		{
			if (this->pomoc == false)
			{
				this->pomoc = true;
				initobrazek();
				renderObrazek();

				/*obrazek->setPosition({ 300.f,300.f });*/
				//obrazek->setSize({ 300.f,300.f });
				//obrazek->setFillColor(sf::Color::Cyan);
			}
			else if (this->pomoc == true)
			{
				this->pomoc = false;
				
			}
		}
		F1 = true;
	}
	else
	{
		F1 = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (Escape == false)
		{
			if (this->pomoc2 == false)
			{
				this->pomoc2 = true;
				initobrazek2();
				renderObrazek2();				
			}
			else if (this->pomoc2 == true)
			{
				this->pomoc2 = false;
				
			}
		}
		Escape = true;
	}
	else
	{
		Escape = false;
	}
	//sf::RectangleShape;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		if (Y == false)
		{
			if (this->pomoc2 == true)
			{
				zapis();
				*czy_zapisal = true;
			}
		}
		Y = true;
	}
	else
	{
		Y = false;
	}
		

}



void game::updatePocisk()
{
	
	unsigned counter = 0;
	for (auto* pocisk : this->pociski)
	{
		pocisk->update();

		if (pocisk->getBounds().top + pocisk->getBounds().height < 0.f)
		{
			delete this->pociski.at(counter);
			this->pociski.erase(this->pociski.begin() + counter);
			--counter;
		}

		++counter;
	}

}

void game::updateEnemiesAndCombat()
{
	this->enemySpawnTimer += 0.5f;
	if (this->enemySpawnTimer >= this->enemySpawnTimerMax) 
	{
		if(trudny == false){ this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f, 2.f)); }
		else if(trudny == true){ this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f, 5.f)); }
		this->enemySpawnTimer = 0.f;
	}


	for (int i = 0; i<this->enemies.size(); i++)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();
		for (size_t k = 0; k < this->pociski.size() && !enemy_removed; k++)
		{
			if (this->pociski[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->pociski.erase(this -> pociski.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);
				this->do_zapisu.points  += 1.f;
				enemy_removed = true;
			}
		}

		if (!enemy_removed)
		{
			if (this->enemies[i]->getBounds().top > this->window->getSize().y)
			{
				this->enemies.erase(this->enemies.begin() + i);
				this->do_zapisu.health -= 1.f;
				enemy_removed = true;
			}
		}

	}
		
}

void game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}



//void game::renderEnemies(sf::RenderTarget& target)
//{
//	for (auto& e : this->enemies)
//	{
//		target.draw(e);
//	}
//}


const bool game::getEndGame() const
{
	return this->endGame;
}



//void game::spawnEnemy()
//{
//	this->enemy.setPosition(
//		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize( ).x)),0.f);
//
//	//Typy enemy
//	int type = rand() % 6;
//	switch (type)
//	{
//	case 0:
//		this->enemy.setSize(sf::Vector2f(10.f, 10.f));
//		this->enemy.setFillColor(sf::Color::Green);
//	case 1:
//		this->enemy.setSize(sf::Vector2f(20.f, 20.f));
//		this->enemy.setFillColor(sf::Color::Blue);
//		break;
//	case 2:
//		this->enemy.setSize(sf::Vector2f(30.f, 30.f));
//		this->enemy.setFillColor(sf::Color::Yellow);
//		break;
//	case 3:
//		this->enemy.setSize(sf::Vector2f(40.f, 40.f));
//		this->enemy.setFillColor(sf::Color::White);
//		break;
//	case 4:
//		this->enemy.setSize(sf::Vector2f(50.f, 50.f));
//		this->enemy.setFillColor(sf::Color::Cyan);
//		break;
//	default:
//		this->enemy.setSize(sf::Vector2f(60.f, 60.f));
//		this->enemy.setFillColor(sf::Color::Magenta);
//		break;
//	}
//	//spawn
//	/*this->enemy.setFillColor(sf::Color::Green);*/
//	this->enemies.push_back(this->enemy);
//}

//void game::updateEnemies()
//{
//	
//	
//	if (this->enemies.size() < this->maxEnemies)
//	{
//		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
//		{
//			//spawn i reset
//			this->spawnEnemy();
//			this->enemySpawnTimer = 0.f;
//		}
//		else
//			this->enemySpawnTimer += 1.f;
//	}
//	
//	for (int i = 0; i < this->enemies.size(); i++)
//	{
//		bool deleted = false;
//
//		this->enemies[i].move(0.f, 1.f);
//
//		if (this->enemies[i].getPosition().y > this->window->getSize().y)
//		{
//			this->enemies.erase(this->enemies.begin() + i);
//			this->health -= 1;
//			std::cout << "Health: " << this->health << "\n";
//		}
//	}
//	
//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//	{
//		if (this->przytrzymywanieMyszki == false)
//		{
//			this->przytrzymywanieMyszki = true;
//			bool deleted = false;
//			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
//			{
//				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
//				{
//
//
//					//punkty
//					if (this->enemies[i].getFillColor() == sf::Color::Blue) 
//					{
//						this->points += 5;
//						this->health += 1;
//					}
//					else if (this->enemies[i].getFillColor() == sf::Color::Yellow) 
//					{
//						this->points += 4;
//						this->health += 1;
//					}
//					else if (this->enemies[i].getFillColor() == sf::Color::White)
//					{
//						this->points += 3;
//						this->health += 0;
//					}
//					else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
//					{
//						this->points += 1;
//						this->health += 0;
//					}
//					else if (this->enemies[i].getFillColor() == sf::Color::Magenta)
//					{
//						this->points += 0;
//						this->health += 0;
//					}
//					std::cout << "Points: " << this->points << "\n";
//					std::cout << "Health: " << this->health << "\n";
//
//
//					deleted = true;
//					this->enemies.erase(this->enemies.begin() + i);
//
//				}
//			}
//		}
//	}
//	else
//	{
//		this->przytrzymywanieMyszki = false;
//	}
//
//
//	//usuwanie (enemy) poni¿ej ekrenu
//
//}


//void game::updateEnemyCollision(const sf::RenderTarget* target)
//{
//	//for (size_t i = 0; i < this->enemies.size(); i++)
//	//{
//	//	if (this->player.getShape().getGlobalBounds().intersects(this->enemies.size()))
//	//	{
//
//	//	}
//	//}
//	
//}



void game::zapis()
{
	std::fstream plik;
	plik.open("wyniki.txt", std::ios::app | std::ios::binary);
	if (plik.good() == true)
	{
		plik.write((char*)&do_zapisu, sizeof(wynik_i_zycie));
	}
	else
	{
		std::cout << "Problem z plikiem" << std::endl;
	}
	plik.close();
}

void game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		// jezeli odebrano zdarzenie "Closed" zamknij okno
		if (ev.type == sf::Event::Closed)
			this->window->close();
	}
}

void game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this-> mousePosWindow);


	/*std::cout << "pozycja myszki: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";*/
}


void game::initobrazek()
{
	if (!this->obrazekTex.loadFromFile("escape.png"));
	{
		std::cout << "error";
	}
	this->obrazek.setTexture(this->obrazekTex);
}

void game::initObrazekTextures()
{
	this->obrazekTextures["OBRAZEK"] = new sf::Texture();
	this->obrazekTextures["OBRAZEK"]->loadFromFile("escape.png");
}

void game::initobrazek2()
{
	if (!this->obrazekTex2.loadFromFile("f1.png"));
	{
		std::cout << "error";
	}
	this->obrazek2.setTexture(this->obrazekTex2);
}

void game::initObrazekTextures2()
{
	this->obrazekTextures2["OBRAZEK2"] = new sf::Texture();
	this->obrazekTextures2["OBRAZEK2"]->loadFromFile("f1.png");
}



void game::renderObrazek()
{
	this->window->draw(this->obrazek);
}

void game::renderObrazek2()
{
	this->window->draw(this->obrazek2);
}

void game::renderBackground()
{
	this->window->draw(this->Background);
}

void game::render()
{

	
	this->window->clear(sf::Color());
	this->renderBackground();
	this->Player->render(this->window);
	
	/*this->window->draw(this->enemy);*/
	/*this->renderEnemies(*this->window);*/


	this->renderText(*this->window);
	
	for (auto *pocisk : this->pociski)
	{
		pocisk->render(this->window);

	}

	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);

	}

	if (pomoc == true)
	{
		this->renderObrazek();
	}

	if (pomoc2 == true)
	{
		this->renderObrazek2();
	}

	this->window->display();
}

void game::stop()
{
	this->Player->playerStop();
	this->enemy->enemyStop();
	
}

void game::start()
{
	this->Player->playerStart();

}

