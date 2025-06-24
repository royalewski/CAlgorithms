#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};
typedef struct Node Node;

void insertAtBeggining(Node **head, int input){
  Node *newNode = malloc(sizeof(Node)); 
  if(newNode == NULL){
    printf("Allocation Failed");
    return;
  }
  newNode->value = input;
  newNode->next = *head;
  *head = newNode;
}
void printList(Node *head){
   Node* temp = head;
  while(temp != NULL){
    printf("\nValue: %d", temp->value);
    temp = temp->next;
  }
  temp = head;
}
int main(){

  printf("\e[1;1H\e[2J");
  Node *head = NULL;
  for (int i = 0; i < 5; i++)
    insertAtBeggining(&head, i);
  printList(head);  
  return 0;
}