#include <iostream>
#include <string>
using namespace std;

// Class 1: Instrument
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

    void playInstrument() const {
        cout << "Playing the " << name << ", a " << type << " instrument with " << strings << " strings." << endl;
    }
};

// Class 2: Genre
class Genre {
private:
    string name;
    string origin;

public:
    Genre(string name, string origin) : name(name), origin(origin) {}

    string getName() const { return name; }
    string getOrigin() const { return origin; }

    void describeGenre() const {
        cout << name << " music originated from " << origin << "." << endl;
    }
};

// Class 3: Artist
class Artist {
private:
    string name;
    int age;
    string genre;

public:
    Artist(string name, int age, string genre) : name(name), age(age), genre(genre) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getGenre() const { return genre; }

    void perform() const {
        cout << name << " is performing " << genre << " music at age " << age << "." << endl;
    }
};

int main() {
    Instrument guitar("Guitar", "String", 6);
    Genre rock("Rock", "USA");
    Artist artist("Dave Grohl", 54, "Rock");

    guitar.playInstrument();
    rock.describeGenre();
    artist.perform();

    return 0;
}