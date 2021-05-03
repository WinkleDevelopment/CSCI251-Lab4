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
using namespace std;

#include "Task4_mylibrary.h"

int main()
{
    // functionOne should take 3 integers from the user.
    // functionTwo should add those 3 integers together.

    int one, two, three, sum;
    functionOne(one, two, three);
    sum = functionTwo(one, two, three);

    cout << "The sum of " << one << " " << two << " " << three;
    cout << " is ... " << sum << endl;
}
