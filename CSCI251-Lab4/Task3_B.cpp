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
	string model = "";
	int year = 0;
	double price = 0.00;
public:
	Transportation() {}
	Transportation(string, int, double) {}
	~Transportation() {}
	virtual void display() {}
	virtual void setData() {}
	string getModel() {
		return model;
	}
	int getYear() {
		return year;
	}
	double getPrice() {
		return price;
	}
};

// Sub-Objects
class SeaTransport : public Transportation {
protected:
	string port = "";
public:
	SeaTransport() {}
	SeaTransport(string a, int b, double c, string d) : Transportation(model, year, price) {}
	~SeaTransport() {}
};

class LandTransport : public Transportation {
protected:
	string area = "";
public:
	LandTransport() {}
	LandTransport(string, int, double, string) : Transportation(model, year, price) {}
	~LandTransport() {}
};

class AirTransport : public Transportation {
protected:
	string sector = "";
public:
	AirTransport() {}
	AirTransport(string, int, double, string) : Transportation(model, year, price) {}
	~AirTransport() {}
};

// Sub-Object Specific Classes
class Canoe : public SeaTransport {
private:
	int maxDepth = 0;
public:
	Canoe() {}
	Canoe(string, int, double, string, int mD) : SeaTransport(model, year, price, port) {}
	~Canoe() {}
	void display();
	void setData(string, int, double, string, int);
};

void Canoe::display() {
	cout << "Canoe: " << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: $" << price << endl;
	cout << "Port: " << port << endl;
	cout << "Max Depth: " << maxDepth << endl;
}

void Canoe::setData(string canoeModel, int canoeYear, double canoePrice, string canoePort, int canoeMaxDepth) {
	model = canoeModel;
	year = canoeYear;
	price = canoePrice;
	port = canoePort;
	maxDepth = canoeMaxDepth;
}

class Car : public LandTransport {
private:
	int engineCapacity = 0;
public:
	Car() {}
	Car(string, int, double, string, int) : LandTransport(model, year, price, area) {}
	~Car() {}
	void display();
	void setData(string, int, double, string, int);
};

void Car::display() {
	cout << "Car: " << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: $" << price << endl;
	cout << "Area: " << area << endl;
	cout << "Engine Capacity: " << engineCapacity << endl;
}

void Car::setData(string carModel, int carYear, double carPrice, string carArea, int carEngineCapacity) {
	model = carModel;
	year = carYear;
	price = carPrice;
	area = carArea;
	engineCapacity = carEngineCapacity;
}

class Hovercraft : public AirTransport, virtual public LandTransport {
private:
	int maxSpeed = 0;
public:
	Hovercraft() {}
	Hovercraft(string, int, double, string, string, int) : AirTransport(Transportation::model, Transportation::year, Transportation::price, AirTransport::sector), LandTransport(Transportation::model, Transportation::year, Transportation::price, LandTransport::area) {}
	~Hovercraft() {}
	void display();
	void setData(string, int, double, string, string, int);
};

void Hovercraft::display() {
	cout << "Hovercraft: " << endl;
	cout << "Model: " << Transportation::model << endl;
	cout << "Year: " << Transportation::year << endl;
	cout << "Price: $" << Transportation::price << endl;
	cout << "Sector: " << sector << endl;
	cout << "Area: " << area << endl;
	cout << "Max Speed: " << maxSpeed << endl;
}

void Hovercraft::setData(string hovercraftModel, int hovercraftYear, double hovercraftPrice, string hovercraftSector, string hovercraftArea, int hovercraftMaxSpeed) {
	Transportation::model = hovercraftModel;
	Transportation::year = hovercraftYear;
	Transportation::price = hovercraftPrice;
	sector = hovercraftSector;
	area = hovercraftArea;
	maxSpeed = hovercraftMaxSpeed;
}

// Driver Code
int main() {

	Canoe myCanoe;
	Car myCar;
	Hovercraft myHovercraft;

	try {

		myCanoe.setData("a", 1, 252.5, "b", 100);
		myCanoe.display();

		myCar.setData("k", 1, 252.5, "q", 100);
		myCar.display();

		myHovercraft.setData("x", 1, 252.5, "s", "u", 100);
		myHovercraft.display();

		vector<Transportation*> transport(0);

		transport.push_back(&myCanoe);
		transport.push_back(&myCar);
		/*transport.push_back(&myHovercraft);
			Unable to add to vector array as the Hovercraft class is considered too ambiguous
		*/
	} catch (const std::bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
	}

	return 1;

}