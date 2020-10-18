#include "Media.h"
using namespace std;
//constructor, sets variables
Media::Media() {
	title = new string();
	checked = false;
}
//getter functions
string Media::getTitle() {
	return *title;
}

int Media::getYear() {
	return year;
}

void Media::printInfo() {}