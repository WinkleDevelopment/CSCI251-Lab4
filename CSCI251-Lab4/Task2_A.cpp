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
#include <vector>

using namespace std;

class Box {
private:
	vector<Box> boxList;
	int cnt = 0;
	int total = 0;
public:
	Box();
	~Box();
	void report();
	void addBox(Box&);
	void removeBox();
};

// Constuctor
Box::Box() {
	total++;
	cout << "Object Added! New Total: " << total << endl;
}

// Deconstructor
Box::~Box() {
	total--;
	cout << "Object Removed! New Total: " << total << endl;
}

// Displays Report of All Objects
void Box::report() {
	cout << "The 'Box' has " << cnt << "mini boxes!" << endl;
}

// Adds Mini Boxes to Box (Object List)
void Box::addBox(Box& mini) {
	boxList.push_back(mini);
	cnt++;
	cout << "Added Mini Box to Box" << endl;
}

// Removes Mini Box from Box (Object List)
void Box::removeBox() {
	boxList.pop_back();
	total++;
	cout << "Removed Mini Box from Box" << endl;
}

//int main() {
//
//	Box box1;
//	Box box2;
//
//	// Reports for Objects
//	box1.report();
//	box2.report();
//
//	// Add Box As Mini to Other Box
//	box1.addBox(box2);
//
//	// Report Box 1 Object
//	box1.report();
//
//	// Remove Mini Box from Box
//	box1.removeBox();
//
//	// Report Box 1 Object
//	box1.report();
//
//	// Remove Boxes
//	box1.~Box();
//	box2.~Box();
//
//	return 1;
//}