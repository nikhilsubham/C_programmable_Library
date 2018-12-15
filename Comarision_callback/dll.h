/*Header file for Doubly Linked List*/

struct Node{

    void *data;
    struct Node *left;
    struct Node *right;
};

typedef struct dll_{
    struct Node *head;
    int (*key_match)(void *, void *);
    int (*comparison_fn)(void *, void *);
} dll_t;

void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void *));

void register_comparison_callback(dll_t *dll, int (*comparison_cb)(void *, void *));

/*Generic Search function*/
void * dll_search_by_key (dll_t *dll, void *key);

/* This function will add data to doubly linked list using insertion sort in sorted order only*/
int dll_priority_insert_data (dll_t *dll, void *data);

/* Public Function declaration to create and return a new empty doubly linked list*/
dll_t * get_new_dll();

/* Public Function declaration to add the appication data to DLL*/
void Add_front(dll_t *dll, void* app_data); 
