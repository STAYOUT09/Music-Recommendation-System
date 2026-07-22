#include "library.h"
#include <iostream>
#include <fstream>
using namespace std;

void MusicLibrary::addSong(Song s) {
    allSongs.push_back(s);
}

void MusicLibrary::showAllSongs() {
    cout << "All Songs in Library:\n";
    for (Song s : allSongs) {
        s.display();
        cout << "----------------------\n";
    }
}

string toLower(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

void MusicLibrary::recommendSongs(User user) {
    cout << "\nRecommended Songs for " << user.name << ":\n";
    bool found = false;

    for (Song s : allSongs) {
        bool genreMatch = false, artistMatch = false;

        for (string liked : user.likedGenres) {
            if (toLower(s.genre) == toLower(liked)) {
                genreMatch = true;
                break;
            }
        }

        for (string likedArtist : user.likedArtists) {
            if (toLower(s.artist) == toLower(likedArtist)) {
                artistMatch = true;
                break;
            }
        }

        if (genreMatch || artistMatch) {
            s.display();
            cout << "----------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No recommendations based on your preferences.\n";
    }
}

void MusicLibrary::saveSongsToFile(string filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout<<"Error opening file for writing.\n";
        return;
    }

    for (Song s : allSongs) {
        outFile << s.title << "|" << s.artist << "|" << s.genre << "|" << s.rating << "\n";
    }

    outFile.close();
    cout<<"Songs saved to file.\n";
}

void MusicLibrary::loadSongsFromFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "File not found. Starting with empty library.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        string title = line.substr(0, pos1);
        string artist = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string genre = line.substr(pos2 + 1, pos3 - pos2 - 1);
        int rating = stoi(line.substr(pos3 + 1));

        Song s(toLower(title), toLower(artist), toLower(genre), rating);
        allSongs.push_back(s);
    }

    inFile.close();
    cout << "Songs loaded from file.\n";
}

void MusicLibrary::searchSongs(string keyword) {
    cout << "\nSearch Results:\n";
    bool found = false;

    for (Song& s : allSongs) {
        if (toLower(s.title).find(keyword) != string::npos ||
            toLower(s.artist).find(keyword) != string::npos) {
            s.display();
            cout << "----------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No songs found matching that keyword.\n";
    }
}

Song* MusicLibrary::findSongByTitle(string title) {
    for (Song& s : allSongs) {
        if (toLower(s.title) == title) {
            return &s;
        }
    }
    return nullptr;
}

vector<Song>& MusicLibrary::getAllSongs() {
    return allSongs;
}
