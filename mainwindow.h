#pragma once

#include <QMainWindow>
#include "song.h"
#include "user.h"
#include "library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadSongs();
    void recommendSongs();
    void likeSong();
    void viewLikedSongs();
    void createPlaylist();
    void addToPlaylist();
    void viewPlaylist();
    void listPlaylists();
    void deletePlaylist();
    void exit();

private:
    Ui::MainWindow *ui;
    User user;
    MusicLibrary lib;
    Playlist p;

};

