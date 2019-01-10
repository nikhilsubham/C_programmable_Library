#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int
diff (void *root1,    /*pointer to first node of data struture 1*/
        void *root2,    /*pointer to first node of data struture 2*/
        void *(*iterator)(void *), /*Iterator function callback*/
        int (*comparator)(void *, void *),
        void *(*get_app_data)(void *)); /*Comparison function callback*/


/*Application specific data structures*/
typedef struct student_{
    char name[32];
    unsigned int year_of_birth;
    unsigned int height;
    unsigned int weight;
    unsigned int total_marks;
} student_t;


static void
print_student_details(student_t *student){

    printf("Name = %s\n",   student->name);
    printf("year_of_birth = %d\n",    student->year_of_birth);
    printf("height = %d\n",    student->height);
    printf("weight = %d\n", student->weight);
    printf("total_marks = %u\n", student->total_marks);
    printf("\n");
}



void printInorder(struct tree* dll, struct tree_node* node) //dll_t *dll, struct node* node) 
{ 
     if(node == NULL) 
          return; 
  
     /* first recur on left child */
     printInorder(dll, node->left); 
  
     /* then print the data of node */
     print_student_details(node->data); 
       
     /* now recur on right child */
     printInorder(dll, node->right); 
} 


/*Step 2 : Implement tree iterator function here*/
void* tree_iterator (void *tree_node){
     
    struct tree_node* node = (struct tree_node*)tree_node;
    if(!node)
       return NULL;

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
    
    /*write your code here*/
    //dll_node_t* node = (dll_node_t*)list_node;
    //if(!node && !node->right)
    //   return NULL;

    //node = node->right;
    //return (void*)node;
}

/*Step 3 : implement student comparator function here*/
int student_comparator(void *_studentobj1, void *_studentobj2){

    /*Write your code here*/
    student_t *stud1 = (student_t*)_studentobj1;
    student_t *stud2 = (student_t*)_studentobj2;
    
    if(!strcmp(stud1->name, stud2->name) && (stud1->year_of_birth == stud2->year_of_birth) && 
                        (stud1->height == stud2->height) && (stud1->weight==stud2->weight) &&
                          (stud1->total_marks==stud2->total_marks))
      
            return 0;
   
    printf("\n\nThe first visited different elements are as below\n");
    print_student_details(stud1);
    print_student_details(stud2);     
    return -1;
} 


/*Step 4 : implement get_app_data_from_list_node function*/
void*
get_app_data_from_list_node(void *tree_node){

    /*Write your code here*/
    struct tree_node* node = (struct tree_node *)tree_node;
    if(!node)
      return NULL;
    
    return node->data;
}


int
main(int argc, char **argv){

    /*Student database list 1*/
    student_t *student1 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student1->name, "Abhishek", strlen("Abhishek"));
    student1->year_of_birth = 2000;
    student1->height = 167;
    student1->weight = 80;
    student1->total_marks = 90;

    student_t *student2 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student2->name, "Sagar", strlen("Sagar"));
    student2->year_of_birth = 2001;
    student2->height = 170;
    student2->weight = 82;
    student2->total_marks = 80;

    student_t *student3 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student3->name, "Vineet", strlen("Vineet"));
    student3->year_of_birth = 2002;
    student3->height = 161;
    student3->weight = 62;
    student3->total_marks = 72;

    student_t *student4 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student4->name, "Neeraj", strlen("Neeraj"));
    student4->year_of_birth = 1998;
    student4->height = 167;
    student4->weight = 76;
    student4->total_marks = 68;

    
    struct tree* tree1 = init_tree();
    struct tree_node* node1= tree1->root;

    //bst_t *student_db1 = get_new_bst();
    //dll_t *student_db11 = get_new_dll();
    //struct node* node1= student_db1->head;
    //dll_node_t*node11 = student_db11->head;

    node1 = init_tree_node(student1);
    node1->parent = NULL; 

    node1->left = init_tree_node(student2); 
    node1->left->parent = node1;

    node1->right = init_tree_node(student3); 
    node1->right->parent = node1;

    node1->left->left = init_tree_node(student4); 
    node1->left->left->parent = node1->left;

    printf("Printing first tree structures data\n");
    printInorder(tree1, node1); 
    printf("........................................................................\n");

    /*Student database list 2*/
    student_t *student5 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student5->name, "Abhishek", strlen("Abhishek"));
    student5->year_of_birth = 2000;
    student5->height = 167;
    student5->weight = 80;
    student5->total_marks = 90;

    student_t *student6 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student6->name, "Sagar", strlen("Sagar"));
    student6->year_of_birth = 2001;
    student6->height = 170;
    student6->weight = 82;
    student6->total_marks = 80;

    student_t *student7 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student7->name, "Vineet", strlen("Vineet"));
    student7->year_of_birth = 2002;
    student7->height = 161;
    student7->weight = 62;
    student7->total_marks = 72;

    student_t *student8 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student8->name, "Neeraj", strlen("Neeraj"));
    student8->year_of_birth = 1998;
    student8->height = 167;
    student8->weight = 76;
    student8->total_marks = 68;

    struct tree* tree2 = init_tree();
    struct tree_node* node2 = tree2->root;
    //bst_t *student_db2 = get_new_bst();
    //dll_t *student_db22 = get_new_dll();
    //struct node* node2 = student_db2->head;
    //dll_node_t*node22 = student_db22->head;

    node2 = init_tree_node(student5);
    node2->parent = NULL;
  
    node2->left = init_tree_node(student6); 
    node2->left->parent = node2;

    node2->right = init_tree_node(student7); 
    node2->right->parent = node2;

    node2->left->left = init_tree_node(student8);
    node2->left->left->parent = node2->left;
 
 
    printf("Printing second tree structures daata\n");
    printInorder(tree2, node2); 

    /*Step 6*/

    if(diff((void *)get_left_most(node1), (void *)get_left_most(node2), tree_iterator, student_comparator, get_app_data_from_list_node) == 0)
        printf("Two tree data sructures are clones of each other\n");
    else
        printf("Two tree data sructures are not clone of each other\n");
    return 0;
}
