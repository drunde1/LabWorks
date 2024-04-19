#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#pragma warning(disable : 4996)

using namespace std;
using namespace sf;


int main();
void consol();
void file();

int Prov()
{
	setlocale(0, "");
	string p;
	bool F{ true };

	while (F)
	{
		cin >> p;
		if ((!p.empty() && p.find_first_not_of("01") == string::npos))
			F = false;
		else
			cout << "Данные введены некоректно, попробуйте снова : " << endl;
	}
	return stoi(p);
}
void proda()
{
	setlocale(0, "");
	cout << "Продолжить? (0 - нет, 1 - да): ";
	int pr = Prov();

	if (pr == 1)
		main();
	else
		exit(0);
}


int entering()
{
	setlocale(0, "");
	string p;
	bool F{ true };

	while (F)
	{
		cin >> p;
		if (!p.empty() && p.find_first_not_of("0123456789") == string::npos)
			F = false;
		else
			cout << "Данные введены некоректно, попробуйте снова : " << endl;
	}
	return stoi(p);
}

void file()
{
	setlocale(0, "");
	int OUT;
	cout << "Сохранить в фaйл (1) или не сохранять (0)?:";
	OUT = Prov();
	int n;
	string path = ("in.txt");
	ifstream fin;
	fin.open(path);
	
	string str;
	int p{ 0 };
	fin >> n;
	int* array = new int[3 * n];
	int i{ -1 };
	while (!fin.eof())
	{
		fin >> str;
		try
		{
			i += 1;
			array[i] = stoi(str);
			
		}
		catch (std::invalid_argument)
		{
			cout << "Необходимо ввести число!\n";
		}
	}
	
	const Color colorArray[12] = { Color::Cyan, Color::Blue, Color::Green, Color::Red, Color::Yellow,
		Color::White, Color(128,0,128), Color(255,0,255), Color(0,128,128), Color(128, 128, 0), Color(255, 255, 0), Color(0, 255, 255) };

	RenderWindow window(VideoMode(800, 800), "Squares");
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				if (OUT == 1)
				{
					Image i = window.capture();
					i.saveToFile("image.png");
				}
				window.close();
				exit(0);
			}
		}
		window.clear(Color(200, 200, 200, 0));
		int d = 0;
		for (int i = 0; i < 3 * n; i++)
		{

			if (i % 3 == 0)
			{
				d++;
				if (d == 12)
				{
					d = 0;
				}
				RectangleShape rectangle(Vector2f(array[i + 2] * 10, array[i + 2] * 10));
				rectangle.move(array[i] * 10 - 0.5 * array[i + 2] * 10 + 400, array[i + 1] * 10 - 0.5 * array[i + 2] * 10 + 400);
				rectangle.setFillColor(colorArray[d]);
				rectangle.setOutlineThickness(2);
				rectangle.setOutlineColor(Color(0, 0, 0));
				window.draw(rectangle);
				srand(time(NULL));

			}
		}
		window.display();
	}
}

void consol() 
{
	int n;
	setlocale(0, "");
	int OUT;
	cout << "Сохранить в фaйл (1) или не сохранять (0)?:";
	OUT = Prov();
	cout << "Введите n:";
	n = entering();
	int* array = new int[3 * n];
	for (int i = 0; i < 3 * n; i++)
	{
		cout << "[" << i << "]" << ": ";
		array[i] = entering();
	}
	cout << "\nВаш массив: ";

	for (int i = 0; i < 3 * n; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
	
	const Color colorArray[12] = { Color::Cyan, Color::Blue, Color::Green, Color::Red, Color::Yellow,
		Color::White, Color(128,0,128), Color(255,0,255), Color(0,128,128), Color(128, 128, 0), Color(255, 255, 0), Color(0, 255, 255) };
	
	RenderWindow window(VideoMode(800, 800), "Squares");
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				if (OUT == 1)
				{
					Image i = window.capture();
					i.saveToFile("image.png");
				}
				window.close();
				proda();
			}
		}
		window.clear(Color(200, 200, 200, 0));
		int d = 0;
		for (int i = 0; i < 3 * n; i++)
		{
			
			if (i % 3 == 0)
			{
				d++;
				if (d == 12)
				{
					d = 0;
				}
				RectangleShape rectangle(Vector2f(array[i + 2] * 10, array[i + 2] * 10));
				rectangle.move(array[i] * 10 - 0.5 * array[i + 2] * 10 + 400, array[i + 1] * 10 - 0.5 * array[i + 2] * 10 + 400);
				rectangle.setFillColor(colorArray[d]);
				rectangle.setOutlineThickness(2);
				rectangle.setOutlineColor(Color(0, 0, 0));
				window.draw(rectangle);
				srand(time(NULL));

			}
		}
		window.display();
	}
}