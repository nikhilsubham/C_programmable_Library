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
void Add_front(struct Node** head_ref, void* app_data); 


/*declaration for deleting node from douly linked list. */
void deleteNode(struct Node **head_ref, struct Node *del);
void deleteNodeAtGivenPos(struct Node** head_ref, int n); 
