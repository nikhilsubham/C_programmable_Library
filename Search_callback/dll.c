#include "dll.h"
#include <memory.h>
#include <stdlib.h>
#include<stdio.h>

/* Public Function Implementation to create and return new empty doubly linked list*/
dll_t * get_new_dll()
{
    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    dll->key_match = NULL;
    return dll;
}

void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void *))
{
    dll->key_match = key_match;
}


/*Generic Search function*/
void *dll_search_by_key (dll_t *dll, void *key)
{
    if(!dll || !dll->head) return NULL;

    struct Node *head = dll->head;

    while(head){
        if(dll->key_match(head->data, key) == 0)
            //return (void *)head->data;
            return (void *)head;
        head = head->next;
    }
    return NULL;
}


/* Appends a new node at the front of the list */
void Add_front(dll_t *dll, void* app_data) 
{ 
    if(!dll || !app_data) 
     return;

    struct Node* new_node = (struct Node*)calloc(1,sizeof(struct Node)); 
    new_node->data = app_data; 
    new_node->prev = NULL; 
    new_node->next = dll->head; 
    
    if ((dll->head) != NULL) 
        (dll->head)->prev = new_node; 
  
    dll->head = new_node; 
}



/* Appends a new node at the end of the list */
void Add_atend(dll_t *dll, void* app_data) 
{ 
        if(!dll || !app_data) 
        return;

        struct Node* new_node = (struct Node*)calloc(1,sizeof(struct Node)); 
        new_node->data = app_data; 
        new_node->next = NULL; 
        struct Node* last = dll->head; 
        
        if(dll->head == NULL) { 
		new_node->prev = NULL; 
		dll->head = new_node; 
		return; 
	} 

	while (last->next != NULL) 
		last = last->next; 

	last->next = new_node; 
        new_node->prev = last; 
        return; 
}


void insertAfter(struct Node* prev_node, void* new_data) 
{ 
    if (prev_node == NULL) { 
        printf("\nThe given previous node cannot be NULL"); 
        return; 
    } 

    struct Node* new_node = (struct Node*)calloc(1,sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
    new_node->prev = prev_node; 
  
    /* Change previous of new_node's next node */
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
} 



void insertBefore(struct Node* next_node,void* new_data) 
{ 
    if (next_node == NULL) { 
        printf("the given next node cannot be NULL"); 
        return; 
    } 

    struct Node* new_node = (struct Node*)calloc(1, sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->prev = next_node->prev; 
    next_node->prev = new_node; 
    new_node->next = next_node; 
  
    /* Change next of new_node's previous node */
    if (new_node->prev != NULL) 
        new_node->prev->next = new_node; 
} 
 



/* Public Function Implementation to add a new application data to DLL
int add_data_to_dll (dll_t *dll, void *app_data){

    if(!dll || !app_data) return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(struct Node));
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    /*Now add this to the front of DLL
    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    dll_new_node->right = first_node;
    first_node->left = dll_new_node;
    dll->head = dll_new_node;
    return 0;
}

*/

