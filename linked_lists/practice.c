#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* link_test(): add a single node to the list*/
void link_test(struct node* head){
  struct node* newNode = head;

  newNode = malloc(sizeof(struct node));
  newNode->data = 1;
  head = newNode;
  printf("%p\n", head); 
}

/* length(): Get the length of a list */
int length(struct node* head){
  struct node* current = head;
  int count = 0;

  while (current != NULL){
    count++;
    current = current->next;
  }

  return count;
}

/* BuildOneTwoThree(): Builds a linked list with three structs*/
struct node* BuildOneTwoThree(){
  // set nodes to null
  struct node* head = NULL;
  struct node* tail = NULL;

  // allocate memory in the heap
  for (int i = 0; i < 4; i++){
    //create first node
    if (i == 0){
      head = tail = malloc(sizeof(struct node));
      tail->data = i + 1;
      tail->next = NULL;
      printf("tail->data: %d\n", tail->data);
      printf("tail->next: %p\n", tail->next);
    }
    // create other nodes
    else {
      tail->next = malloc(sizeof(struct node)); // adding new node
      tail->next->data = i + 1;
      tail->next->next= NULL;
      tail = tail->next;
      printf("tail->data: %d\n", tail->data);
      printf("tail->next: %p\n", tail->next);
    }
  }
  // cant make it better at this moment...

//  // setup first node
//  head->data = 1;
//  head->next = second;
//  printf("head->data %d\n",head->data);
//  printf("head->next %p\n",head->next);// before second, second address; 0x600000570050
//  
//  // setup second node
//  second->data = 2;
//  second->next = third;
//  printf("second->data %d\n",second->data);
//  printf("second->next %p\n",second->next); // after head, third address; 0x600000570060
//
//  // setup third node
//  third->data = 3;
//  printf("third->data %d\n",third->data);
//  printf("third->next %p\n",third->next); // address that's null

  // At this point the list is {1,2,3}
  return head;

}

int main(void){

  // functions here
  // print struct
  struct node *head = BuildOneTwoThree();
  struct node *node;
  // print list
  for (node = head; node != NULL; node = node->next){
    printf("%d ", node->data);
  }
  printf("\n");
  //link test - add node
  link_test(head);
  // count list
  int list_length = length(head);
  printf("list_length: %d\n", list_length);
  printf("\n");

  return 0;

}
