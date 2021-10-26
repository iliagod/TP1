#pragma once

#include "cats.h"
#include "animal.h"
#include "fishes.h"
#include "birds.h"
#include "keeper.h"
#include <iostream>
using std::cout;
using std::cin;

short answer;

bool check_input()
{
	if (!cin.good())
	{
		cout << "�� ������� ������������ ������! ���������� ��� ���!" << endl;
		system("pause");
		cin.clear();
		while (cin.get() != '\n');
		return false;
	}
	return true;
}

void menu()
{
	while (1)
	{
		system("cls");
		cout << "�������� �����:" << endl << endl;
		cout << "1. �������� ������� � �������" << endl;
		cout << "2. ������� ������� �� �������" << endl;
		cout << "3. ��������� ������ � ����" << endl;
		cout << "4. ��������� �������� ������� �� �����" << endl;
		cout << "5. �������� �������� �������" << endl;
		cout << "6. ����� �� ���������" << endl;
		cout << "��� �����: ";
		cin >> answer;
		if (!check_input())
			continue;
		break;
	}
}

void add_menu(Keeper* keeper)
{
	short answer2;
	while (1)
	{
		system("cls");
		cout << "�������� ������ ��� ���������� � �������:" << endl;
		cout << "1. ����" << endl;
		cout << "2. �����" << endl;
		cout << "3. �����" << endl;
		cout << "4. �����" << endl;
		cout << "��� �����: ";
		cin >> answer2;
		if (!check_input())
			continue;
		switch (answer2)
		{
		case 1:
		{
			animal* obj = new fishes;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 2:
		{
			animal* obj = new birds;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 3:
		{
			animal* obj = new cats;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "��� ������ ������ ����! ���������� ��� ���!" << endl;
			system("cls");
			continue;
		}
		}
		break;
	}
}

void starting()
{
	Keeper* keeper = new Keeper;
	while (1)
	{
		menu();
		switch (answer)
		{
		case 1:
		{
			add_menu(keeper);
			continue;
		}
		case 2:
		{
			if (!(keeper->pop()))
			{
				system("cls");
				cout << "�������� ����������! ������� �����!" << endl;
				system("pause");
				continue;
			}
			system("cls");
			cout << "�������� ������ �������!" << endl;
			system("pause");
			continue;
		}
		case 3:
		{
			system("cls");
			int answ;
			if (keeper->get_size() == 0)
			{
				cout << "������� �����, ������ ����������!" << endl;
				system("pause");
				continue;
			}
			cout << "������ �������� � ����(1) ��� ������������(2)?" << endl;
			cin >> answ;
			if (!check_input())
			{
				cout << "�� ������� �������� ������! ���������� ��� ���!" << endl;
				system("pause");
				continue;
			}
			switch (answ)
			{
			case 1:
			{
				if (keeper->save())
				{
					cout << "���������� ������ �������!" << endl;
					system("pause");
				}
				break;
			}
			case 2:
			{
				if (remove("txt.txt") != 0)
					cout << "������ ����������";
				else
				{
					if (keeper->save())
						cout << "���������� ������ �������!" << endl;
				}
				system("pause");
				break;
			}
			default:
			{
				cout << "�������� ������! ��������� ����������������� ���������!" << endl;
				system("pause");
				break;
			}
			}
			continue;
		}
		case 4:
		{
			if ((keeper->recover()) != -1)
				cout << "�������������� ������ �������!" << endl;
			else
				cout << "���� ����!" << endl;
			system("pause");
			continue;
		}
		case 5:
		{
			system("cls");
			keeper->show();
			system("pause");
			continue;
		}
		case 6:
		{
			break;
		}
		default:
		{
			cout << "��� ������ ������ ����! ���������� ��� ���!" << endl;
			system("pause");
			continue;
		}
		}
		break;
	}
}