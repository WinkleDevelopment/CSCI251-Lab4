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
    double value = 0;
public:
    Painting();
    Painting(string, string);
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
    cin >> this->title;
    cout << "Enter artist ";
    cin >> this->artist;
    value = 400;
}

void Painting::showPainting() {
    cout << this->title << this->artist << " value: $" << value << endl;
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
    int x;
    for (x = 0; x <= NUM; ++x)
        if (p.getArtist() == artists[x])
            isFamous = true;
    return isFamous;
}

//int main() {
//    const int NUM = 4;
//    Painting pictures[NUM];
//    int x;
//    for (x = 0; x < NUM; ++x) {
//        Painting tmp;
//        tmp.setData();
//        if (isPaintingFamous(tmp))
//        {
//            FamousPainting tmpF(tmp.getTitle(), tmp.getArtist());
//            tmp = tmpF;
//        }
//        pictures[x] = tmp;
//    }
//
//    for (x = 0; x < NUM; x++)
//        pictures[x].showPainting();
//}
