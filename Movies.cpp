#include "Movies.h"
//constructor, sks user to fill in inputs
Movies::Movies() {
    director = new string();
    string input;
    cout << "Enter the title of the movie: ";
    getline(cin, *title);
    cout << "Enter the director the movie was made by: ";
    getline(cin, *director);
    cout << "Enter the year the movie was made: ";
    getline(cin, input);
    year = stoi(input);
    cout << "Enter the duration of the movie (enter number of hours, you can use decimals): ";
    getline(cin, input);
    duration = stof(input);
    cout << "Enter the rating of the movie (out of 10): ";
    getline(cin, input);
    rating = stof(input);
}

//getter functions
string Movies::getDirector() {
    return *director;
}

float Movies::getRating() {
    return rating;
}

float Movies::getDuration() {
    return duration;
}
//prints info
void Movies::printInfo() {
    cout << "Title: " << getTitle() << ", Director: " << getDirector() << ", Year: " << getYear() << ", Duration: " << getDuration() << ", Rating: " << getRating() << endl;
}

// destructer deletes pointers
Movies::~Movies() {
    delete title;
    delete director;
}