#include "Music.h"
//constructer, sets inputs for the object
Music::Music() {
    publisher = new char();
    artist = new char();
    char* input = new char();
    cout << "Enter the title of the song: ";
    cin.getline(title, 80, '\n');
    //title = input;
    cout << "Enter the artist the song was made by: ";
    cin.getline(artist, 80, '\n');
    cout << "Enter the year the song was made: ";
    cin.getline(input, 80, '\n');
    year = stoi(input);
    cout << "Enter the duration of the song (enter number of minutes, you can use decimals): ";
    cin.getline(input, 80, '\n');
    duration = stof(input);
    cout << "Enter the publisher of the song: ";
    cin.getline(input, 80, '\n');
    publisher = input;
}
//getter functions
char* Music::getArtist() {
    return artist;
}

char* Music::getPublisher() {
    return publisher;
}

float Music::getDuration() {
    return duration;
}
// prints info
void Music::printInfo() {
    cout << "Title: " << getTitle() << ", Artist: " << getArtist() << ", Year: " << getYear() << ", Duration: " << getDuration() << ", Publisher: " << getPublisher() << endl;
}
//destructure deletes pointers
Music::~Music() {
    delete title;
    delete publisher;
    delete artist;
}