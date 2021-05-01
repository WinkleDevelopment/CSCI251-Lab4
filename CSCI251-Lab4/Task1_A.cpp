/*
*
*	Bachelor of Computer Science (Software Engineering)
*
*				Kyle J. Brookes | 6822794
*
*					     Lab 4
*
*/

#include<iostream>
#include<string>

using namespace std;

class Painting {
protected:
    string title;
    string artist;
    int value;
public:
    Painting();
    Painting(string name, string painter);
    void showPainting();
    void setData();
    string getArtist();
    string getTitle();
};

Painting::Painting() {};

Painting::Painting(string name, string painter) {
    this->title = name;
    this->artist = painter;
    this->value = 400;
}

void Painting::setData() {
    cout << "Enter painting's title ";
    cin >> artist;
    cout << "Enter artist ";
    cin >> title;
    value = 400;
}

void Painting::showPainting() {
    cout << title << artist << " value $40";
}

string Painting::getArtist() {
    return this->artist;
}

string Painting::getTitle() {
    return this->title;
}

class FamousPainting : public Painting {
public:
    FamousPainting(string, string);
};

FamousPainting::FamousPainting(string name, string painter) : Painting(name, painter) {
    this->value = 25000;
}

bool isPaintingFamous(Painting p) {
    bool isFamous = false;
    const int NUM = 4;
    string artists[NUM] = { "Degas","Monet","Picasso","Rembrandt" };
    char x;
    for (x = 0; x <= NUM; ++x)
        if (p.getArtist() == artists[x])
            isFamous = true;
    return isFamous;
}

int main() {
    const int NUM = 4;
    Painting pictures[NUM];
    int x;
    for (x = 0; x < NUM; ++x) {
        Painting temp;
        temp.setData();
        if (isPaintingFamous(temp))
        {
            FamousPainting tempF(temp.getTitle(), temp.getArtist());
            temp = tempF;
        }
        pictures[x] = temp;
    }

    for (x = 0; x < NUM; x++)
        pictures[x].showPainting();
}
