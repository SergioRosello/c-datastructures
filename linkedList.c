#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


struct Node* previousNode(struct Node* node){
  return node->previousNode;
}

struct Node* nextNode(struct Node* node){
  return node->nextNode;
}

int add(struct Node* node, struct Node* last){
  // If node is not the end of the list:
  if(node->nextNode != NULL){
    last->nextNode = node->nextNode;
    last->previousNode = node;
    node->nextNode = last;
  }
  else{ // If node is at the end of the list
    node->nextNode = last;
    last->previousNode = node;
  }
  return 0;
}
//
// Ads to last location of linked list
int addToLastLocation(struct Node* node, struct LinkedList* list){
  // If list has no nodes:
  if(list->firstNode == NULL){
    struct Node newNode = NEW_NODE;
    list->firstNode = &newNode;
  }
  else{
    struct Node* lastNode = getLastNode(list);
    add(lastNode, node);
  }

  return 0;
}

struct Node* getLastNode(struct LinkedList* list){
  struct Node* tmp = list->firstNode;
  for (int i = 0; i < list->size; ++i) {
    printf("Node %d\n", i);
    //tmp = tmp->nextNode;
  }
  return tmp;
}

//
// Ads to location X of linked list
int addToXLocation(struct Node* node, struct LinkedList* list, int location){
  return 0;
}

struct Node* getNode(int location);

int del(struct Node* node){
  // If it is at the middle of the list:
  if(node->nextNode != NULL){
    node->previousNode->nextNode = node->nextNode;
  }
  else{ // If it is at the end of the list
    node->previousNode->nextNode = NULL;
  }
  // Subtract 1 from linked list counter
  return 0;
}
