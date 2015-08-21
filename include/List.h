// List.h

#ifndef LIST 
#define LIST

typedef double DataType;

struct Node{
	DataType info;
	Node * next;
};

// Declaration of functions

Node * MakeNewList (void);
void ShowList (Node *);
void CleanMemory (Node *);
bool IsItVoid (Node *);

#endif
