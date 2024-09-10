#include <stdio.h>
#include <stdlib.h>
#include "lib/basic.h"

struct node* create_list(){
  struct node* head = NULL;
  struct node* tail = NULL;
  
  int size;
  int n;

  // prompt for size 
  printf("size of linked list: ");
  scanf("%d", &size);

  // prompt for each size
  printf("list_element: ");
  scanf("%d", &n);
  push(&head, n);
  tail = head;

  for (int i = 1; i < size; i++){
    printf("list_element: ");
    scanf("%d", &n);
    push(&tail->next, n);
    tail = tail->next;
  }

  return head;
}


int Count(struct node* head, int search_for); 
int get_nth(struct node* head, int index);
void delete_list(struct node** head_ref);
int pop(struct node** head_ref);
void insert_nth(struct node** list_ref, int index, int data);

int main(int argc, char* argv[]){
/*
  struct node* head = create_list(); 
  print_list(head);
  printf("list_length: %d\n", list_length(head));

  // exercise 1 ; Count()
  int count_func = Count(head, 3);
  printf("count_func: %d\n", count_func);

  // exercise 2 ; GetNth()
  int last_node = get_nth(head, 2);
  if (last_node == -1){
    printf("index is invalid, outside 0, or length-1 exceeded\n"); 
  }
  printf("last node: %d\n", last_node);
*/

  // exercise 3 ; delete_list()
  // checked with valgrind there's still 1 memory block not freed, meaning the head is NULL
  /*delete_list(&head); 
  if(head == NULL){
    printf("print deleted succesfully\n");
  }
  */

  // exercise 4 ; pop() == done
  /*int a = pop(&head); 
  int b = pop(&head); 
  int c = pop(&head); 
  printf("pop_func a: %d\n", a);
  printf("pop_func b: %d\n", b);
  printf("pop_func c: %d\n", c);
  print_list(head);
  printf("list_length: %d\n", list_length(head));
  if (list_length(head) == 0){
    return -1;
  }
  */

  // exercise 5; insert_nth()
  struct node* list = NULL;
  insert_nth(&list, 0, 13);
  //insert_nth(&list, 1, 42);

  // free
//  link_free(head);
  link_free(list);
  return 0;
}

void insert_nth(struct node** list_ref, int index, int data){
  // allocate
  struct node* new_node = malloc(sizeof(struct node));
  struct node* current = NULL;
  
  // create a list if no nodes
  if (*list_ref == NULL){
    new_node->data = data;
    new_node->next = *list_ref;
    *list_ref = new_node;
  }
  current = *list_ref;
  // loop when in index create node
  int count = 0;
  while (current != NULL){
    if (index == count){
      new_node->data = data;
      new_node->next = current;
      current = new_node;
      break;
    }
    current = current->next;
    count++;
  }
  printf("list_length: %d\n", list_length(*list_ref));
  print_list(*list_ref);
}

int pop(struct node** head_ref){

// allocate
  struct node* new_head = (*head_ref)->next;
  int trunq;
  // get data
  trunq = (*head_ref)->data;
  // free head
  free(*head_ref);
  // head is next node
  *head_ref = new_head;
 // return truncated data
 return trunq;


}

void delete_list(struct node** head_ref){
  struct node* temp;
  struct node* current = (*head_ref)->next;

  while (current != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
  *head_ref = NULL;
}

int get_nth(struct node* head, int index){
  struct node* current = head; 
  int idx_count;

  while (current != NULL){
    if (idx_count == index){
      return current->data;
    }
    else {
      idx_count++;
      current = current->next;
    }
  }
  return -1;
}

int Count(struct node* head, int search_for){
  struct node* current = head;
  int count = 0;

  while (current != NULL){
    if (current->data == search_for){
      count++;
    }
    current = current->next;
  }
  return count;
}

















