#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "song.h"
#include "playlist.h"

using namespace std;

class User {
public:
    string name;
    vector<string> likedGenres;
    vector<string> likedArtists;
    vector<Song> likedSongs;
    vector<Song>& getLikedSongs();
    map<string, Playlist> playlists;

    User();
    User(string n);

    void likeGenre(string g);
    void likeArtist(string a);

    void showLikedGenres();
    void showLikedArtists();
    void likeSong(Song s);
    void showLikedSongs();
    
    void createPlaylist(string name);
    void addToPlaylist(string playlistName, Song s);
    void showPlaylist(string name);
    void listPlaylists();
    void deletePlaylist(string name);
};


