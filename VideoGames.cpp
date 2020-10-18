#include "VideoGames.h"
//constructer gets user to input values
VideoGames::VideoGames() {
    publisher = new string();
    string input;
    cout << "Enter the title of the video game: ";
    getline(cin, *title);
    cout << "Enter the year the video game was made: ";
    getline(cin, input);
    year = stoi(input);
    cout << "Enter the publisher of the video game: ";
    getline(cin, *publisher);
    cout << "Enter the rating of the video game (out of 10): ";
    getline(cin, input);
    rating = stoi(input);
}
//getter functions
string VideoGames::getPublisher() {
    return *publisher;
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
