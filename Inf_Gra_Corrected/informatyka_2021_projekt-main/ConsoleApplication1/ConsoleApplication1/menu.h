
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "game.h"
#pragma once
#define MAX_LICZBA_POZIOMOW 5

using namespace sf;
class Menu
{

private:
	sf::Font font;
	sf::Text menu[MAX_LICZBA_POZIOMOW];//maksymalna liczba poziomow
	sf::Text wyniki_tekst[10];
	wynik_i_zycie wyniki[10];
	int selectedItem = 0;
	bool* czy_zapisal;


public:
	//konstruktor
	Menu(float width, float height, bool* czy_zapisal);
	
	//destruktor
	~Menu() {};
	
	
	//funcje
	void przesunG();//przesun do gory
	void przesunD();//przesun w dol
	/*void myDelay(int opoznienie);*/
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
	void draw(sf::RenderWindow& window);//rysuj menu w oknie
	void draw2(sf::RenderWindow& window);
	void odczyt();
};

