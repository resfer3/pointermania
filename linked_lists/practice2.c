#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void print_linked_list(struct node* head);
void free_linked_list(struct node* head);
void push(struct node** head, int data);
struct node* create_list_at_head();
struct node* create_list_at_tail();
struct node* copy_list2(struct node* head);

int main(void){
  // create linked list
  //struct node* head = create_list_at_head(); 
  struct node* head = create_list_at_tail();
  // print list
  print_linked_list(head);

  printf("\n");

  // copylist2
  struct node* copy = copy_list2(head); 
  print_linked_list(copy);
  printf("\n");
  // free list
  free_linked_list(copy);
  free_linked_list(head);
  printf("linked list freed\n");
  printf("linked list copy freed\n");

  return 0;
}

struct node* copy_list2(struct node* head){
  struct node* current = head; // iterate over original list
  struct node* new_head = NULL; 
  struct node* tail = NULL;

  while(current != NULL){
    if (new_head == NULL){
      push(&new_head, current->data);
      tail = new_head;
      tail = new_head;
    }
    else {
      push(&tail->next, current->data); 
      tail = tail->next;
    }
    current = current->next;
  }

  return new_head;
  
}

void push(struct node** head, int data){
  struct node* new_node = malloc(sizeof(struct node));

  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

struct node* create_list_at_tail(){
  struct node* head = NULL;
  struct node* tail = NULL;
  int first_input;
  int rest_of_inputs;
  int length;

  printf("which size the linked list: ");
  scanf("%d", &length);
  
  printf("data_to_input: ");
  scanf("%d", &first_input);
  push(&head, first_input);
  tail = head;

  for (int i = 1; i < length; i++){
    printf("data_to_input: ");
    scanf("%d", &rest_of_inputs);
    push(&tail->next, rest_of_inputs); // add node at tail->next
    tail = tail->next;                   // advance tail to point to last node
  }

  return head;
}

struct node* create_list_at_head(){
  struct node* head = NULL;

  int length; 
  int data_input;
  printf("which size the linked list: ");
  scanf("%d", &length);

  for (int i = 0; i < length; i++){
    printf("input data: ");
    scanf("%d", &data_input);
    push(&head, data_input);
  }

  return head;

}

void print_linked_list(struct node* head){
  struct node* current = head;

  while(current != NULL){
    printf("%d ", current->data);
    current = current->next;
  }
}

void free_linked_list(struct node* head){
  struct node* temp;
  struct node* current = head->next;

  while(current != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
  free(head);
}

