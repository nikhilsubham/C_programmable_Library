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


/* Given a reference (pointer to pointer) to the head of a DLL and a data, appends a new node at the end of the list */
void Add_front(dll_t *dll, void* app_data) 
{ 
    if(!dll || !app_data) 
     return;

    struct Node** head_ref = (&dll->head);

    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    /* 2. put in the data  */
    new_node->data = app_data; 
  
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node; 
}


/* Given a reference (pointer to pointer) to the head of a DLL and a data, appends a new node at the end of the list */
void Add_atend(dll_t *dll, void* app_data) 
{ 

        if(!dll || !app_data) 
        return;

        struct Node** head_ref = (&dll->head);

	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	struct Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = app_data; 

	/* 3. This new node is going to be the last node, so 
		make next of it as NULL*/
	new_node->next = NULL; 

	/* 4. If the Linked List is empty, then make the new 
		node as head */
	if (*head_ref == NULL) { 
		new_node->prev = NULL; 
		*head_ref = new_node; 
		return; 
	} 

	/* 5. Else traverse till the last node */
	while (last->next != NULL) 
		last = last->next; 

	/* 6. Change the next of last node */
	last->next = new_node; 

	/* 7. Make last node as previous of new node */
	new_node->prev = last; 

	return; 
}


void insertAfter(struct Node* prev_node, void* new_data) 
{ 
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
  
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    /* 3. put in the data  */
    new_node->data = new_data; 
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
  
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node; 
  
    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node; 
  
    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
} 



void insertBefore(struct Node* next_node,void* new_data) 
{ 
    /*1. check if the given new_node is NULL */
    if (next_node == NULL) { 
        printf("the given next node cannot be NULL"); 
        return; 
    } 
  
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    /* 3. put in the data */
    new_node->data = new_data; 
  
    /* 4. Make prev of new node as prev of next_node */
    new_node->prev = next_node->prev; 
  
    /* 5. Make the prev of next_node as new_node */
    next_node->prev = new_node; 
  
    /* 6. Make next_node as next of new_node */
    new_node->next = next_node; 
  
    /* 7. Change next of new_node's previous node */
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

