# 🎵 Music Recommendation System

A desktop-based **Music Recommendation System** developed in **C++** using **Object-Oriented Programming (OOP)** principles with a **Qt GUI**. The application allows users to browse songs, search by title or artist, receive personalized recommendations, like songs, and manage playlists through an interactive graphical interface.

---

## 📌 Project Overview

This project was developed to demonstrate the practical implementation of Object-Oriented Programming concepts while building a functional desktop application. The system uses a content-based recommendation approach, suggesting songs based on the user's favorite genres and artists.

The application consists of:
- A C++ backend implementing the business logic
- A Qt Widgets GUI providing an interactive user experience
- File-based storage for managing song data

---

## ✨ Features

### 🎵 Song Management
- Load songs from a text file
- Display all available songs
- Search songs by title or artist
- View song details

### ❤️ User Preferences
- Like songs
- Store favorite genres
- Store favorite artists
- View liked songs

### 🤖 Recommendation System
- Recommend songs using:
  - Genre only
  - Artist only
  - Genre + Artist
- Case-insensitive searching and matching

### 📂 Playlist Management
- Create playlists
- Add songs to playlists
- View playlists
- Display all playlists

### 🖥️ Graphical User Interface
- Built using Qt Widgets
- Tab-based interface
- Interactive buttons and input fields
- User-friendly layout

### 💾 File Handling
- Load songs from text files
- Save song library
- Store user data using file handling

---

# 🛠 Technologies Used

- **Programming Language:** C++
- **GUI Framework:** Qt Widgets
- **IDE:** Qt Creator
- **Compiler:** MinGW / GCC
- **Build System:** CMake

---

# 📁 Project Structure

```
Music-Recommendation-System/
│
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
│
├── song.h
├── song.cpp
│
├── user.h
├── user.cpp
│
├── playlist.h
├── playlist.cpp
│
├── library.h
├── library.cpp
│
├── recommender.h
├── recommender.cpp
│
├── songs.txt
│
└── README.md
```

---

# 🧩 Object-Oriented Programming Concepts Used

This project demonstrates the implementation of:

- ✅ Classes & Objects
- ✅ Encapsulation
- ✅ Abstraction
- ✅ Composition (HAS-A Relationship)
- ✅ Constructors
- ✅ Function Overloading
- ✅ Separate Header and Source Files
- ✅ Modular Design

---

# 📚 STL Concepts Used

The project also makes use of several Standard Template Library (STL) containers and algorithms including:

- `vector`
- `map`
- Range-based for loops
- String manipulation
- File streams (`ifstream`, `ofstream`)

---

# 🚀 Getting Started

## Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/Music-Recommendation-System.git
```

## Open in Qt Creator

1. Open Qt Creator.
2. Open the project folder.
3. Select the `CMakeLists.txt` file.
4. Configure the project.
5. Build and Run.

---

# 📄 Song File Format

Songs are stored in a text file using the following format:

```
title|artist|genre|rating
```

Example:

```
shape of you|ed sheeran|pop|5
blinding lights|the weeknd|pop|5
perfect|ed sheeran|romantic|4
believer|imagine dragons|rock|5
```

---

# 📸 Screenshots

Home Dashboard
<img width="1917" height="1013" alt="image" src="https://github.com/user-attachments/assets/5d71c694-c968-4b89-955d-03cf19c7b09d" />



---

# 🎯 Future Improvements

- Audio playback using QMediaPlayer
- User login system
- Database integration (SQLite)
- Advanced recommendation algorithm
- Song ratings and reviews
- Playlist deletion and editing
- Dark mode support

---

# 👨‍💻 Authors

**Syed Dawood Bukhari**

Software Engineering Undergraduate

GitHub: https://github.com/STAYOUT09

---

## 📜 License

This project is developed for educational purposes and learning Object-Oriented Programming with C++ and Qt.
