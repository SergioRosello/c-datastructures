#include "linkedList.h"
#include <stdio.h>

void printList(struct LinkedList*);

int main(int argc, char *argv[])
{
  struct Node firstNode = NEW_NODE;
  firstNode.data = "Data from First node!\n";
  struct Node secondNode = NEW_NODE;
  secondNode.data = "Data from second node!\n";
  struct Node thirdNode = NEW_NODE;
  thirdNode.data = "Data from third node!\n";
  struct Node fourthNode = NEW_NODE;
  fourthNode.data = "Data from fourth node!\n";

  struct LinkedList llist = {NULL, 0};

  addToLastLocation(&firstNode, &llist);
  addToLastLocation(&secondNode, &llist);
  addToLastLocation(&thirdNode, &llist);

  printList(&llist);

  printf("Deleting second node\n");
  del(&secondNode, &llist);
  printf("Deleting third node\n");
  del(&thirdNode, &llist);
  printList(&llist);
  printf("Deleting first node\n");
  del(&firstNode, &llist);
  printList(&llist);

  addToLastLocation(&fourthNode, &llist);
  printf("Added to last location\n");
  printList(&llist);

  return 0;
}

void printList(struct LinkedList* llist){
  printf("List size: %d\n", llist->size);
  if(llist->firstNode != NULL){
    int i = 1;
    struct Node* tmp = llist->firstNode;
    printf("Node %d data: %s", i, (char *) tmp->data);
    i++;
    while (tmp->nextNode != NULL) {
      printf("Node %d data: %s", i, (char *) tmp->nextNode->data);
      i++;
      tmp = tmp->nextNode;
    }
  }
}
