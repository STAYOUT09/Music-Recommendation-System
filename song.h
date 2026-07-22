#pragma once

#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    string artist;
    string genre;
    int rating;

    Song(); // Default constructor
    Song(string t, string a, string g, int r); // Parameterized constructor
    void display(); // Function to print song details
};
