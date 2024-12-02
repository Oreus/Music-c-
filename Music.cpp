#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Class: Genre
class Genre {
private:
    string name;
    string origin;

public:
    Genre(string name, string origin) : name(name), origin(origin) {}
    string getName() const { return name; }
    string getOrigin() const { return origin; }
    void setName(string genreName) { name = genreName; }
    void setOrigin(string genreOrigin) { origin = genreOrigin; }
};

//Class: Artist
class Artist {
private:
    string name;
    int age;
    Genre* genre;

public:
    Artist(string name, int age, Genre* genre) : name(name), age(age), genre(genre) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    Genre* getGenre() const { return genre; }
    void setName(string artistName) { name = artistName; }
    void setAge(int artistAge) { age = artistAge; }
    void setGenre(Genre* artistGenre) { genre = artistGenre; }
};

//Class: Song
class Song {
private:
    string title;
    double duration;
    Genre* genre;
    Artist* artist;

public:
    Song(string title, double duration, Genre* genre, Artist* artist) : title(title), duration(duration), genre(genre), artist(artist) {}
    string getTitle() const { return title; }
    double getDuration() const { return duration; }
    Genre* getGenre() const { return genre; }
    Artist* getArtist() const { return artist; }

    void setTitle(string songTitle) { title = songTitle; }
    void setDuration(double songDuration) { duration = songDuration; }
    void setGenre(Genre* songGenre) { genre = songGenre; }
    void setArtist(Artist* songArtist) { artist = songArtist; }
};

//Class: Instrument
class Instrument {
private:
    string name;
    string type;
    int strings;

public:
    Instrument(string name, string type, int strings) : name(name), type(type), strings(strings) {}
    string getName() const { return name; }
    string getType() const { return type; }
    int getStrings() const { return strings; }

    void setName(string instrumentName) { name = instrumentName; }
    void setType(string instrumentType) { type = instrumentType; }
    void setStrings(int numberOfStrings) { strings = numberOfStrings; }

    virtual void play() const {
        cout << "Playing " << name << endl;
    }
};

//Class: Guitar
class Guitar : public Instrument {
public:
    Guitar(string name, int strings) : Instrument(name, "Guitar", strings) {}
    void play() const {
        cout << "Strumming the guitar with " << getStrings() << " strings." << endl;
    }
};

//Class: Drum
class Drum : public Instrument {
private:
    string drumType;

public:
    Drum(string name, string drumType) : Instrument(name, "Drum", 0), drumType(drumType) {}
    string getDrumType() const { return drumType; }
    void setDrumType(string type) { drumType = type; }

    void play() const {
        cout << "Playing the " << drumType << " drum." << endl;
    }
};

int main() {
    Genre rock("Rock", "USA");
    Genre jazz("Jazz", "USA");

    Artist johnMayer("John Mayer", 45, &rock);
    Artist milesDavis("Miles Davis", 65, &jazz);

    Song gravity("Gravity", 4.5, &rock, &johnMayer);
    Song blueInGreen("Blue in Green", 5.1, &jazz, &milesDavis);

    Guitar electricGuitar("Fender Stratocaster", 6);
    Drum snareDrum("Snare", "Snare");

    cout << "Song: " << gravity.getTitle() << ", Artist: " << gravity.getArtist()->getName() << endl;
    cout << "Song: " << blueInGreen.getTitle() << ", Artist: " << blueInGreen.getArtist()->getName() << endl;

    electricGuitar.play();
    snareDrum.play();

    return 0;
}
