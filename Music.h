#pragma once
#include "Media.h"
#include <iostream>
#include <string>
using namespace std;
class Music : public Media {
public:
    // functions:
    virtual string getPublisher();
    virtual string getArtist();
    virtual float getDuration();
    // constructer asks user to input values of class
    Music();
    virtual void printInfo();
    //destructer deletes any pointers
    ~Music();
    //variables
    float duration;
    string* publisher;
    string* artist;
};

