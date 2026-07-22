#include "playlist.h"

void Playlist::addSong(Song s) {
    songs.push_back(s);
    cout << "Added to playlist: " << s.title << endl;
}

void Playlist::showSongs() {
    if (songs.empty()) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nPlaylist: " << name << "\n";
    for (Song s : songs) {
        s.display();
        cout << "----------------------\n";
    }
}

vector<Song>& Playlist::getSongs() {
    return songs;
}
