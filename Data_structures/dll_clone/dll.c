#include "dll.h"
#include <memory.h>
#include <stdlib.h>

/* Public Function Implementation to create and return new empty doubly linked list*/
dll_t* get_new_dll(){

    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;
}

/* Appends a new node at the front of the list */
void Add_front(dll_t *dll, void* app_data) 
{ 
    if(!dll || !app_data) 
     return;

    dll_node_t* new_node = (dll_node_t*)calloc(1,sizeof(dll_node_t)); 
    new_node->data = app_data; 
    new_node->left = NULL; 
    new_node->right = dll->head; 
    
    if ((dll->head) != NULL) 
        (dll->head)->left = new_node; 
  
    dll->head = new_node; 
}



