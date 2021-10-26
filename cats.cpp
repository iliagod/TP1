#include "cats.h"
#include <iostream>
#include <cstring>

using namespace std;
/*��� ������ ����� ����������:
������, �����, ��� ���������, ������*/
void cats::data()
{
	cout << "������: " << kindofcat << endl;
	cout << "�����: " << color << endl;
	cout << "��� ���������: " << FIO << endl;
	cout << "������: " << name << endl;
}

void cats::set()
{
	while (1)
	{
		system("cls");
		cout << "������� ������ �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> kindofcat;
		if (exception(kindofcat) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> color;
		if (exception(color) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ��� ���������(������ ��������, ������� ������ ������������� _ ): ";
		cin >> FIO;
		if (exception(FIO) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ������ �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> name;
		if (exception(name) == -2)
			continue;
		break;
	}
}

void cats::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 4; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			kindofcat = line;
			break;
		}
		case 1:
		{
			color = line;
			break;
		}
		case 2:
		{
			FIO = line;
			break;
		}
		case 3:
		{
			name = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void cats::save(ofstream& out)
{
	out << 3 << endl;
	out << kindofcat << endl;
	out << color << endl;
	out << FIO << endl;
	out << name << endl;
}

cats::cats()
{
	kindofcat = "��� ����������";
	color = "��� ����������";
	FIO = "��� ����������";
	name = "��� ����������";
}

cats::cats(string kindofcat, string color, string FIO, string name)
{
	this->kindofcat = kindofcat;
	this->color = color;
	this->FIO = FIO;
	this->name = name;

}

cats::cats(const cats& Cats) : kindofcat(Cats.kindofcat), color(Cats.color), FIO(Cats.FIO), name(Cats.name) {}

int cats::exception(string line)
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
			cout << "���������� ��������� ��������!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "���-�� ����� �� ���! ������!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}

cats::~cats() {}