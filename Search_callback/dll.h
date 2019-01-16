/*Header file for Doubly Linked List*/

struct Node
{
    void *data;
    struct Node *next;
    struct Node *prev;
};

typedef struct dll_{
    struct Node *head;
    int (*key_match)(void *, void *);
} dll_t;

void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void *));

/*Generic Search function*/
void* dll_search_by_key (dll_t *dll, void *key);

/*Public Function declaration to create and return a new empty doubly linked list*/
dll_t* get_new_dll();

/*Public Function declaration to add the appication data to DLL*/
int add_data_to_dll(dll_t *dll, void *appn_data);
void Add_front(dll_t* dll, void* app_data); 
void Add_atend(dll_t* dll, void* new_data);
void insertAfter(struct Node* prev_node, void* new_data);
void insertBefore(struct Node* next_node, void* new_data);  


/*declaration for deleting node from douly linked list. */
void deleteNode(dll_t* dll, struct Node *del);
void deleteNodeAtGivenPos(dll_t*dll, int n); 

/* reversing a doubly lined list*/ 
void reverse(dll_t*dll);

/*Macro to iterate over a DLL*/
#define ITERATE_LIST_BEGIN(list_ptr, node_ptr)                              \
{                                                                           \
    struct Node* _node_ptr = NULL;                                           \
    node_ptr = list_ptr->head;                                              \
    for(; node_ptr!= NULL; node_ptr = _node_ptr){                           \
        if(!node_ptr) break;                                                \
        _node_ptr = node_ptr->next;

#define ITERATE_LIST_END  }}
