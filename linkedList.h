#include <stdio.h>
#define NEW_NODE {NULL, NULL, NULL}

struct Node {
  void* data;
  struct Node* nextNode;
  struct Node* previousNode;
};

struct LinkedList {
  struct Node* firstNode;
  int size;
};

// Returns the previous node on the list
struct Node* previousNode(struct Node*);

// Returns the next node on the list
struct Node* nextNode(struct Node*);

// Adds the node passed as argument to the end of the list
int add(struct Node*, struct Node*);

// Ads to last location of linked list
int addToLastLocation(struct Node*, struct LinkedList*);
//
// Ads to location X of linked list
int addToXLocation(struct Node*, struct LinkedList*, int location);

// Return a pointer to the node at location passed by argument
struct Node* getNode(int);

struct Node* getLastNode(struct LinkedList* list);

// Removes the last node on the list
int del(struct Node*);
