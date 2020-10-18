#pragma once
#include "Media.h"
#include <iostream>
#include <string>
class Movies : public Media {
public:
    // functions:
    virtual string getDirector();
    virtual float getRating();
    virtual float getDuration();
    virtual void printInfo();
    // constructer asks user to input values of class
    Movies();
    //destructer deletes any pointers
    ~Movies();
    // variables:
    float duration;
    string* director;
    float rating;
};
