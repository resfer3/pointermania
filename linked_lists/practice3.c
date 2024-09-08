#include <stdio.h>
#include <stdlib.h>
#include "lib/basic.h"

struct node* create_list(){
  struct node* head = NULL;
  struct node* tail = NULL;
  
  push(&head, 1);
  tail = head;

  for (int i = 2; i < 5; i++){
    push(&tail->next, i);
    tail = tail->next;
  }

  return head;
}

int main(int argc, char* argv[]){
  struct node* head = create_list(); 
  print_list(head);
  list_length(head);
  link_free(head);
}


