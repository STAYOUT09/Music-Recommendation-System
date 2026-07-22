#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "song.h"
#include "user.h"
using namespace std;

class MusicLibrary {
private:
    vector<Song> allSongs;

public:
    void addSong(Song s);
    void showAllSongs();
    void recommendSongs(User user);
    void saveSongsToFile(string filename);
    void loadSongsFromFile(string filename);
    void searchSongs(string keyword);
    Song* findSongByTitle(string title);
    vector<Song>& getAllSongs();
};

