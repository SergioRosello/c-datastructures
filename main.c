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
  struct Node fifthNode = NEW_NODE;
  fifthNode.data = "Data from fifth node!\n";

  struct LinkedList llist = {NULL, 0};
  llist.firstNode = &firstNode;
  llist.size = 5;

  add(&firstNode, &secondNode);
  add(&secondNode, &thirdNode);
  add(&secondNode, &fifthNode);
  add(&firstNode, &fourthNode);
  printList(&llist);
  del(&secondNode);
  printList(&llist);

  struct Node* lastNode = getLastNode(&llist);
  printf("Last node data: %s\n", (char *) lastNode->data);
  return 0;
}

void printList(struct LinkedList* llist){
  int i = 0;
  printf("Node %d data: %s\n", i, (char *) llist->firstNode->data);
  i++;
  while (llist->firstNode->nextNode != NULL) {
    printf("Node %d data: %s\n", i, (char *) llist->firstNode->nextNode->data);
    i++;
    llist->firstNode = llist->firstNode->nextNode;
  }
}