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

/*********************************************************/
// FUNCTION PROTOTYPES

// List management functions
Node * MakeNewList (void);
void ShowList (Node *);
void CleanMemory (Node *);

// List characteristics functions
bool IsItVoid (Node *);
int NumberOfNodes (Node *);

// Statistical functions
DataType Mean (Node *);
DataType Variance (Node *);

#endif
