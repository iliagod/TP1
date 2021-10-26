#include "birds.h"
#include <iostream>

using namespace std;
/*��� ������ ����� ����������:
������, �����, ��� ��������, ��� �������.*/
void birds::data()
{
	cout << "������: " << kindofbird << endl;
	cout << "�����: " << color << endl;
	cout << "�������: " << typeoffood << endl;
	cout << "����� ��������: " << habitat << endl;

}

void birds::set()
{
	while (1)
	{
		system("cls");
		cout << "������� ������ �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> kindofbird;
		if (exception(kindofbird) == -2)
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
		cout << "������� ��� ������� �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> typeoffood;
		if (exception(typeoffood) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� ��������(������ ��������, ������� ������ ������������� _ ): ";
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
	kindofbird = "��� ����������";
	color = "��� ����������";
	typeoffood = "��� ����������";
	habitat = "��� ����������";

}

birds::birds(string k, string �, string t, string h)
{
	kindofbird = k;
	color = �;
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
			cout << "������ ���� �� ����� ���� ������!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "���-�� ����� �� ���!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}