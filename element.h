#pragma once
#include "animal.h"

class element
{
private:
	animal* obj;
	element* prev;
public:
	animal* get_obj();
	element* get_prev();
	void set_obj(animal* Obj);
	void set_prev(element* Prev);
};
