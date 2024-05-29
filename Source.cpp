#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "windows.h"
#include <ctime>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(500, 800), L"Новый проект", Style::Default);
	Image fon;
	fon.loadFromFile("C:/Users/dima-/Desktop/pictures/fon1.png");
	Texture fontexture;//создаем объект Texture (текстура)
	fontexture.loadFromImage(fon);//передаем в него объект Image (изображения)
	Sprite herosprite;//создаем объект Sprite(спрайт)
	herosprite.setTexture(fontexture);//передаём в него объект Texture (текстуры)
	herosprite.setPosition(0, 0);//задаем начальные координаты появления спрайта
	//циферки
	Image one;
	one.loadFromFile("C:/Users/dima-/Desktop/pictures/1.png");
	Texture onet;//создаем объект Texture (текстура)
	onet.loadFromImage(one);//передаем в него объект Image (изображения)
	Sprite ones;//создаем объект Sprite(спрайт)
	ones.setTexture(onet);//передаём в него объект Texture (текстуры)
	ones.setPosition(60, 60);//задаем начальные координаты появления спрайта
	Image two;
	two.loadFromFile("C:/Users/dima-/Desktop/pictures/2.png");
	Texture twot;//создаем объект Texture (текстура)
	twot.loadFromImage(two);//передаем в него объект Image (изображения)
	Sprite twos;//создаем объект Sprite(спрайт)
	twos.setTexture(twot);//передаём в него объект Texture (текстуры)
	twos.setPosition(270, 60);//задаем начальные координаты появления спрайта
	Image three;
	three.loadFromFile("C:/Users/dima-/Desktop/pictures/3.png");
	Texture threet;//создаем объект Texture (текстура)
	threet.loadFromImage(three);//передаем в него объект Image (изображения)
	Sprite threes;//создаем объект Sprite(спрайт)
	threes.setTexture(threet);//передаём в него объект Texture (текстуры)
	threes.setPosition(60, 220);//задаем начальные координаты появления спрайта
	Image four;
	four.loadFromFile("C:/Users/dima-/Desktop/pictures/4.png");
	Texture fourt;//создаем объект Texture (текстура)
	fourt.loadFromImage(four);//передаем в него объект Image (изображения)
	Sprite fours;//создаем объект Sprite(спрайт)
	fours.setTexture(fourt);//передаём в него объект Texture (текстуры)
	fours.setPosition(270, 220);//задаем начальные координаты появления спрайта
	Image amnom;
	amnom.loadFromFile("C:/Users/dima-/Desktop/pictures/amnomt.png");
	Texture amnomt;
	amnomt.loadFromImage(amnom);
	Sprite amnoms;
	amnoms.setTexture(amnomt);//передаём в него объект Texture (текстуры)
	amnoms.setPosition(150, 600);//задаем начальные координаты появления спрайта

	Image win;
	win.loadFromFile("C:/Users/dima-/Desktop/pictures/win.png");
	Texture wint;
	wint.loadFromImage(win);
	Sprite wins;
	wins.setTexture(wint);//передаём в него объект Texture (текстуры)
	wins.setPosition(-1000, -200);//задаем начальные координаты появления спрайта
	//конфета
	Image candy;
	candy.loadFromFile("C:/Users/dima-/Desktop/pictures/candy.png");
	Texture candyt;
	candyt.loadFromImage(candy);
	Sprite candys;
	candys.setTexture(candyt);//передаём в него объект Texture (текстуры)
	candys.setPosition(-150, -210);//задаем начальные координаты появления спрайта
	Image baloon;
	baloon.loadFromFile("C:/Users/dima-/Desktop/pictures/baloont.png");
	Texture baloont;
	baloont.loadFromImage(baloon);
	Sprite baloons;
	baloons.setTexture(baloont);//передаём в него объект Texture (текстуры)
	baloons.setPosition(-150, -210);//задаем начальные координаты появления спрайта
	//веревка
	RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(3, 200));
	rectangle.setPosition(sf::Vector2f(-10, -10));
	rectangle.setFillColor(sf::Color::Black);
	int level = 0, choose, rope = 0;
	float fallSpeed = 500.0f;
	Clock clock;
	float dtSeconds = 0.0f;
	int wait = 0;
	while (window.isOpen())
	{
		std::cout << level<<std::endl;
		//sf::Time deltaTime = clock.restart();
		dtSeconds = clock.restart().asSeconds();
		//sf::Time deltaTime = clock.restart();
		//float dtSeconds = deltaTime.asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(herosprite);
		window.draw(ones);
		window.draw(twos);
		window.draw(threes);
		window.draw(fours);
		window.draw(rectangle);
		window.draw(candys);
		window.draw(baloons);
		window.draw(amnoms);
		window.draw(wins);
		bool win = true;

		if (level == 0) {
			ones.setPosition(60, 60);
			twos.setPosition(270, 60);
			threes.setPosition(60, 220);
			fours.setPosition(270, 220);
			candys.setPosition(-150, -210);
			if (IntRect(60, 60, 120, 120).contains(Mouse::getPosition(window))) {
				ones.setColor(Color::Green);
				if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					level = 1;
					rope = 1;
				}
			}
			else {
				ones.setColor(Color::Red);
			}
			if (IntRect(270, 60, 120, 120).contains(Mouse::getPosition(window))) {
				twos.setColor(Color::Green);
				if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					level = 2;
					rope = 1;
				}
			}
			else {
				twos.setColor(Color::Red);
			}
			if (IntRect(60, 220, 120, 120).contains(Mouse::getPosition(window))) {
				threes.setColor(Color::Green);
				if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					level = 3;
					rope = 1;
				}
			}
			else {
				threes.setColor(Color::Red);

			}
			if (IntRect(270, 220, 120, 120).contains(Mouse::getPosition(window)) && rope==0) {
				fours.setColor(Color::Green);
				Sleep(50);
				if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					level = 4;
					rope = 1;
				}
			}
			else {
				fours.setColor(Color::Red);
			}
		}
		//amnoms.setPosition(sf::Vector2f(-1000.f, -1000.f));
		choose = level;
		if (choose == 1) {
			ones.setPosition(sf::Vector2f(-1000.f, -1000.f));
			twos.setPosition(sf::Vector2f(-1000.f, -1000.f));
			threes.setPosition(sf::Vector2f(-1000.f, -1000.f));
			fours.setPosition(sf::Vector2f(-1000.f, -1000.f));
			rectangle.setPosition(sf::Vector2f(240, 0));
			if (rope == 1)
				candys.setPosition(190, 190);
			if (IntRect(240, 0, 5, 200).contains(Mouse::getPosition(window))) {
				rectangle.setFillColor(Color(255, 255, 255));
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left && rope == 1) {
					rope = 0;
				}
			}
			else {
				if (rope == 1)
					rectangle.setFillColor(Color::Black);
			}
			sf::Vector2f spritePos = candys.getPosition();
			if (rope == 0) {
				if (spritePos.y < 1000 && spritePos.y < 650) {
					rectangle.setFillColor(Color(255, 255, 255, 0));
					//напиши сюда падение
					spritePos.y = spritePos.y + fallSpeed * dtSeconds;
					candys.setPosition(spritePos.x, spritePos.y);
					//dtSeconds = clock.restart().asSeconds();			
				}
				if (spritePos.y > 650) {
					wins.setPosition(10, 200);
					if (IntRect(10, 200, 400, 300).contains(Mouse::getPosition(window))) {
						wins.setColor(Color::Green);
						if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
							wins.setPosition(-10, -400);
							//Sleep(500);
							level = 0;
							choose = 0;			
						}
					}
					else {
						wins.setColor(Color::Red);
					}
				}

			}


		}
		if (choose == 2) {
			ones.setPosition(sf::Vector2f(-1000.f, -1000.f));
			twos.setPosition(sf::Vector2f(-1000.f, -1000.f));
			threes.setPosition(sf::Vector2f(-1000.f, -1000.f));
			fours.setPosition(sf::Vector2f(-1000.f, -1000.f));
			rectangle.setPosition(sf::Vector2f(240, 0));
			if (rope == 1)
				candys.setPosition(190, 190);
			if (IntRect(240, 0, 5, 200).contains(Mouse::getPosition(window))) {
				rectangle.setFillColor(Color(255, 255, 255));
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left && rope == 1) {
					rope = 0;
				}
			}
			else {
				if (rope == 1)
					rectangle.setFillColor(Color::Black);
			}
			sf::Vector2f spritePos = candys.getPosition();
			if (rope == 0) {
				if (spritePos.y < 1000 && spritePos.y < 650) {
					rectangle.setFillColor(Color(255, 255, 255, 0));
					//напиши сюда падение
					spritePos.y = spritePos.y + fallSpeed * dtSeconds;
					candys.setPosition(spritePos.x, spritePos.y);
					//dtSeconds = clock.restart().asSeconds();			
				}
				if (spritePos.y > 650) {
					wins.setPosition(10, 200);
					if (IntRect(10, 200, 400, 300).contains(Mouse::getPosition(window))) {
						wins.setColor(Color::Green);
						if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
							wins.setPosition(-10, -400);
							//Sleep(500);
							level = 0;
							choose = 0;
						}
					}
					else {
						wins.setColor(Color::Red);
					}
				}

			}
		}
		if (choose == 3) {
			ones.setPosition(sf::Vector2f(-1000.f, -1000.f));
			twos.setPosition(sf::Vector2f(-1000.f, -1000.f));
			threes.setPosition(sf::Vector2f(-1000.f, -1000.f));
			fours.setPosition(sf::Vector2f(-1000.f, -1000.f));
			rectangle.setPosition(sf::Vector2f(240, 0));
			if (rope == 1)
				candys.setPosition(190, 190);
			if (IntRect(240, 0, 5, 200).contains(Mouse::getPosition(window))) {
				rectangle.setFillColor(Color(255, 255, 255));
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left && rope == 1) {
					rope = 0;
				}
			}
			else {
				if (rope == 1)
					rectangle.setFillColor(Color::Black);
			}
			sf::Vector2f spritePos = candys.getPosition();
			if (rope == 0) {
				if (spritePos.y < 1000 && spritePos.y < 650) {
					rectangle.setFillColor(Color(255, 255, 255, 0));
					//напиши сюда падение
					spritePos.y = spritePos.y + fallSpeed * dtSeconds;
					candys.setPosition(spritePos.x, spritePos.y);
					//dtSeconds = clock.restart().asSeconds();			
				}
				if (spritePos.y > 650) {
					wins.setPosition(10, 200);
					if (IntRect(10, 200, 400, 300).contains(Mouse::getPosition(window))) {
						wins.setColor(Color::Green);
						if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
							wins.setPosition(-10, -400);
							//Sleep(500);
							level = 0;
							choose = 0;
						}
					}
					else {
						wins.setColor(Color::Red);
					}
				}

			}
		}
		if (choose == 4) {
			ones.setPosition(sf::Vector2f(-1000.f, -1000.f));
			twos.setPosition(sf::Vector2f(-1000.f, -1000.f));
			threes.setPosition(sf::Vector2f(-1000.f, -1000.f));
			fours.setPosition(sf::Vector2f(-1000.f, -1000.f));
			rectangle.setPosition(sf::Vector2f(240, 0));
			if (rope == 1)
				candys.setPosition(190, 190);
			if (IntRect(240, 0, 5, 200).contains(Mouse::getPosition(window))) {
				rectangle.setFillColor(Color(255, 255, 255));
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left && rope == 1) {
					rope = 0;
				}
			}
			else {
				if (rope == 1)
					rectangle.setFillColor(Color::Black);
			}
			sf::Vector2f spritePos = candys.getPosition();
			if (rope == 0) {
				if (spritePos.y < 1000 && spritePos.y < 650) {
					rectangle.setFillColor(Color(255, 255, 255, 0));
					//напиши сюда падение
					spritePos.y = spritePos.y + fallSpeed * dtSeconds;
					candys.setPosition(spritePos.x, spritePos.y);
					//dtSeconds = clock.restart().asSeconds();			
				}
				if (spritePos.y > 650) {
					wins.setPosition(10, 200);
					if (IntRect(10, 200, 400, 300).contains(Mouse::getPosition(window))) {
						wins.setColor(Color::Green);
						if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
							wins.setPosition(-10, -400);
							//Sleep(500);
							level = 0;
							choose = 0;
						}
					}
					else {
						wins.setColor(Color::Red);
					}
				}

			}
		}
		window.display();

	}

	return 0;
}