#include "dll.h"
#include <stdlib.h>
#include <memory.h>

int
is_dll_empty (struct Node **head_ref){
 
    if(*head_ref == NULL)
      return 0;

    return -1;
}


void deleteNode( dll_t *dll, struct Node *del) 
{ 
   
   if(!dll) 
     return;

  struct Node** head_ref = (&dll->head);

  /* base case */
  if(*head_ref == NULL || del == NULL) 
    return; 
  
  /* If node to be deleted is head node */
  if(*head_ref == del) 
    *head_ref = del->next; 
  
  /* Change next only if node to be deleted is NOT the last node */
  if(del->next != NULL) 
    del->next->prev = del->prev; 
  
  /* Change prev only if node to be deleted is NOT the first node */
  if(del->prev != NULL) 
    del->prev->next = del->next;      
  
  /* Finally, free the memory occupied by del*/
  free(del); 
  return; 
} 



void deleteNodeAtGivenPos(dll_t * dll, int n) 
{ 

    if(!dll) 
    return;

    struct Node** head_ref = (&dll->head);

    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0) 
        return; 
  
    struct Node* current = *head_ref; 
    int i; 
  
    /* traverse up to the node at position 'n' from 
       the beginning */
    for (i = 1; current != NULL && i < n; i++) 
        current = current->next; 
  
    /* if 'n' is greater than the number of nodes 
       in the doubly linked list */
    if (current == NULL) 
        return; 
  
    /* delete the node pointed to by 'current' */
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
       
     /* swap next and prev for all nodes of  
       doubly linked list */
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     /* Before changing head, check for the cases like empty  
        list and list with only one node */
     if(temp != NULL ) 
        *head_ref = temp->prev; 
}      

