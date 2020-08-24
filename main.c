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
  llist.firstNode = &firstNode;

  add(&firstNode, &secondNode, &llist);
  add(&secondNode, &thirdNode, &llist);

  printList(&llist);

  printf("Deleting second node\n");
  del(&secondNode, &llist);
  printf("Finished Deleting second node\n");
  printf("Deleting third node\n");
  del(&thirdNode, &llist);
  printf("Finished Deleting third node\n");
  printList(&llist);
  printf("Deleting first node\n");
  del(&firstNode, &llist);
  printf("Finished Deleting first node\n");
  //printList(&llist);

  //add(llist.firstNode, &fourthNode, &llist);
  addToLastLocation(&fourthNode, &llist);
  printf("Added to last location\n");
  printList(&llist);

  return 0;
}

void printList(struct LinkedList* llist){
  if(llist->firstNode != NULL){
    int i = 1;
    struct Node* tmp = llist->firstNode;
    printf("Node %d data: %s\n", i, (char *) tmp->data);
    i++;
    while (tmp->nextNode != NULL) {
      printf("Node %d data: %s\n", i, (char *) tmp->nextNode->data);
      i++;
      tmp = tmp->nextNode;
    }
  }
}
