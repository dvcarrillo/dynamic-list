// List.cpp

#include "List.h"
#include <iostream>
#include <cmath>
using namespace std;

/*****************************************************************************/
// MAKE A NEW LIST
// Asks for new data until the user introduces a negative value, then it
// finishes the list adding a null value on the "next" field of the last node.

PNode MakeNewList (void)
{
	PNode first;	// Always points to the first node
	PNode end;		// Points to the last node created

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

void ShowList (PNode first)
{
	PNode aux = first;

	while (aux != 0)
	{
		cout << (aux->info) << "  ";
		aux = aux->next;
	}
}

/*****************************************************************************/
// CHECK IF THE LIST IS VOID
// Receives a pointer to the first node of a list and checks if it is void

bool IsItVoid (PNode first)
{
	return (first == 0);
}

/*****************************************************************************/
// CLEAN THE LIST FROM MEMORY
// As the list is stored on the Heap, it needs to be released at least
// before the program closes, or when needed.
// Receives the pointer to the first node.

void CleanMemory (PNode first)
{
	if (!IsItVoid(first))		// Checks if the list is void
	{
		PNode aux = first;

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

int NumberOfNodes (PNode first)
{
	int count = 0;		// Counts the number of nodes

	if (!IsItVoid(first))		// Checks if the list is void
	{
		PNode aux = first;		// Auxiliar pointer that points to each node		

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

DataType Mean (PNode first)
{
	DataType mean = 0;

	if (!IsItVoid(first))		// Checks if the list is void
	{
		PNode aux = first;
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

DataType Variance (PNode first)
{
	DataType variance = 0;

	if (!IsItVoid(first))		// Checks if the list is void
	{
		PNode aux = first;
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

/*****************************************************************************/
// CHECK IF THE LIST IS SORTED
// Returns "true" if the list is sorted. Returns "false" in other case.
// A list is sorted when its numbers are stored from minor to major.
// Receives as argument a pointer to the first node.

bool IsItSorted (PNode first)
{
	bool sorted = true;

	if (!IsItVoid(first))			// Checks if the list is void
	{
		PNode aux = first;

		while ((aux->next) != 0)	// Compares all the values of the list
		{
			if ((aux->info) > ((aux->next)->info))
				sorted = false;

			aux = aux->next;
		}
	}

	return(sorted);
}

/*****************************************************************************/
// SORT A DISORDERED LIST
// If a list is disordered, this function sorts it following the order "from
// minor to major".
// Receives a reference to the first node.

void Sort (PNode &first)
{
	// Pointer which always points to the end of the "new sorted list" into
	// the actual list
	PNode aux1 = first;

	if (!IsItSorted(first))			// Checks if the list is void
	{
		while (aux1->next != 0)
		{			
			DataType minor = aux1->info;
			PNode minor_pos = aux1;

			// Pointer which covers all the list and searchs the lowest value
			PNode aux2 = aux1->next;

			while (aux2 != 0)
			{
				if ((aux2->info) < minor)	// A new minor value is found
				{
					minor = aux2->info;
					minor_pos = aux2;
				}
				aux2 = aux2->next;		// Goes on on the list
			}

			// Exchanges the minor for the value of the aux1 pointer
			DataType tmp = aux1->info;
			aux1->info = minor_pos->info;
			minor_pos->info = tmp;

			aux1 = aux1->next;
		}
	}
}

/*****************************************************************************/
// INSERT A VALUE INTO A SORTED LIST
// Inserts the indicated value in the position where it fits.
// Receives a reference to the first node and the value to insert.

void InsertValue (PNode &first, DataType n)
{
	if (!IsItSorted(first))			// Sorts the list in case it is not
	{
		Sort(first);
		InsertValue(first, n);
	}

	else if (IsItVoid(first))		// There isn't any node
	{
		first = new Node;
		first->info = n;
		first->next = 0;
	}

	else						// Right conditions to insert a value
	{
		PNode aux1 = first;		// Pointer that covers all the list
		PNode aux2 = first;		// The previous node to the inserted one

		bool go_on = true;

		while (go_on)
		{
			if (aux1 != 0)
			{
				if (aux1->info < n)		// Searchs a node with a major value
				{
					aux2 = aux1;
					aux1 = aux1->next;
				}
				else					// aux1 points to a major value than n
					go_on = false;
			}
			else					// aux1 has reached the end of the list
				go_on = false;
		}

		PNode inserted = new Node;		// Node to be inserted
		inserted->info = n;

		// Connects the inserted node with the actual list
		if (aux1 == first)
		{
			inserted->next = first;
			first = inserted;
		}

		else if (aux1 == 0)
		{
			aux2->next = inserted;
			inserted->next = 0;
		}

		else
		{
			aux2->next = inserted;
			inserted->next = aux1;
		}
	}
}
