#ifndef BASIC_H 
#define BASIC_H

// basic structure for all problems
struct node* node{
  int data;
  struct node* next;
};

/* ONLY USEFUL FOR LINKED LISTS
   print_list : prints the linked list
   link_free : free all the nodes
   list_length : counts how many items in list
   push : does the allocation
*/
void print_list(struct node* head);
void link_free(struct node* head);
int list_length(struct node* head);
void push(struct node** head, int data);

#endif
