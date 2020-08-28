#include "linkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int add(struct Node* node, struct Node* newNode, struct LinkedList* list){
  // If the list is empty
  if(node == NULL){
    // Make this node the first node of the list (We need the list)
    printf("Empty list\n");
    list->firstNode = newNode;
  }
  // If node is not the end of the list:
  else if(node->nextNode != NULL){
    // If the node is the first of the list
    // else if(node->previousNode == NULL && node->nextNode != NULL){
    printf("middle list\n");
    newNode->nextNode = node->nextNode;
    newNode->previousNode = node;
    node->nextNode = newNode;
  }
  else{ // If node is at the end of the list
    printf("end list\n");
    node->nextNode = newNode;
    newNode->previousNode = node;
    newNode->nextNode = NULL;
  }
  list->size++;
  return 0;
}

// Ads to last location of linked list
int addToLastLocation(struct Node* node, struct LinkedList* list){
  struct Node* last = getLastNode(list);
  add(last, node, list);
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

int addToFirstLocation(struct Node* node, struct LinkedList* list){
  node->previousNode = NULL;
  node->nextNode = list->firstNode;
  list->firstNode->previousNode = node;
  list->firstNode = node;
  list->size++;
  return 0;
}

// Ads to location X of linked list
// TODO: Check index at which node is added 
int addToIndex(struct Node* node, struct LinkedList* list, int location){
  struct Node* tmp = NULL;
  assert(location < list->size);
  if(location == 0){
    addToFirstLocation(node, list);
  }else{
    tmp = getNode(location, list);
    // node, next, list
    // When we add the node to the index, it doesnt have enther a previousNode or a nextNode.
    add(tmp, node, list);
    printf("tmp node data: %s\n", (char*) tmp->data);
  }
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
  printf("GetNode return: %s\n", (char*) tmp->data);
  return tmp;
}

int del(struct Node* node, struct LinkedList *list){
  // If it is at the middle of the list:
  if(node->nextNode != NULL && node->previousNode != NULL){
    printf("Deleting a node in the middle of the list\n");
    node->previousNode->nextNode = node->nextNode;
    node->nextNode->previousNode = node->previousNode;
  }
  // If it the last element node on the list
  else if(node->previousNode != NULL && node->nextNode == NULL){ 
    printf("Last element on list deletion\n");
    node->previousNode->nextNode = NULL;
  } 
  // It's the first element of the list
  else if(node->previousNode == NULL && node->nextNode != NULL){
    printf("First node of list going to be deleted\n");
    node->previousNode = NULL;
    list->firstNode = node->nextNode;
    list->firstNode->previousNode = NULL;
  }
  // If it the only element in the list
  else if(node->previousNode == NULL && node->nextNode == NULL){ 
    list->firstNode = NULL;
  }
  node = NULL;
  // Subtract 1 from linked list counter
  list->size--;
  return 0;
}
