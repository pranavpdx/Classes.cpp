// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Delete function not working, input not assigning correclty 


#include <iostream>;
#include <vector>;
#include "Media.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"
using namespace std;
//Protype functions:
bool deleteCheck(vector<Media*> &vect, char input1[80], char value[80]);
// runs main method
int main(){
    //initializes variables:
    bool playing = true;
    char input[80];
    vector<Media*> vect;
    // keeps running program until user quits
    while (playing) {
        //asks what user wants to do with database
        cout << "Enter a command (ADD, SEARCH, DELETE, QUIT)\n";
        cin.getline(input, 80, '\n');
        // runs if user wants to add to database
        if (strcmp(input, "ADD") == 0) {
            char media[80];
            // asks for type of media
            cout << "Enter the type of media you would like to add to the database (VIDEOGAMES, MUSIC, MOVIES)\n";
            cin.getline(media, 80, '\n');
            // initalizes an object depending on media indicated by user, then adds to database
            if (strcmp(media, "VIDEOGAMES") == 0) {
                VideoGames* games = new VideoGames();
                vect.push_back(static_cast<Media*>(games));
            }
            else if (strcmp(media, "MUSIC") == 0) {
                Music* music = new Music();
                vect.push_back(static_cast<Media*>(music));
            }
            else if (strcmp(media, "MOVIES") == 0) {
                Movies* movie = new Movies();
                vect.push_back(static_cast<Media*>(movie));
            }
            //checks for any errors
            else {
                cout << "You did not enter a proper media type\n";
            }
        }
        //runs if user wants to search database
        else if (strcmp(input, "SEARCH") == 0) {
            char input1[80];
            char value[80];
            //user may search by year or title
            cout << "Enter what you would like to search for (TITLE or YEAR): \n";
            cin.getline(input1, 80, '\n');
            cout << "Enter the title or year: \n";
            cin.getline(value, 80, '\n');
            // checks databse for year or title and prints any results
            for (vector<Media*>::iterator it = (vect).begin(); it != (vect).end(); ++it) {
                if (strcmp(input1, "TITLE") == 0) {
                    if (strcmp((*it)->getTitle(), value) == 0) {
                        (*it)->printInfo();
                    }
                }
                else if (strcmp(input1, "YEAR") == 0) {
                    if ((*it)->getYear() == stoi(value)) {
                        (*it)->printInfo();
                    }
                }
            }
            // checks if user inputs are valid
            if (strcmp(input1, "TITLE") != 0 && strcmp(input1, "YEAR") != 0) {
                cout << "You did not enter a proper command\n";
            }
        }
        // runs if user wants to delete from database
        else if (strcmp(input, "DELETE") == 0) {
            char input1[80];
            char value[80];
            // user can delete by title or year
            cout << "Enter what you would like to search for to delete (TITLE or YEAR): \n";
            cin.getline(input1, 80, '\n');
            cout << "Enter the title or year: \n";
            cin.getline(value, 80, '\n');
            // keeps deleting until all objects with the title/year are gone
            while (deleteCheck(vect, input1, value)== true) {};
            for (vector<Media*>::iterator it = (vect).begin(); it != (vect).end(); ++it) { (*it)->checked = false; }
        }
        // stops program if the user indicates they want to stop playing
        else if (strcmp(input, "QUIT") == 0) {
            playing = false; 
        }
        else {
            cout << "You did not enter a proper command\n";
        }
        
        
    }
}
// deletes from databse depending on title or year, returns true if there are still more to delete
bool deleteCheck(vector<Media*> &vect, char input1[80], char value[80]) {
    int count = 0;
    char confirm[80];
    bool exist = true;
    bool ran = false;
    // runs through vector, searching for any values matching year or title
    for (vector<Media*>::iterator it = (vect).begin(); it != (vect).end(); ++it) {
        if (strcmp(input1, "TITLE") == 0) {
            if (strcmp((*it)->getTitle(), value) == 0 && (*it)->checked == false) {
                // confirms with user if they would like to delete
                cout << "Are you sure you would like to delete this item?(Y/N)"<< endl;
                (*it)->printInfo();
                cin.getline(confirm, 80, '\n');
                if (strcmp(confirm, "Y") == 0) {
                    vect.erase(vect.begin() + count);
                    exist = true;
                    ran = true;
                    break;
                }
                else {
                    (*it)->checked = true;
                }
            }
        }
        else if (strcmp(input1, "YEAR") == 0) {
            if ((*it)->getYear() == stoi(value) && (*it)->checked == false) {
                // confirms with user if they would like to delete
                cout << "Are you sure you would like to delete this item?(Y/N)" << endl;
                (*it)->printInfo();
                cin.getline(confirm, 80, '\n');
                if (strcmp(confirm, "Y") == 0) {
                    vect.erase(vect.begin() + count);
                    exist = true;
                    ran = true;
                    break;
                }
                else {
                    (*it)->checked = true;
                }
            }
        }
        count++;    
        // if the for loop doesn't find any objects, stops the search
        exist = false;
    }
    // if the for loop didn't run, vector is empty and stops the search
    if (ran == false) {
        exist = false;
    }
    return exist;
}


