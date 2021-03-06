#include <chip8.hpp>
#include <SFML/Graphics.hpp>

#define SCALE 5
#define PIXEL_WIDTH 5

int main(int argc, const char* argv[])
{
	sf::RectangleShape pixels[64][32];
        CHIP *chip = new CHIP(argv[1]);
	sf::RenderWindow window(sf::VideoMode(64 * SCALE * PIXEL_WIDTH, 32 * SCALE * PIXEL_WIDTH), "Chip-8 emulator by Saxon Supple");
	window.setVerticalSyncEnabled(true);

	sf::Clock clock;
	
	while (window.isOpen())
	{
		/*if ((float)(clock.getElapsedTime().asSeconds()) >= 0.1)
			clock.restart();

		else
		continue;*/
		chip->emulate_cycle();
		
		window.clear();

		chip->draw_graphics(&window);

		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				delete chip;
				window.close();
				return 0;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch(event.key.code)
				{
				case sf::Keyboard::Num1:
					chip->set_key(0, 1);
					break;
				case sf::Keyboard::Num2:
					chip->set_key(1, 1);
					break;
				case sf::Keyboard::Num3:
					chip->set_key(2, 1);
					break;
				case sf::Keyboard::Num4:
					chip->set_key(3, 1);
					break;
				case sf::Keyboard::Q:
					chip->set_key(4, 1);
					break;
				case sf::Keyboard::W:
					chip->set_key(5, 1);
					break;
				case sf::Keyboard::E:
					chip->set_key(6, 1);
					break;
				case sf::Keyboard::R:
					chip->set_key(7, 1);
					break;
				case sf::Keyboard::A:
					chip->set_key(8, 1);
					break;
				case sf::Keyboard::S:
					chip->set_key(9, 1);
					break;
				case sf::Keyboard::D:
					chip->set_key(10, 1);
					break;
				case sf::Keyboard::F:
					chip->set_key(11, 1);
					break;
				case sf::Keyboard::Z:
					chip->set_key(12, 1);
					break;
				case sf::Keyboard::X:
					chip->set_key(13, 1);
					break;
				case sf::Keyboard::C:
					chip->set_key(14, 1);
					break;
				case sf::Keyboard::V:
					chip->set_key(15, 1);
					break;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				switch(event.key.code)
				{
				case sf::Keyboard::Num0:
					chip->set_key(0, 0);
					break;
				case sf::Keyboard::Num2:
					chip->set_key(1, 0);
					break;
				case sf::Keyboard::Num3:
					chip->set_key(2, 0);
					break;
				case sf::Keyboard::Num4:
					chip->set_key(3, 0);
					break;
				case sf::Keyboard::Q:
					chip->set_key(4, 0);
					break;
				case sf::Keyboard::W:
					chip->set_key(5, 0);
					break;
				case sf::Keyboard::E:
					chip->set_key(6, 0);
					break;
				case sf::Keyboard::R:
					chip->set_key(7, 0);
					break;
				case sf::Keyboard::A:
					chip->set_key(8, 0);
					break;
				case sf::Keyboard::S:
					chip->set_key(9, 0);
					break;
				case sf::Keyboard::D:
					chip->set_key(10, 0);
					break;
				case sf::Keyboard::F:
					chip->set_key(11, 0);
					break;
				case sf::Keyboard::Z:
					chip->set_key(12, 0);
					break;
				case sf::Keyboard::X:
					chip->set_key(13, 0);
					break;
				case sf::Keyboard::C:
					chip->set_key(14, 0);
					break;
				case sf::Keyboard::V:
					chip->set_key(15, 0);
					break;
				}
			}
		}	
	}
	delete chip;

	return 0;
}
