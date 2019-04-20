/*Header file for Doubly Linked List*/
#ifndef __DLL__
#define __DLL__

typedef struct dll_node_{

    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
} dll_t;


/* Public Function declaration to create and return a new empty doubly linked list*/
dll_t* get_new_dll();

/* Appends a new node at the front of the list */
void Add_front(dll_t *dll, void* app_data); 

#endif
