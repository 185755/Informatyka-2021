#include "Game.h"
#include "player.h"
#include "menu.h"
#include "enemy.h"


#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <iostream>

//temat gry: gra typu asteroids
//opis: w  grze poruszamy siê statkiem kosmicznym niszcz¹c asteroidy zyskujemy punkty, asteroidy które przelec¹ poni¿ej ekranu odejmuj¹ nam ¿ycie

int main()

{
	/*bool done = false;*/
	int menu_selected_flag = 0;
	bool czy_zapisal = false;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Glowne");// utworz okno
	Menu menu(window.getSize().x, window.getSize().y,&czy_zapisal);
	sf::View kamera;
	kamera.setSize(800.f, 600.f);
	kamera.setCenter(400.f, 300.f);
	window.setView(kamera);
	// petla wieczna - dopoki okno jest otwarte
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					/*myDelay(250);*/
					menu.przesunG();
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					/*myDelay(250);*/
					menu.przesunD();
				}

				if (event.key.code == sf::Keyboard::Escape)
				{
					kamera.setCenter(400.f, 300.f);
					window.setView(kamera);
				}

				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 0)
				{

					std::srand(static_cast<unsigned>(time(NULL)));
					game game(&czy_zapisal);
					while (game.running() && !game.getEndGame())// wykrzyknik oznacza ¿e zwracana jest wartoœæ (false)
					{
						game.update();


						
						

						game.render();

						/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
						{
							game.stop();
						*/

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
						{
							game.start();
						}
					}

				}

				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1)
				{
					kamera.setCenter(1200.f, 300.f);
					window.setView(kamera);
				}
				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2)
				{
					std::cout << "Koniec gry" << std::endl;
					window.close();
					sf::RenderWindow window(sf::VideoMode(800, 600), "Koniec gry");
				}

				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3)
				{
					
					game game(&czy_zapisal);
					game.getTrudny();
					while (game.running() && !game.getEndGame())// wykrzyknik oznacza ¿e zwracana jest wartoœæ (false)
					{
						
						game.update();






						game.render();

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
						{

							game.stop();
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
						{
							game.start();
						}


					}
					
				}

			}


		}

		// wyczysc obszar rysowania
		window.clear();


		// tutaj umiesc procedury rysujace...
		// window.draw(...);
		if (menu_selected_flag == 0)
		{
			menu.draw(window);
		}


		// ostatnia czynnosc - wyswietl okno wraz zawartoscia
		window.display();
	}
	return 0;
}


