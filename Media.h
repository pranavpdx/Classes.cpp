#pragma once
#include <iostream>;
#include <string>;
// Media parent class
using namespace std;
class Media {
public:
    //functions:
    virtual string getTitle();
    virtual int getYear();
    virtual void printInfo();
    Media();
    //variables:
    string* title;
    int year;
    bool checked;
};

