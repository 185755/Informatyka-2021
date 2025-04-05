#pragma once
#include "pocisk.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <fstream>

struct wynik_i_zycie
{
	unsigned points;
	int health = 10;
};

class game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;
	
	std::map <std::string, sf::Texture*> obrazekTextures;
	std::map <std::string, sf::Texture*> obrazekTextures2;
	std::map <std::string, sf::Texture*> textures;

	//	POCISKI
	std::vector<pocisk*> pociski;
	//pozycja myszki
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;


	Enemy* enemy;
	player* Player;

	std::vector<Enemy*> enemies;
	
	//Ekran help i escape
	sf::Sprite obrazek;
	sf::Texture obrazekTex;

	sf::Sprite obrazek2;
	sf::Texture obrazekTex2;


	//t³o
	sf::Sprite Background;
	sf::Texture BackgroundTexture;






	//czcionka
	sf::Font font;


	// tekst
	 
	sf::Text uiText;

	

	//logic
	bool endGame;
	bool trudny = false;
	bool* czy_zapisal;




	bool pomoc = false; // czy widaæ ekran pomocy;
	bool F1 = false;
	bool Y = false;

	bool pomoc2 = false;
	bool Escape = false;

	wynik_i_zycie do_zapisu;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool przytrzymywanieMyszki;

	

	// obiekty
	/*std::vector<sf::RectangleShape> enemies;*/
	

	


	

	// Funkcje
	void initVariables();
	void initWindow();
	/*void initEnemies();*/
	void initFont();
	void initText();
	void initBackground();
	void initobrazek();
	void initObrazekTextures();
	void initobrazek2();
	void initObrazekTextures2();
	void initTextures();
	void initPlayer();
	void initEnemies();
	


public:
	//konstruktory/ destruktory
	game(bool* czy_zapisal);
	virtual ~game();
	

	const bool running() const;
	const bool getEndGame() const;
	
	//Funkcje
	
	//void spawnEnemy();
	void zapis();
	void pollEvents();
	void updateMousePositions();
	void getTrudny() {trudny = true; }
	/*void updateEnemies();*/
	/*void updateEnemyCollision(const sf::RenderTarget* target);*/
	//UPDATE
	void stop();
	void start();
	void update();
	void updatePocisk();
	void updateEnemiesAndCombat();
	void updateText();
	void updateInput();
	void updateInputGlobal();
	
	//RENDER
	void renderText(sf::RenderTarget& target);// pozwala na renderowanie tekstu w innych oknach
	/*void renderEnemies(sf::RenderTarget& target);*/
	void renderObrazek2();
	void renderObrazek();

	void renderBackground();
	void render();
};
