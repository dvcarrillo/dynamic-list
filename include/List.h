// List.h

#ifndef LIST 
#define LIST

// Define the type of data that the list is going to use
typedef double DataType;

// Struct dedicated to store the information of each node
struct Node{
	DataType info;
	Node * next;
};

typedef Node * PNode;		// Pointer to a node

/*********************************************************/
// FUNCTION PROTOTYPES

// List management functions
PNode MakeNewList (void);
void ShowList (PNode);
void CleanMemory (PNode);

// List characteristics functions
bool IsItVoid (PNode);
int NumberOfNodes (PNode);

// Statistical functions
DataType Mean (PNode);
DataType Variance (PNode);

// Ordination functions
bool IsItSorted (PNode);
void Sort (PNode &);

// Data management functions
void InsertValue (PNode &, DataType);

#endif
