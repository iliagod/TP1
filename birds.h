#pragma once
#include <string>
#include "animal.h"

using namespace std;

class birds : public animal
{
private:
	string kindofbird;
	string color;
	string typeoffood;
	string habitat;
public:
	virtual void data() override;
	virtual void set() override;
	virtual void recover(ifstream& in) override;
	virtual void save(ofstream& out) override;
	birds();
	birds(string k, string c, string t, string h);
	birds(const birds& Birds);
	~birds();
	int exception(string line);
};
