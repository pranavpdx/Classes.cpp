#pragma once
#include <iostream>;
#include <string>;
// Media parent class
using namespace std;
class Media {
public:
    //functions:
    virtual char* getTitle();
    virtual int getYear();
    virtual void printInfo();
    Media();
    //variables:
    char* title;
    int year;
    bool checked;
};

