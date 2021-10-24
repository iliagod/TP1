#pragma once
#include "cats.h"
#include "animal.h"
#include "birds.h"
#include "fishes.h"
#include "element.h"

using namespace std;

class Keeper
{
private:
	element* tail;
	int size;
public:
	Keeper();
	Keeper(element* Tail, int Size);
	Keeper(const Keeper& keeper);
	int get_size();
	int pop();
	void push(animal* obj);
	int save_all();
	int recover_all();
	bool isempty();
	void show();
	~Keeper();
};