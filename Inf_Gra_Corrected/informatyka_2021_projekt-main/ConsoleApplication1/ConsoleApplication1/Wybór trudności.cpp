#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <iostream>


int main(){
while (window.isOpen())
{
	// w kazdej iteracji petli sprawdzaj zdarzenia
	sf::Event event;
	while (window.pollEvent(event))
	{
		// jezeli odebrano zdarzenie "Closed" zamknij okno
		if (event.type == sf::Event::Closed)
			window.close();
		//jezeli nacisnieto jakikolwiek przycisk
		if (event.type == sf::Event::KeyPressed)
		{//obsluga menu z poziomu klawiszy (strzalki)
			if (event.key.code == sf::Keyboard::Up)
			{
				myDelay(250);
				menu.przesunG();
			}

			if (event.key.code == sf::Keyboard::Down)
			{
				myDelay(250);
				menu.przesunD();
			}

			if (menu_selected_flag == 3) {
				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3) {
					sf::RenderWindow window(sf::VideoMode(800, 600), "Wybór poziomów", sf::Style::Default | sf::Style::Close);
					while (window.isOpen())

					{

						// petla sprawdzajace zdarzenia 

						sf::Event event;

						while (window.pollEvent(event))

						{

							// jezeli zdarzenie zamknij - zamykamy okno 

							if (event.type == sf::Event::Closed)

								window.close();

							if (event.KeyPressed && event.key.code == Keyboard::Escape)

								window.close();

						}
					}
					window.clear(sf::Color::White);
				}
			}