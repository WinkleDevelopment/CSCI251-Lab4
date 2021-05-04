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

class Material {
protected:
	string brand;
	double price;
public:
	Material() {}
	virtual ~Material() {}
	virtual void setData();
	virtual void display();
	string getName() { return brand; }
	double getPrice() { return price; }
	virtual int getMaxLoad() {}
};

class Straw : public Material {
private:
	int maxLoad = 10;
public:
	Straw() {}
	~Straw() {}
	void setData(string, double);
	void display();
	int getMaxLoad() { return maxLoad; }
};

void Straw::setData(string nM, double pR) {
	brand = nM;
	price = pR;
}

void Straw::display() {
	cout << " --| Straw |-- " << endl;
	cout << brand << endl;
	cout << price << endl;
	cout << maxLoad << endl << endl;
}

class Stick : public Material {
private:
	int maxLoad = 25;
public:
	Stick() {}
	~Stick() {}
	void setData(string, double);
	void display();
	int getMaxLoad() { return maxLoad; }
};

void Stick::setData(string nM, double pR) {
	brand = nM;
	price = pR;
}

void Stick::display() {
	cout << " --| Stick |-- " << endl;
	cout << brand << endl;
	cout << price << endl;
	cout << maxLoad << endl << endl;
}

class Brick : public Material {
private:
	int maxLoad = 100;
public:
	Brick() {}
	~Brick() {}
	void setData(string, double);
	void display();
	int getMaxLoad() { return maxLoad; }
};

void Brick::setData(string nM, double pR) {
	brand = nM;
	price = pR;
}

void Brick::display() {
	cout << " --| Brick |-- " << endl;
	cout << brand << endl;
	cout << price << endl;
	cout << maxLoad << endl << endl;
}

class Pig {
private:
	string name;
	int age;
public: 
	Pig() {}
	Pig(string nM, int aG) : name(nM), age(aG) {}
	~Pig() {}
	void setData(string, int);
	void display();
	string getName() { return name; }
	int getAge() { return age; }
};

void Pig::setData(string nM, int aG) {
	name = nM;
	age = aG;
}

void Pig::display() {
	cout << " --| Pig |-- " << endl;
	cout << name << endl;
	cout << age << endl << endl;
}

class Wolf {
private:
	string name;
	int maxStrength = 60;
public:
	Wolf() {}
	Wolf(string nM) : name(nM) {}
	~Wolf() {}
	void setData(string);
	void display();
	string getName() { return name; }
	int getMaxStrength() { return maxStrength; }
};

void Wolf::setData(string nM) {
	name = nM;
}

void Wolf::display() {
	cout << " --| Wolf |-- " << endl;
	cout << name << endl;
	cout << maxStrength << endl << endl;
}

class House {
private:
	Pig* owner;
	Material* material;
public:
	House() {}
	House(Pig* pG, Material* mTL) : owner(pG), material(mTL) {}
	~House() { cout << "House Destroyed" << endl; getPig()->~Pig(); getMaterial()->~Material(); }
	void setData(Pig*, Material*);
	void display();
	Pig* getPig() { return owner; }
	Material* getMaterial() { return material; }
};

void House::setData(Pig* pG, Material* mTL) {
	owner = pG;
	material = mTL;
}

void House::display() {
	cout << " --| House |-- " << endl;
	owner->display();
	material->display();
}

int main() {

	Pig* pig1 = new Pig("Little Pig 1", 8);
	Pig* pig2 = new Pig("Little Pig 2", 16);
	Pig* pig3 = new Pig("Little Pig 3", 24);

	Straw* strawHouse;
	Stick* stickHouse;
	Brick* brickHouse;

	strawHouse->setData("Natural", 0);
	stickHouse->setData("Organic", 5);
	brickHouse->setData("Industrial", 25);

	House* house1 = new House(pig1, strawHouse);
	House* house2 = new House(pig2, stickHouse);
	House* house3 = new House(pig3, brickHouse);

	house1->display();
	house2->display();
	house3->display();

	Wolf* wolf = new Wolf("Wolf with Blowing Issues");

	wolf->display();

	vector<House*> houses;
	houses.push_back(house1);
	houses.push_back(house2);
	houses.push_back(house3);

	for (House* house : houses) {
		if (wolf->getMaxStrength() > house->getMaterial()->getMaxLoad()) {
			house->~House();
		} else {
			cout << "The Pigs Lived" << endl;
		}
	}

	return 1;
}
