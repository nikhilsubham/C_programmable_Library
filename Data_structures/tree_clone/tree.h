struct tree_node 
{ 
    void* data; 
    struct tree_node *left; 
    struct tree_node *right;
    struct tree_node *parent; 
};

struct tree {
    struct tree_node *root;
};
 

struct tree* init_tree(void);
struct tree_node* init_tree_node(void* n);

struct tree_node* get_left_most(struct tree_node *node);
struct tree_node* get_next_inorder_succ(struct tree_node *node);



//bst_t * get_new_bst();
//struct node *newNode(void* key);
