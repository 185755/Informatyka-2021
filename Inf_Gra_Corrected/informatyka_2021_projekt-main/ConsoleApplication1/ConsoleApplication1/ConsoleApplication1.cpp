//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp> 
//#include <SFML/System.hpp> 
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//
//
//#include <iostream>
//
//
//
//
//
//
//
//
//int main()
//{
//	int menu_selected_flag = 0;
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML demo");// utworz okno
//	Menu menu(window.getSize().x, window.getSize().y);
//	// petla wieczna - dopoki okno jest otwarte
//	while (window.isOpen())
//	{
//		// w kazdej iteracji petli sprawdzaj zdarzenia
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			// jezeli odebrano zdarzenie "Closed" zamknij okno
//			if (event.type == sf::Event::Closed)
//				window.close();
//			//jezeli nacisnieto jakikolwiek przycisk
//			if (event.type == sf::Event::KeyPressed)
//			{//obsluga menu z poziomu klawiszy (strzalki)
//				if (event.key.code == sf::Keyboard::Up)
//				{
//				
//					menu.przesunG();
//				}
//
//				if (event.key.code == sf::Keyboard::Down)
//				{
//					
//					menu.przesunD();
//				}
//
//
//
//				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1)
//				{
//					std::cout << "Pls help me" << std::endl;
//					menu_selected_flag = 1;
//
//				}
//
//				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2)
//				{
//					std::cout << "Koniec gry" << std::endl;
//					menu_selected_flag = 1;
//					sf::RenderWindow window(sf::VideoMode(800, 600), "Koniec gry");
//				}
//				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3)
//				{
//					std::cout << "Tu będzie opis i wybor poziomów trudnosci" << std::endl;
//					menu_selected_flag = 1;
//				}
//				if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 4)
//				{
//					std::cout << "tu bedzie wybor levla" << std::endl;
//					menu_selected_flag = 1;
//				}
//
//			}
//
//
//		}
//	
//
//
//
//	// wyczysc obszar rysowania
//	window.clear();
//
//
//	// tutaj umiesc procedury rysujace...
//	// window.draw(...);
//	if (menu_selected_flag == 0)
//		menu.draw(window);
//
//	// ostatnia czynnosc - wyswietl okno wraz zawartoscia
//	window.display();
//	}
//	return 0;
//}





	