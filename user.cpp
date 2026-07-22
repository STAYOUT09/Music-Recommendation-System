#include "user.h"
#include <iostream>
#include <fstream>

User::User() {}

User::User(string n) {
    name = n;
}

void User::likeGenre(string g) {
    likedGenres.push_back(g);
}

void User::likeArtist(string a) {
    likedArtists.push_back(a);
}

void User::showLikedGenres() {
    cout << name << "'s liked genres:\n";
    for (string g : likedGenres)
        cout << "- " << g << endl;
}

void User::showLikedArtists() {
    cout << name << "'s liked artists:\n";
    for (string a : likedArtists)
        cout << "- " << a << endl;
}

void User::likeSong(Song s) {
    likedSongs.push_back(s);
    cout << "Song liked: " << s.title << endl;
}

//Show all liked songs
void User::showLikedSongs() {
    cout << "\n" << name << "'s Liked Songs:\n";
    if (likedSongs.empty()) {
        cout << "No songs liked yet.\n";
        return;
    }
    for (Song s : likedSongs) {
        s.display();
        cout << "----------------------\n";
    }
}

vector<Song>& User::getLikedSongs() {
    return likedSongs;
}

void User::createPlaylist(string name) {
    if (playlists.find(name) != playlists.end()) {
        cout << "Playlist already exists.\n";
        return;
    }
    playlists[name] = Playlist(name);
    cout << "Playlist created: " << name << endl;
}

void User::addToPlaylist(string name, Song s) {
    if (playlists.find(name) == playlists.end()) {
        cout << "Playlist not found.\n";
        return;
    }
    playlists[name].addSong(s);
}

void User::showPlaylist(string name) {
    if (playlists.find(name) == playlists.end()) {
        cout << "Playlist not found.\n";
        return;
    }
    playlists[name].showSongs();
}

void User::listPlaylists() {
    if (playlists.empty()) {
        cout << "No playlists found.\n";
        return;
    }
    cout << "\nYour Playlists:\n";
    for (auto& pair : playlists) {
        cout << "- " << pair.first << endl;
    }
}

void User::deletePlaylist(string name) {
    if (playlists.find(name) == playlists.end()) {
        cout << "Playlist not found.\n";
        return;
    }
    playlists.erase(name);
    cout << "Playlist deleted: " << name << endl;
}
