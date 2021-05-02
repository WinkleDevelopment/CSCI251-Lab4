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

// Base Object
class Transportation {
protected:
	string model;
	int year;
	float price;
public:
	Transportation(string, int, float);
	~Transportation();
	virtual void display();
	virtual void setData();
	string getModel() {
		return model;
	}
	int getYear() {
		return year;
	}
	float getPrice() {
		return price;
	}
};

// Sub-Objects
class SeaTransport : public Transportation {
protected:
	string port;
public:
	SeaTransport(string, int, float, string) : Transportation(model, year, price) {}
	~SeaTransport() {}
};

class LandTransport : public Transportation {
protected:
	string area;
public:
	LandTransport(string, int, float, string) : Transportation(model, year, price) {}
	~LandTransport() {}
};

class AirTransport : public Transportation {
protected:
	string sector;
public:
	AirTransport(string, int, float, string) : Transportation(model, year, price) {}
	~AirTransport() {}
};

// Sub-Object Specific Classes
class Canoe : public SeaTransport {
private:
	int maxDepth;
public:
	Canoe(string, int, float, string, int) : SeaTransport(model, year, price, port) {}
	~Canoe() {}
	void display();
	void setData(string, int, float, string, int);
};

void Canoe::display() {
	cout << "Canoe: " << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: $" << price << endl;
	cout << "Port: " << port << endl;
	cout << "Max Depth: " << maxDepth << endl;
}

void Car::setData(string canoeModel, int canoeYear, float canoePrice, string canoePort, int canoeMaxDepth) {
	this->model = canoeModel;
	this->year = canoeYear;
	this->price = canoePrice;
	this->area = canoePort;
	this->engineCapacity = canoeMaxDepth;
}

class Car : public LandTransport {
private:
	int engineCapacity;
public:
	Car(string, int, float, string, int) : LandTransport(model, year, price, area) {}
	~Car() {}
	void display();
	void setData(string, int, float, string, int);
};

void Car::display() {
	cout << "Car: " << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: $" << price << endl;
	cout << "Area: " << area << endl;
	cout << "Engine Capacity: " << engineCapacity << endl;
}

void Car::setData(string carModel, int carYear, float carPrice, string carArea, int carEngineCapacity) {
	this->model = carModel;
	this->year = carYear;
	this->price = carPrice;
	this->area = carArea;
	this->engineCapacity = carEngineCapacity;
}

class Hovercraft : public AirTransport { // Need to be derived from two classes :P
private:
	int maxSpeed;
public:
	Hovercraft(string, int, float, string, int) : AirTransport(model, year, price, sector) {}
	~Hovercraft() {}
	void display();
	void setData(string, int, float, string, int);
};

void Hovercraft::display() {
	cout << "Hovercraft: " << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: $" << price << endl;
	cout << "Sector: " << sector << endl;
	cout << "Max Speed: " << maxSpeed << endl;
}

void Hovercraft::setData(string hovercraftModel, int hovercraftYear, float hovercraftPrice, string hovercraftSector, int hovercraftMaxSpeed) {
	this->model = hovercraftModel;
	this->year = hovercraftYear;
	this->price = hovercraftPrice;
	this->sector = hovercraftSector;
	this->maxSpeed = hovercraftMaxSpeed;
}

// Driver Code
int main() {

	Canoe myCanoe("a", 2000, 2500.3, "Sydney", 40);
	Car myCar("b", 4000, 12500.7, "Wollongong", 128);
	Hovercraft myHovercaft("c", 6000, 22500.3, "Aplha", 150);

	myCanoe.display();
	myCar.display();
	myHovercaft.display();

	return 1;

}