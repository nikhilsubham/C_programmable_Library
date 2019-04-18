#include "dll.h"
#include <stdlib.h>
#include <memory.h>

int is_dll_empty (struct Node **head_ref){
 
   if(*head_ref == NULL)
       return 0;
   return -1;
}


void deleteNode( dll_t *dll, struct Node *del) 
{ 
  if(!dll) 
     return;

  if(dll->head == NULL || del == NULL) 
      return; 
  
  if(dll->head == del) 
      dll->head = del->next; 
  
  if(del->next != NULL) 
     del->next->prev = del->prev; 
  
  if(del->prev != NULL) 
     del->prev->next = del->next;      
  
  free(del); 
  return; 
} 


void deleteNodeAtGivenPos(dll_t * dll, int n) 
{ 
    if(!dll) 
       return;

    if (dll->head == NULL || n <= 0) 
        return; 
  
    struct Node* current = dll->head; 
    int i; 
  
    for (i = 1; current != NULL && i < n; i++) 
        current = current->next; 
  
    /* if n is greater than the number of nodes in the doubly linked list */
    if (current == NULL) 
        return; 
  
    deleteNode(dll, current); 
} 


/* Reversing a doubly linked list */
void reverse(dll_t* dll) 
{ 
     
     if(!dll) 
     return;

     struct Node** head_ref = (&dll->head);

     struct Node *temp = NULL;   
     struct Node *current = *head_ref; 
       
     /* swap next and prev for all nodes of doubly linked list */
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     /* Before changing head, check for the cases like empty list and list with only one node */
     if(temp != NULL ) 
        *head_ref = temp->prev; 
}      

