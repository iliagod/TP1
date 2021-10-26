#include "fishes.h"
#include <iostream>
#include <cstring>
using namespace std;

/*Для каждой рыбы
определено: порода, окрас, тип питания.*/
void fishes::data()
{
	cout << "Порода: " << kindoffish << endl;
	cout << "Окрас: " << color << endl;
	cout << "Тип питания: " << typeoffood << endl;
}

void fishes::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите породу рыбы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> kindoffish;
		if (exception(kindoffish) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите окрас(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> color;
		if (exception(color) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите тип питания(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> typeoffood;
		if (exception(typeoffood) == -2)
			continue;
		break;
	}
}

void fishes::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 3; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			kindoffish = line;
			break;
		}
		case 1:
		{
			color = line;
			break;
		}
		case 2:
		{
			typeoffood = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void fishes::save(ofstream& out)
{
	out << 1 << endl;
	out << kindoffish << endl;
	out << color << endl;
	out << typeoffood << endl;
}

fishes::fishes()
{
	kindoffish = "Нет информации";
	color = "Нет информации";
	typeoffood = "Нет информации";
}

fishes::fishes(string k, string c, string t)
{
	kindoffish = k;
	color = c;
	typeoffood = t;
}

fishes::fishes(const fishes& fur) :
	kindoffish(fur.kindoffish), color(fur.color), typeoffood(fur.typeoffood) {}

fishes::~fishes() {}

int fishes::exception(string line)
{
	try
	{
		if (line.empty())
			throw - 2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "Данное поле не может быть пустым!!!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "Что-то пошло не так!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}