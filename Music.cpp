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
    Genre(string genreName, string genreOrigin) : name(genreName), origin(genreOrigin) {}
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
    Artist(string artistName, int artistAge, Genre* artistGenre) : name(artistName), age(artistAge), genre(artistGenre) {}
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
    Song(string songTitle, double songDuration, Genre* songGenre, Artist* songArtist) : title(songTitle), duration(songDuration), genre(songGenre), artist(songArtist) {}

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
    Instrument(string instrumentName, string instrumentType, int numberOfStrings) : name(instrumentName), type(instrumentType), strings(numberOfStrings) {}
    virtual ~Instrument() {} 

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
    Guitar(string instrumentName, int numberOfStrings) : Instrument(instrumentName, "Guitar", numberOfStrings) {}

    void play() const {
        cout << "Strumming the guitar with " << getStrings() << " strings." << endl;
    }
};

//Class: Drum
class Drum : public Instrument {
private:
    string drumType; 

public:
    Drum(string instrumentName, string type) : Instrument(instrumentName, "Drum", 0), drumType(type) {}

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
