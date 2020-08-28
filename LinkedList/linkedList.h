#include <stdio.h>
#define NEW_NODE {NULL, NULL, NULL}

struct Node {
  void* data;
  struct Node* nextNode;
  struct Node* previousNode;
};

struct LinkedList {
  struct Node* firstNode;
  unsigned int size;
};

// Adds the node passed as argument to the end of the list
int add(struct Node*, struct Node*, struct LinkedList*);

// Ads to last location of linked list
int addToLastLocation(struct Node*, struct LinkedList*);
//
// Ads to location location of linked list
int addToIndex(struct Node*, struct LinkedList*, int location);

// Return a pointer to the node at location passed by argument
struct Node* getNode(int, struct LinkedList*);

struct Node* getLastNode(struct LinkedList* list);

// Removes the last node on the list
int del(struct Node*, struct LinkedList*);
