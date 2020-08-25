#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


struct Node* previousNode(struct Node* node){
  return node->previousNode;
}

struct Node* nextNode(struct Node* node){
  return node->nextNode;
}

int add(struct Node* node, struct Node* last, struct LinkedList* list){
  // If the list is empty
  if(node == NULL){
    // Make this node the first node of the list (We need the list)
    list->firstNode = last;
  }
  // If node is not the end of the list:
  else if(node->nextNode != NULL){
    last->nextNode = node->nextNode;
    last->previousNode = node;
    node->nextNode = last;
  }
  else{ // If node is at the end of the list
    node->nextNode = last;
    last->previousNode = node;
    last->nextNode = NULL;
  }
  list->size++;
  return 0;
}
//
// Ads to last location of linked list
int addToLastLocation(struct Node* node, struct LinkedList* list){
  struct Node* lastNode = getLastNode(list);
  add(lastNode, node, list);
  return 0;
}

// Returns a pointer to the last node from the list
struct Node* getLastNode(struct LinkedList* list){
  struct Node* tmp = list->firstNode;
  while (list->firstNode != NULL && tmp->nextNode != NULL) {
    tmp = tmp->nextNode;
  }
  return tmp;
}

// Ads to location X of linked list
int addToIndex(struct Node* node, struct LinkedList* list, int location){
  struct Node* tmp = getNode(location, list);
  add(tmp, node, list);
  return 0;
}

struct Node* getNode(int index, struct LinkedList* list){
  struct Node* tmp = NULL;
  if (index < list->size){
    tmp = list->firstNode;
    for (int i = 1; i < index && tmp; ++i) {
      tmp = tmp->nextNode;
    }
  }
  return tmp;
}

int del(struct Node* node, struct LinkedList *list){
  // If it is at the middle of the list:
  if(node->nextNode != NULL && node->previousNode != NULL){
    printf("Deleting a node in the middle of the list\n");
    node->previousNode->nextNode = node->nextNode;
    node->nextNode->previousNode = node->previousNode;
  }
  else if(node->previousNode != NULL && node->nextNode == NULL){ // If it the last element node on the list
    printf("Last element on list deletion\n");
    node->previousNode->nextNode = NULL;
  } 
  // It's the first element of the list
  else if(node->previousNode == NULL && node->nextNode != NULL){
    printf("First node of list going to be deleted\n");
    list->firstNode = node->nextNode;
    node->nextNode->previousNode = list->firstNode;
  }
  else if(node->previousNode == NULL && node->nextNode == NULL){ // If it the only element in the list
    list->firstNode = NULL;
  }
  node = NULL;
  // Subtract 1 from linked list counter
  list->size--;
  return 0;
}
