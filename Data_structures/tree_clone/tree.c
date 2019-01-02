#include "tree.h"
#include <memory.h>
#include <stdlib.h>


struct tree* init_tree(void)
{
    struct tree *tree = calloc(1,sizeof(struct tree));
    if(!tree)
        return NULL;
    tree->root = NULL;
    return tree;
}

struct tree_node* init_tree_node(void* n)
{
    struct tree_node* node = calloc(1, sizeof(struct tree_node));
    if(!node)   return NULL;
    node->data = n;
    return node;
}


struct tree_node* get_left_most(struct tree_node *node){

    if(!node->left)
        return NULL;

    while(node->left){
        node = node->left;
    }
    return node;
}


struct tree_node* get_next_inorder_succ(struct tree_node *node){

    /* case 1 : Handling root*/
    if(!node->parent){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
        return NULL;
    }

    /*case 2 : if node is a left child of its parent*/
    if(node == node->parent->left){
        if(!node->right)
            return node->parent;
        else
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
    }

    /*case 3 : if node is a right child of its parent*/
    if(node == node->parent->right){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
    }

    /* case 4 : Inorder successor of node is a ancestor whose
     * left children is also an ancestor*/

    struct tree_node *gp = node->parent->parent;
    struct tree_node *parent = node->parent;

    while(gp && gp->left != parent){

        parent = gp;
        gp = gp->parent;
    }
    return gp;
}




/* Public Function Implementation to create and return new empty doubly linked list*/
//bst_t * get_new_bst()
//{
//    bst_t *bst = calloc(1, sizeof(bst_t));
//    bst->head = NULL;
//    return bst;
//}

//struct node *newNode(void* key) 
//{ 
//    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
//    temp->data = key; 
//    temp->left = temp->right = NULL; 
//    return temp; 
//}














 
