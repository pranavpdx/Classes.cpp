#pragma once
#include <iostream>
#include "Media.h"
using namespace std;
//Videogames child class
class VideoGames : public Media {
public:
    // functions:
    virtual char* getPublisher();
    virtual int getRating();
    virtual void printInfo();
    // constructer asks user to input values of class
    VideoGames();
    //destructer deletes any pointers
    ~VideoGames();
    //variables
    char* publisher;
    int rating;
};

