#include "Movies.h"
//constructor, sks user to fill in inputs
Movies::Movies() {
    director = new char();
    char* input = new char();
    cout << "Enter the title of the movie: ";
    cin.getline(title, 80, '\n');
    //title = input;
    cout << "Enter the director the movie was made by: ";
    cin.getline(director, 80, '\n');
    cout << "Enter the year the movie was made: ";
    cin.getline(input, 80, '\n');
    year = stoi(input);
    cout << "Enter the duration of the movie (enter number of hours, you can use decimals): ";
    cin.getline(input, 80, '\n');
    duration = stof(input);
    cout << "Enter the rating of the movie (out of 10): ";
    cin.getline(input, 80, '\n');
    rating = stof(input);
}

//getter functions
char* Movies::getDirector() {
    return director;
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