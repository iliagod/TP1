#include "birds.h"
#include <iostream>

using namespace std;
/*Для каждой птицы определено:
порода, окрас, чем питается, где обитает.*/
void birds::data()
{
	cout << "Порода: " << kindofbird << endl;
	cout << "Окрас: " << color << endl;
	cout << "Питание: " << typeoffood << endl;
	cout << "Место обитания: " << habitat << endl;

}

void birds::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите породу птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> kindofbird;
		if (exception(kindofbird) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите окрас птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> color;
		if (exception(color) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите тип питания птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> typeoffood;
		if (exception(typeoffood) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите место обитания(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> habitat;
		if (exception(habitat) == -2)
			continue;
		break;
	}
}

void birds::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 4; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			kindofbird = line;
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
		case 3:
		{
			habitat = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void birds::save(ofstream& out)
{
	out << 2 << endl;
	out << kindofbird << endl;
	out << color << endl;
	out << typeoffood << endl;
	out << habitat << endl;
}

birds::birds()
{
	kindofbird = "Нет информации";
	color = "Нет информации";
	typeoffood = "Нет информации";
	habitat = "Нет информации";

}

birds::birds(string k, string с, string t, string h)
{
	kindofbird = k;
	color = с;
	typeoffood = t;
	habitat = h;
}

birds::birds(const birds& Birds) :
	kindofbird(Birds.kindofbird), color(Birds.color), typeoffood(Birds.typeoffood), habitat(Birds.habitat) {}

birds::~birds() {}

int birds::exception(string line)
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
			cout << "Данное поле не может быть пустым!" << endl;
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