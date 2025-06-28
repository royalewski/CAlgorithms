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
  newNode->next = NULL;
  newNode->value = input;
  newNode->next = *head;
  *head = newNode;
}
void insertAtEnd(Node **head, int input){
  Node *newNode = malloc(sizeof(Node));
  if(newNode == NULL){
    printf("Allocation Failed");
    return;
  }
  newNode->value = input;
  newNode->next = NULL;

  Node *temp = *head;
  if (*head == NULL) {
    *head = newNode;
    return;
}
  while(temp->next != NULL){
    temp = temp->next;   
  }
  temp->next = newNode;
}
void insertAtSorted(Node **head, int input){
  Node *newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
  newNode->value = input;
  newNode->next = NULL;

  if (*head == NULL || input < (*head)->value){
    newNode->next = *head;
    *head = newNode;
    return;
  }
  Node *lag = *head;
  Node *lead = (*head)->next;

  while(lead != NULL && input >= lead->value){
    lag = lead;
    lead = lead->next;
  }
  
  newNode->next = lead;
  lag->next = newNode;
  return;

}
void printList(Node *head){
   Node* temp = head;
  while(temp != NULL){
    printf("%d -> ", temp->value);
    temp = temp->next;
  }
}
void bubbleSort(Node **head){
  
  if(*head == NULL || (*head)->next == NULL){
    printf("Nothing to sort");
    return;
  }
  int swapFlag = 0;
  
  do{
    swapFlag = 0;
    Node **lag = head;
    Node *mid = *head;
    Node *lead = mid->next; 
    while (lead != NULL){
      if (mid->value > lead->value){
        mid->next = lead->next;
        lead->next = mid;
        *lag = lead;
        Node *temp = mid;
        mid = lead;
        lead = temp;
        swapFlag = 1;
      }
      lag = &mid->next;
      mid = mid ->next;
      lead = (mid != NULL) ? mid->next : NULL;
    }
  }while (swapFlag);
  return;
}
void deleteNode(Node **head, int targetValue){
  if (*head == NULL) {
  printf("List is empty!\n");
  return;
  }
  Node *lead = *head;
  Node *lag = NULL;

  while (lead != NULL) {
    if (lead->value == targetValue) {
      if (lag == NULL) {
        // usuwanie pierwszego elementu
        *head = lead->next;
      } else {
        lag->next = lead->next;
      }
      free(lead);
      return;
    }
    lag = lead;
    lead = lead->next;
  }
  printf("No value found!\n");
  return;
}
void deleteAllValues(Node **head, int targetValue){
  if (*head == NULL) {
  printf("List is empty!\n");
  return;
  }
  Node *lead = *head;
  Node *lag = NULL;
  int foundFlag = 0;
  while (lead != NULL) {
    if (lead->value == targetValue) {
      foundFlag = 1;
      if (lag == NULL) {
        // usuwanie pierwszego elementu
        *head = lead->next;
      } else {
        lag->next = lead->next;
      }
      Node* temp = lead;
      lead = lead -> next;
      free(temp);
      continue;
    }
    lag = lead;
    lead = lead->next;
  }
  if(!foundFlag)
   printf("No value found!\n");
  return;
}
int lengthOfList(Node *head) {
    int listLength = 0;
    while (head != NULL) {
        listLength++;
        head = head->next;
    }
    return listLength;
}
void freeList(Node **head){
  if (*head == NULL) return;

  Node *lead = (*head)->next;
  Node *lag = *head;
  do{
    free(lag);
    lag = lead;
    lead = lead->next;
  }while(lead != NULL);

  free(lag);
  *head = NULL;
  return;
}
Node* findInList(Node **head, int targetValue){
  Node *temp = *head;
  while (temp != NULL) {
    if (temp->value == targetValue) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
void reverseList(Node** head){
 Node *lag = NULL;
 Node *mid = *head;
 Node *lead = NULL;
 while(mid != NULL){
  lead = mid->next;
  mid->next = lag;
  lag = mid;
  mid = lead;
 }
 *head = lag;
 return;
}


int main(){
  return 0;
}