#include "song.h"
#include <iostream>
using namespace std;
 
Song::Song() {
    title = "";
    artist = "";
    genre = "";
    rating = 0;
}

Song::Song(string t, string a, string g, int r) : title(t), artist(a), genre(g), rating(r) {}

void Song::display() {
    cout << "Title: " << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << "/5" << endl;
}
