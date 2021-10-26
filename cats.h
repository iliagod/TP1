#pragma once
#include <string>
#include "animal.h"

using namespace std;

class cats : public animal
{
private:
	string kindofcat;
	string color;
	string FIO;
	string name;
public:
	virtual void data() override;
	virtual void set() override;
	virtual void recover(ifstream& in) override;
	virtual void save(ofstream& out) override;
	cats();
	cats(string kindofcat, string color, string FIO, string name);
	cats(const cats& Cats);
	int exception(string line);
	~cats();
};
