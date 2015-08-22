// List.cpp

#include "List.h"
#include <iostream>
#include <cmath>
using namespace std;

/*****************************************************************************/
// MAKE A NEW LIST
// Asks for new data until the user introduces a negative value, then it
// finishes the list adding a null value on the "next" field of the last node.

Node * MakeNewList (void)
{
	Node * first;	// Always points to the first node
	Node * end;		// Points to the last node created

	string msg = "Please enter a value (negative to finish): ";

	first = 0;

	int n;			// Value to read and add to each node

	// First reading

	cout << msg;
	cin >> n;

	if (n >= 0)
	{
		// Memory request for the first node
		first = new Node;

		first->info = n;	// Save n in the new node
		first->next = 0;	// This is (right now) the last node

		end = first;

		// Second reading

		cout << msg;
		cin >> n;

		while (n >= 0)
		{
			// Memory request for the next node
			end->next = new Node;
			end = end->next;

			end->info = n;
			end->next = 0;

			// Next reading
			cout << msg;
			cin >> n;
		}
	}

	return (first);
}

/*****************************************************************************/
// SHOW A LIST
// Show the values of the list of the argument (indicated with the pointer to
// the first node), from the first to the last node.

void ShowList (Node * first)
{
	Node * aux = first;

	while (aux != 0)
	{
		cout << (aux->info) << "  ";
		aux = aux->next;
	}
}

/*****************************************************************************/
// CHECK IF THE LIST IS VOID
// Receives a pointer to the first node of a list and checks if it is void

bool IsItVoid (Node * first)
{
	return (first == 0);
}

/*****************************************************************************/
// CLEAN THE LIST FROM MEMORY
// As the list is stored on the Heap, it needs to be released at least
// before the program closes, or when needed.
// Receives the pointer to the first node.

void CleanMemory (Node * first)
{
	if (!IsItVoid(first))		// Checks if the list is void
	{
		Node * aux = first;

		while (aux->next != 0)
		{
			aux = aux->next;
			delete first;
			first = aux;
		}

		delete first;
	}
}

/*****************************************************************************/
// NUMBER OF NODES
// Calculates the number of nodes in a list.
// Receives as argument a pointer to the first node.

int NumberOfNodes (Node * first)
{
	int count = 0;		// Counts the number of nodes

	if (!IsItVoid(first))		// Checks if the list is void
	{
		Node * aux = first;		// Auxiliar pointer that points to each node		

		while (aux != 0)
		{
			aux = aux->next;
			count++;
		}
	}

	return (count);
}

/*****************************************************************************/
// ARITHMETIC MEAN OF THE STORED DATA
// Calculates the mean of all the values stored in the list.
// Receives as argument a pointer to the first node.

DataType Mean (Node * first)
{
	DataType mean = 0;

	if (!IsItVoid(first))		// Checks if the list is void
	{
		Node * aux = first;
		DataType add = 0;		// Keeps the addition of the values

		// Add the numbers to the variable until the list ends
		while (aux != 0)
		{
			add += aux->info;
			aux = aux->next;
		}

		// Calculates the mean (addition / number of data)
		mean = add / NumberOfNodes(first);
	}

	return (mean);
}

/*****************************************************************************/
// VARIANCE OF THE STORED DATA
// Calculates the variance of all the values stored in the list.
// Receives as argument a pointer to the first node.

DataType Variance (Node * first)
{
	DataType variance = 0;

	if (!IsItVoid(first))		// Checks if the list is void
	{
		Node * aux = first;
		DataType add = 0;		// Keeps the addition of the values

		// Add the numbers to the variable until the list ends
		while (aux != 0)
		{
			add += pow((aux->info),2);
			aux = aux->next;
		}

		// Calculates the variance
		variance = (add/NumberOfNodes(first)) - pow(Mean(first),2);
	}

	return (variance);

}
