// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
// look at videogame ending.. skipping a command line
// search key... doesn;t parse int if input is a string

#include <iostream>;
#include <vector>;
#include <string>;
#include "Media.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"
using namespace std;
//Protype functions:
bool deleteCheck(vector<Media*> &vect, string input, string value);
// runs main method
int main(){
    //initializes variables:
    bool playing = true;
    string input;
    vector<Media*> vect;
    // keeps running program until user quits
    while (playing) {
        //asks what user wants to do with database
        cout << "Enter a command (ADD, SEARCH, DELETE, QUIT)\n";
        getline(cin, input);
        // runs if user wants to add to database
        if (input == "ADD") {
            string media;
            // asks for type of media
            cout << "Enter the type of media you would like to add to the database (VIDEOGAMES, MUSIC, MOVIES)\n";
            getline(cin, media);
            // initalizes an object depending on media indicated by user, then adds to database
            if (media == "VIDEOGAMES") {
                VideoGames* games = new VideoGames();
                vect.push_back(static_cast<Media*>(games));
            }
            else if (media == "MUSIC") {
                Music* music = new Music();
                vect.push_back(static_cast<Media*>(music));
            }
            else if (media == "MOVIES") {
                Movies* movie = new Movies();
                vect.push_back(static_cast<Media*>(movie));
            }
            //checks for any errors
            else {
                cout << "You did not enter a proper media type\n";
            }
        }
        //runs if user wants to search database
        else if (input == "SEARCH") {
            string input;
            string value;
            //user may search by year or title
            cout << "Enter what you would like to search for (TITLE or YEAR): \n";
            getline(cin, input);
            cout << "Enter the title or year: \n";
            getline(cin, value);
            // checks databse for year or title and prints any results
            for (vector<Media*>::iterator it = (vect).begin(); it != (vect).end(); ++it) {
                if (input == "TITLE") {
                    if ((*it)->getTitle() == value) {
                        (*it)->printInfo();
                    }
                }
                else if (input == "YEAR") {
                    if ((*it)->getYear() == stoi(value)) {
                        (*it)->printInfo();
                    }
                }
            }
            // checks if user inputs are valid
            if (input != "TITLE" && input != "YEAR") {
                cout << "You did not enter a proper command\n";
            }
        }
        // runs if user wants to delete from database
        else if (input == "DELETE") {
            string input;
            string value;
            // user can delete by title or year
            cout << "Enter what you would like to search for to delete (TITLE or YEAR): \n";
            getline(cin, input);
            cout << "Enter the title or year: \n";
            getline(cin, value);
            // keeps deleting until all objects with the title/year are gone
            while (deleteCheck(vect, input, value)== true) {};
            for (vector<Media*>::iterator it = (vect).begin(); it != (vect).end(); ++it) { (*it)->checked = false; }
        }
        // stops program if the user indicates they want to stop playing
        else if (input == "QUIT") {
            playing = false; 
        }
        else {
            cout << "You did not enter a proper command\n";
        }
        input = "";
        
    }
}
// deletes from databse depending on title or year, returns true if there are still more to delete
bool deleteCheck(vector<Media*> &vect, string input, string value) {
    int count = 0;
    string confirm;
    bool exist = true;
    bool ran = false;
    // runs through vector, searching for any values matching year or title
    for (vector<Media*>::iterator it = (vect).begin(); it != (vect).end(); ++it) {
        if (input == "TITLE") {
            if ((*it)->getTitle() == value && (*it)->checked == false) {
                // confirms with user if they would like to delete
                cout << "Are you sure you would like to delete this item?(Y/N)"<< endl;
                (*it)->printInfo();
                getline(cin, confirm);
                if (confirm == "Y") {
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
        else if (input == "YEAR") {
            if ((*it)->getYear() == stoi(value) && (*it)->checked == false) {
                // confirms with user if they would like to delete
                cout << "Are you sure you would like to delete this item?(Y/N)" << endl;
                (*it)->printInfo();
                getline(cin, confirm);
                if (confirm == "Y") {
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


