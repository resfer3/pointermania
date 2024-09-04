#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

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

/* BuildOneTwoThree(): Builds a linked list */
struct node* BuildOneTwoThree(int size){
  // set nodes to null
  struct node* head = NULL;
  struct node* tail = NULL;
  int tmp = 0;
  
  // allocate memory in the heap
  for (int i = 0; i < size; i++){
    //create first node
    if (i == 0){
      printf("get value: ");
      scanf("%d",&tmp);
      head = tail = malloc(sizeof(struct node));
      tail->data = tmp;
      tail->next = NULL;
      printf("tail->data: %d\n", tail->data);
      printf("tail->next: %p\n", tail->next);
    }
    // create other nodes
    else {
      printf("get value: ");
      scanf("%d",&tmp);
      tail->next = malloc(sizeof(struct node)); // adding new node
      tail->next->data = tmp;
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
  printf("address head: %p\n", head);
  return head;

}

/* link_test(): add a single node to the list*/
struct node* BuildTwoThree(){
  struct node* head = NULL; 
  struct node* final = NULL; 

  head = malloc(sizeof(struct node));
  final = malloc(sizeof(struct node));

  head->data = 2;
  head->next = final;

  final->data = 3;
  // null

  return head;
}
struct node* link_test(){
  int size = 0;
  printf("get size: ");
  scanf("%d", &size);
  struct node* head = BuildOneTwoThree(size);
  struct node* new_node;

  new_node = malloc(sizeof(struct node)); //allocate
  new_node->data = 10;
  // link next
  new_node->next = head;
  //link head
  head = new_node;
  printf("head = newNode: %d\n", head->data);
  printf("head = newNode: %p\n", head);
  

  int list_length = length(head);
  printf("list_length: %d\n", list_length);

  return head;

}



int main(void){

  // functions here
  // print struct
  // prompt for number of elements
  //int size = 0;
  //printf("Linked List Size: ");
  //scanf("%d", &size);
  // allocate structs
  //struct node *head = BuildOneTwoThree(size);
  //struct node *node;
//  for (node = head; node != NULL; node = node->next){
//    printf("%d ", node->data);
//  }
//  printf("\n");

  // link test - add node
  struct node* head = link_test();
  struct node* node;
  for (node = head; node != NULL; node = node->next){
  printf("%d ", node->data);
  }
  printf("\n");
  // count list
  //int list_length = length(head);
  //printf("list_length: %d\n", list_length);
  //printf("\n");
  // count list
  

  return 0;

}
