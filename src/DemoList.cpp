// DemoList.cpp

#include "List.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// Creation of the list
	// We need a pointer aiming to the first Node of it

	cout << "Creating the list..." << endl;
	Node * list = MakeNewList();
	cout << endl;

	// Shows the current list

	cout << "Showing the list..." << endl;
	ShowList (list);
	cout << endl << endl;

	// Shows some operations on the list

	cout << "* Number of nodes = " << NumberOfNodes(list);
	cout << endl;
	cout << "* Arithmetic mean = " << Mean(list);
	cout << endl;
	cout << "* Variance = " << Variance(list);
	cout << endl << endl;

	// Cleans the memory
	cout << "Cleaning the memory..." << endl;
	CleanMemory (list);
	cout << "Memory cleaned." << endl;
	
	return 0;
}
