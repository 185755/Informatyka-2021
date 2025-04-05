
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "menu.h"
#include "Game.h"
#define MAX_LICZBA_POZIOMOW 5
using namespace sf;

Menu::Menu(float width, float height, bool* czy_zapisal)
{	
	this->czy_zapisal = czy_zapisal;
	//laduj czcionke
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	//rysowanie elementow menu
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("Nowa gra");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 1));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].setString("Zapisane wyniki");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Red);
	menu[2].setString("Wyjscie");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 3));
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Red);
	menu[3].setString("Tryb Trudny");
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 4));

	odczyt();
	for (int i = 0; i < 10; i++)
	{
		wyniki_tekst[i].setFont(font);
		wyniki_tekst[i].setFillColor(sf::Color::Green);
		wyniki_tekst[i].setString("Wynik: "+std::to_string(wyniki[i].points) + L" ¯ycia: " + std::to_string(wyniki[i].health));
		wyniki_tekst[i].setPosition(830.f,50.f+50.f*i);
	}

}

//rysowanie menu w biezacym oknie
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		window.draw(menu[i]);
	}

	if (*czy_zapisal == true)
	{
		std::cout << "jazda";
		odczyt();
		*czy_zapisal = false;
	}

	for (int i = 0; i < 10; i++)
	{
		wyniki_tekst[i].setString("Wynik: " + std::to_string(wyniki[i].points)+ L" ¯ycia: " + std::to_string(wyniki[i].health));
		window.draw(wyniki_tekst[i]);
	}
}

void Menu::draw2(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::przesunG()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = MAX_LICZBA_POZIOMOW - 1;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}


}



void Menu::przesunD()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= MAX_LICZBA_POZIOMOW)
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}

}

void Menu::odczyt()
{
	
	std::fstream plik;
	plik.open("wyniki.txt", std::ios::in | std::ios::binary);
	if (plik.good() == true)
	{
		for (int i = 0; i < 10; i++)
		{
			plik.read((char*)&wyniki[i], sizeof(wynik_i_zycie));
		}
	}
	else
	{
		std::cout << "Problem z plikiem" << std::endl;
	}
	plik.close();
	
}

//funkcja opozniajaca
//void Menu::myDelay(int opoznienie)
//{
//	sf::Clock zegar;
//	sf::Time czas;
//	while (1)
//	{
//		czas = zegar.getElapsedTime();
//		if (czas.asMilliseconds() > opoznienie)
//		{
//			zegar.restart();
//			break;
//		}
//			
//	}	
//}