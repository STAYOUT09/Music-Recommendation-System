#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "song.h"
#include "user.h"
#include "library.h"
#include "playlist.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // load songs into the shared library instance
    lib.loadSongsFromFile("songs.txt");

    // connect UI signals
    connect(ui->like, &QPushButton::clicked, this, &MainWindow::likeSong);
    connect(ui->recommendButton, &QPushButton::clicked, this, &MainWindow::recommendSongs);
    connect(ui->viewLike, &QPushButton::clicked, this, &MainWindow::viewLikedSongs);
    connect(ui->createP, &QPushButton::clicked, this, &MainWindow::createPlaylist);
    connect(ui->addP, &QPushButton::clicked, this, &MainWindow::addToPlaylist);
    connect(ui->viewP, &QPushButton::clicked, this, &MainWindow::viewPlaylist);
    connect(ui->listAllP, &QPushButton::clicked, this, &MainWindow::listPlaylists);
    connect(ui->deleteP, &QPushButton::clicked, this, &MainWindow::deletePlaylist);
    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);

}

MainWindow::~MainWindow() {
    delete ui;
}

string toTitleCase(string str) {
    bool capitalize = true;
    for (char& c : str) {
        if (isspace(c) || c == '-') {
            capitalize = true;
        } else if (capitalize && isalpha(c)) {
            c = toupper(c);
            capitalize = false;
        } else {
            c = tolower(c);
        }
    }
    return str;
}

void MainWindow::loadSongs() {
    QFile file("songs.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->outputDisplay->setText("Failed to load songs.");
        return;
    }

    QTextStream in(&file);
    QStringList songs;
    while (!in.atEnd()) {
        songs << in.readLine();
    }
    file.close();

    ui->outputDisplay->setText("Songs loaded: " + QString::number(songs.size()));
}

void MainWindow::recommendSongs() {
    QString genre = ui->genreInput->text().toLower().trimmed();
    QString artist = ui->artistInput->text().toLower().trimmed();

    bool genreGiven = !genre.isEmpty();
    bool artistGiven = !artist.isEmpty();

    if (!genreGiven && !artistGiven) {
        ui->outputDisplay->setPlainText("Please enter at least a genre or an artist.");
        return;
    }

    const vector<Song>& songs = lib.getAllSongs();  // your getter

    QStringList recommendations;
    for (const Song& s : songs) {
        QString songGenre = QString::fromStdString(s.genre).toLower();
        QString songArtist = QString::fromStdString(s.artist).toLower();

        bool matchGenre = genreGiven && songGenre.contains(genre);
        bool matchArtist = artistGiven && songArtist.contains(artist);

        if (matchGenre || matchArtist) {
            QString result = QString::fromStdString(
                toTitleCase(s.title) + " by " + toTitleCase(s.artist) + " [" + toTitleCase(s.genre) + "]"
                );
            recommendations << result;
        }
    }

    if (recommendations.isEmpty()) {
        ui->outputDisplay->setPlainText("No matching songs found.");
    } else {
        ui->outputDisplay->setPlainText("Recommendations:\n" + recommendations.join("\n"));
    }
}

void MainWindow::likeSong() {
    QString title = ui->likeInput->text().toLower().trimmed();
    string titleStr = title.toStdString();
    if (title.isEmpty()) {
        ui->outputDisplay->setText("Please enter a song title.");
        return;
    }

    Song* s = lib.findSongByTitle(title.toStdString());
    if (s != nullptr) {
        user.likeSong(*s);  // from your User class
        ui->outputDisplay->setText("Liked song: " + QString::fromStdString(s->title));
    } else {
        ui->outputDisplay->setText("Song not found.");
    }

    qDebug() << "Liked songs count: " << user.getLikedSongs().size();
    if (s != nullptr) {
        qDebug() << "Found song:" << QString::fromStdString(s->title);
    }
}

void MainWindow::viewLikedSongs() {
    const vector<Song>& liked = user.getLikedSongs();

    qDebug() << "Showing liked songs, total:" << liked.size();

    if (liked.empty()) {
        ui->outputDisplay->setPlainText("No liked songs.");
        return;
    }

    QString output = "Liked Songs:\n";

    for (const Song& s : liked) {
        QString line = QString::fromStdString(
            toTitleCase(s.title) + " by " + toTitleCase(s.artist) + " [" + toTitleCase(s.genre) + "]"
            );
        output += line + "\n";
    }

    ui->outputDisplay->setPlainText(output);  // ✅ REPLACE setText() with setPlainText()
}

void MainWindow::createPlaylist() {
    QString name = ui->playlistInput->text().toLower().trimmed();
    if (name.isEmpty()) {
        ui->outputDisplay->setPlainText("Enter a playlist name.");
        return;
    }

    user.createPlaylist(name.toStdString());
    ui->outputDisplay->setPlainText("Playlist created: " + name);
}

void MainWindow::addToPlaylist() {
    QString title = ui->pSongInput->text().toLower().trimmed();
    QString playlist = ui->playlistInput->text().toLower().trimmed();

    if (title.isEmpty() || playlist.isEmpty()) {
        ui->outputDisplay->setPlainText("Enter both song title and playlist name.");
        return;
    }

    Song* s = lib.findSongByTitle(title.toStdString());
    if (!s) {
        ui->outputDisplay->setPlainText("Song not found.");
        return;
    }

    user.addToPlaylist(playlist.toStdString(), *s);
    ui->outputDisplay->setPlainText("Added song to playlist.");
}

void MainWindow::viewPlaylist() {
    QString name = ui->playlistInput->text().toLower().trimmed();
    if (name.isEmpty()) {
        ui->outputDisplay->setPlainText("Enter a playlist name.");
        return;
    }

    if (user.playlists.find(name.toStdString()) == user.playlists.end()) {
        ui->outputDisplay->setPlainText("Playlist not found.");
        return;
    }

    Playlist& p = user.playlists[name.toStdString()];

    QStringList songList;
    for (const Song& s : p.getSongs()) {
        QString line = QString::fromStdString(
            toTitleCase(s.title) + " by " + toTitleCase(s.artist) + " [" + toTitleCase(s.genre) + "]"
            );
        songList << line;
    }

    ui->outputDisplay->setPlainText("Playlist: " + name + "\n" + songList.join("\n"));
}

void MainWindow::listPlaylists() {
    if (user.playlists.empty()) {
        ui->outputDisplay->setPlainText("No playlists found.");
        return;
    }

    QStringList names;
    for (const auto& pair : user.playlists) {
        names << QString::fromStdString(pair.first);
    }

    ui->outputDisplay->setPlainText("Your Playlists:\n" + names.join("\n"));
}

void MainWindow::deletePlaylist() {
    QString name = ui->playlistInput->text().toLower().trimmed();
    if (name.isEmpty()) {
        ui->outputDisplay->setPlainText("Enter a playlist name to delete.");
        return;
    }

    if (user.playlists.find(name.toStdString()) == user.playlists.end()) {
        ui->outputDisplay->setPlainText("Playlist not found.");
        return;
    }

    user.deletePlaylist(name.toStdString());
    ui->outputDisplay->setPlainText("Deleted playlist: " + name);
}

void MainWindow::exit() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you want to quit?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
