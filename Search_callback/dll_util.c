#include "dll.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

int is_dll_empty (struct Node **head_ref){
 
   if(*head_ref == NULL)
       return 0;
   return -1;
}


int deleteNode( dll_t *dll, struct Node *del) 
{ 
  if(!dll) 
     return -1;

  if(dll->head == NULL || del == NULL) {
      printf("\nThe node is not present in DLL\n");
      return -1;
    }
 
  if(dll->head == del)
      dll->head = del->next; 
  
  if(del->next != NULL) 
     del->next->prev = del->prev; 
  
  if(del->prev != NULL) 
     del->prev->next = del->next;
  
  free(del); 
  return 0; 
} 



int deleteNodeAtGivenPos(dll_t * dll, int n) 
{ 
    if(!dll) 
       return -1;

    if (dll->head == NULL || n <= 0) 
        return -1; 
  
    struct Node* current = dll->head; 
    int i; 
  
    for (i = 1; current != NULL && i < n; i++) 
        current = current->next; 
  
    /* if n is greater than the number of nodes in the doubly linked list */
    if (current == NULL) 
        return -1; 
  
    return deleteNode(dll, current); 
} 



int delete_node_by_value(dll_t * dll, void *data)
{
    if(!dll || ! (dll->head)) 
        return -1;

    struct Node*  trav = dll->head;

    while(trav != NULL){
        if(trav->data == data)
            return deleteNode(dll, trav);
	trav = trav->next;
    }
    return 0;
}


void removeNode( dll_t *dll, struct Node *del) 
{ 
  if(!dll) 
     return;

  if(dll->head == NULL || del == NULL){
      printf("\nThe node for removing is not present in DLL\n"); 
      return;
    }
 
  if(dll->head == del)
      dll->head = del->next; 
  
  if(del->next != NULL) 
     del->next->prev = del->prev; 
  
  if(del->prev != NULL) 
     del->prev->next = del->next;
 
  //free(del); 
  return;
} 



void remove_node_by_value(dll_t * dll, void *data)
{
    struct Node* node;
    if(!dll || ! (dll->head)) 
        return;

    struct Node*  trav = dll->head;

    while(trav != NULL){
        if(trav->data == data){
            removeNode(dll, trav);
	    return;
        }
        trav = trav->next;
    }
    return;
}




/* Reversing a doubly linked list */
void reverse(dll_t* dll) 
{ 
     if(!dll) 
     return;

     struct Node *temp = NULL, *current = dll->head;   
     
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
       dll->head = temp->prev; 
}   



/* This function will detect and remove loop if present*/
void Detect_remov_loop(dll_t* dll)
{
   if(!dll || ! (dll->head)) 
        return;

   struct Node*  trav = dll->head;
   
   while(trav->next)
     {
         if(trav->next->prev != trav)
           {
             printf("\nThere is loop detected\n");
             trav->next = NULL;  
             return; 
           }
         trav = trav->next;
     }
   printf("\nThere is no loop detected\n");
   return;
}   

