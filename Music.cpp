#include "Music.h"
//constructer, sets inputs for the object
Music::Music() {
    publisher = new string();
    artist = new string();
    string input;
    cout << "Enter the title of the song: ";
    getline(cin, *title);
    cout << "Enter the artist the song was made by: ";
    getline(cin, *artist);
    cout << "Enter the year the song was made: ";
    getline(cin, input);
    year = stoi(input);
    cout << "Enter the duration of the song (enter number of minutes, you can use decimals): ";
    getline(cin, input);
    duration = stof(input);
    cout << "Enter the publisher of the song: ";
    getline(cin, *publisher);

}
//getter functions
string Music::getArtist() {
    return *artist;
}

string Music::getPublisher() {
    return *publisher;
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