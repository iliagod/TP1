#pragma once
#include <string>
#include "animal.h"

using namespace std;

class fishes : public animal
{
private:
    string kindoffish;
    string color;
    string typeoffood;
public:
    virtual void data() override;
    virtual void set() override;
    virtual void recover(ifstream& in) override;
    virtual void save(ofstream& out) override;
    fishes();
    fishes(string t, string d, string c);
    fishes(const fishes& fur);
    ~fishes();
    int exception(string line);
};
