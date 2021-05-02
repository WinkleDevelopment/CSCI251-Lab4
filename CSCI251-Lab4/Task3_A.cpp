/*
*
*	Bachelor of Computer Science (Software Engineering)
*
*				Kyle J. Brookes | 6822794
*
*					     Lab 4
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parent Class
class Animal {
protected:
    string name;
    string breed;
    int age;
public:
    Animal(string, string, int);
    ~Animal();
    string getName() {
        return name;
    }
    string getBreed() {
        return breed;
    }
    int getAge() {
        return age;
    }
};

// Sub-Class of Animal
class Cat : public Animal {
private:
    float weight = 0;
    static constexpr double licenseFee = 10;
public:
    Cat();
    Cat(string name, string breed, int age, float weight) : Animal(name, breed, age) {}
    ~Cat() {}
    void setCatData(string, string, int, float);
    void showCat();
};

void Cat::setCatData(string catName, string catBreed, int catAge, float catWeight) {
    this->name = catName;
    this->breed = catBreed;
    this->age = catAge;
    this->weight = catWeight;
}

void Cat::showCat() {
    cout << "Cat: " << name << " is a " << breed << endl;
    cout << "The cat's age is " << age << endl;
    cout << "They also weigh " << weight << "kg!" << endl;
    cout << "License fee: $" << licenseFee << endl;
}

// Sub-Class of Animal
class Lizard : public Animal {
private:
    string scaleColour = "";
    static constexpr double licenseFee = 5;
public:
    Lizard();
    Lizard(string name, string breed, int age, string scaleColour) : Animal(name, breed, age) {}
    ~Lizard() {}
    void setLizardData(string, string, int, string);
    void showLizard();
};

void Lizard::setLizardData(string lizardName, string lizardBreed, int lizardAge, string lizardScaleColour) {
    this->name = lizardName;
    this->breed = lizardBreed;
    this->age = lizardAge;
    this->scaleColour = lizardScaleColour;
}

void Lizard::showLizard() {
    cout << "Lizard: " << name << " is a " << breed << endl;
    cout << "The lizards's age is " << age << endl;
    cout << "They also has " << scaleColour << " coloured scales!" << endl;
    cout << "License fee: $" << licenseFee << endl;
}

int main() {
    Cat myCat;
    myCat.setCatData("Tigger", "Fluffy unit", 3, 4.6);
    myCat.showCat();

    Lizard myLizard;
    myLizard.setLizardData("Scales", "Devil", 1, "Purple");
    myLizard.showLizard();

    vector<Animal> hierarchy;
    hierarchy.reserve(2);

    hierarchy.push_back(myCat);
    hierarchy.push_back(myLizard);

    return 1;

}
