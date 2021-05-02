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
using namespace std;

class Person;
class Contract;

class Company
{
private:
    string name;
    string addresss;
    Contract* contr;
public:
    Company(string Name = "") : name(Name), contr(NULL) {}
    string getName() const { return(name); }
    void setContract(Contract* cn) { contr = cn; }
    Contract* getContract() const { return(contr); }
};

class Person
{
private:
    string name;
    Contract* contr;
public:
    Person(string Name = "") : name(Name), contr(NULL) {}
    string getName() const { return(name); }
    void setContract(Contract* cn) { contr = cn; }
    Contract* getContract() const { return(contr); }
};

class Contract
{
    Person* pers;
    Company* comp;
    int contNum;
    int duration;
    static float rate;
public:
    Contract(Person* worker, Company* empl, int cN, int dr)
        : pers(worker), comp(empl), contNum(cN), duration(dr)
    {
        worker->setContract(this); // set a link Person->Contract
        comp->setContract(this);   // set a link Company->Contract
    }

    string getPersonName() const { return(pers->getName()); }
    string getCompName() const { return(comp->getName()); }
    float getRate() const { return(rate); }
    int getDuration() const { return(duration); }
    int getContractNumber() const { return(contNum); }
};
float Contract::rate = 70.00;

int main()
{
    Person* worker = new Person("John");
    Company* company = new Company("Bell Pty Ltd");

    Contract* cont1 = new Contract(worker, company, 5247, 12);

    cout << worker->getName() << " has a contract number "
        << worker->getContract()->getContractNumber()
        << " with " << worker->getContract()->getCompName()
        << endl;

    cout << "Duration: " << worker->getContract()->getDuration()
        << " months" << endl;
    cout << "Rate: $" << worker->getContract()->getRate()
        << "/hr " << endl;


    return 0;
}

/*

(a) What concept does it illustrate?

    This concept shows a Person, Company, and Contract object being created then displaying the objects themselves and variables of the objects

(b) How are the classes related?

    Association between the classes is shown by the use of Objects inside the creation of another class. 
    E.g Person and Company objects are required in the creation of the contract object

(c) What happens if either the worker or company is deleted in main, after the Contract is set up but before the output is displayed?

    If any of the required objects are deleted from the main (Person & Company Objects), the Contract objects 
    will be unable to locate details regarding the objects which are required for the construction of the object 
    itself. In this case the object will be incomplete and removed/unaccessable

(d) What happens if we add an additional company and add a contract between John and the new company?

    A new Company and Contract object would be required for John to "work" for a different company.

*/