#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "song.h"
using namespace std;

class Playlist {
private:
    string name;
    vector<Song> songs;

public:
    Playlist() {}
    Playlist(string n) { name = n; }

    string getName() { return name; }
    void addSong(Song s);
    void showSongs();
    vector<Song>& getSongs();
};
