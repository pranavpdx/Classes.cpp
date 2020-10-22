#include "VideoGames.h"
//constructer gets user to input values
VideoGames::VideoGames() {
    publisher = new char();;
    char* input = new char();
    cout << "Enter the title of the video game: ";
    cin.getline(title, 80, '\n');
    //title = input;
    cout << "Enter the year the video game was made: ";
    cin.getline(input, 80, '\n');
    year = stoi(input);
    cout << "Enter the publisher of the video game: ";
    cin.getline(publisher, 80, '\n');
    cout << "Enter the rating of the video game (out of 10): ";
    cin.getline(input, 80, '\n');
    rating = stoi(input);
}
//getter functions
char* VideoGames::getPublisher() {
    return publisher;
}

int VideoGames::getRating() {
    return rating;
}
//prints info
void VideoGames::printInfo() {
    cout << "Title: " << getTitle() << ", Year:  " << getYear() << ", Publisher: " << getPublisher() << ", Rating: " << getRating() << endl;
}
//destructer deletes pointers
VideoGames::~VideoGames() {
    delete title;
    delete publisher;
}
