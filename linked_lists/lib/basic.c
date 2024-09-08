#include <stdio.h>
#include <stdlib.h>
#include "basic.h"

struct node* node;

void print_list(struct node* head){
  struct node* node = head;

  for (node = head; node != NULL; node = node->next){
    printf("%d ", node->data);
  }
  printf("\n");
}

int list_length(struct node* head){
  struct node* current = head;
  int count = 0;

  while (current != NULL){
    count++; 
    current = current->next;
  }
  return count;
}

void link_free(struct node* head){
  struct node* temp;
  struct node* current = head->next; 

  while (current != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
  free(head);
}

void push(struct node** head, int data){
  struct node* new_node = malloc(sizeof(struct node));

  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}
