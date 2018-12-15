#include "dll.h"
#include <memory.h>
#include <stdlib.h>

/* Public Function Implementation to create and return
 * new empty doubly linked list*/
dll_t * get_new_dll()
{
    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    dll->key_match = NULL;
    return dll;
}

void register_key_match_callback(dll_t *dll, 
                             int (*key_match)(void *, void *)){

    dll->key_match = key_match;
}

void register_comparison_callback(dll_t *dll,
                            int (*comparison_cb)(void *, void *)){

    dll->comparison_fn = comparison_cb;
}


/*Generic Search function*/
void * dll_search_by_key (dll_t *dll, void *key)
{
   if(!dll || !dll->head) return NULL;

    struct Node *head = dll->head;

    while(head){
        if(dll->key_match(head->data, key) == 0)
            return (void *)head->data;
        head = head->right;
    }
    return NULL;
}


/*Return 0 - on success -1 on Failure*/
int dll_priority_insert_data (dll_t *dll, void *data)
{
    if(!dll)
        return -1;

    /*if DLL is empty*/
    if(!dll->head){
        Add_front(dll, data);
        return 0;
    }

    struct Node *data_node = calloc(1, sizeof(struct Node));
    data_node->data = data;
    data_node->left = NULL;
    data_node->right = NULL;

    /* if there is only one node in DLL*/
    if(dll->head && !dll->head->right){
        if(dll->comparison_fn(dll->head->data, data) == -1){
            dll->head->right = data_node;
            data_node->left = dll->head;
        }
        else{
            dll->head->left = data_node;
            data_node->right = dll->head;
            dll->head = data_node;
        }
        return 0;
    }

    /*if More than one node in DLL*/
    if(dll->comparison_fn(data, dll->head->data) == -1){
        data_node->right = dll->head;
        dll->head->left = data_node;
        dll->head = data_node;
        return 0;
    }

    struct Node *prev = NULL,
               *curr = NULL;

    curr = dll->head;

    while(curr){
        if(dll->comparison_fn(data, curr->data) != -1){
            prev = curr;
            curr = curr->right;
            continue;
        }

        prev->right = data_node;
        data_node->left = prev;
        data_node->right = curr;
        curr->left = data_node;
        return 0;
    }

    /*Add in the end*/
    prev->right = data_node;
    data_node->left = prev;
    return 0;
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
    new_node->right = (*head_ref); 
    new_node->left = NULL; 
  
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL) 
        (*head_ref)->left = new_node; 
  
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node; 
}

