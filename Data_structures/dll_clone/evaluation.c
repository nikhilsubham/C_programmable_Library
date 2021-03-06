#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int
diff (void *root1,    /*pointer to first node of data struture 1*/
        void *root2,    /*pointer to first node of data struture 2*/
        void* (*iterator)(void *), /*Iterator function callback*/
        int   (*comparator)(void *, void *),
        void* (*get_app_data)(void *)); /*Comparison function callback*/


/*Application specific data structures*/
typedef struct student_{
    char name[32];
    unsigned int year_of_birth;
    unsigned int height;
    unsigned int weight;
    unsigned int total_marks;
} student_t;


/*list iterator function is implemented here*/
void* list_iterator (void *list_node){

    dll_node_t* node = (dll_node_t*)list_node;
    if(!node && !node->right)
       return NULL;

    node = node->right;
    return (void*)node;
}

/*Student comparator function is implemented here*/
int student_comparator (void *_studentobj1, void *_studentobj2){

    student_t *stud1 = (student_t*)_studentobj1;
    student_t *stud2 = (student_t*)_studentobj2;
    
    if(!strcmp(stud1->name, stud2->name) && (stud1->year_of_birth == stud2->year_of_birth) && 
                        (stud1->height == stud2->height) && (stud1->weight==stud2->weight) &&
                          (stud1->total_marks==stud2->total_marks))
      
               return 0;     
    return -1;
} 


/* get_app_data_from_list_node function is implemented here*/
void* get_app_data_from_list_node(void *list_node){

    dll_node_t* node = (dll_node_t*)list_node;
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
    student2->year_of_birth = 2002;
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


    dll_t *student_db1 = get_new_dll();
    Add_front(student_db1, student1);
    Add_front(student_db1, student2);
    Add_front(student_db1, student3);
    Add_front(student_db1, student4);


    /*Student database list 2*/
    student_t *student5 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student5->name, "Abhishek", strlen("Abhishek"));
    student5->year_of_birth = 2000;
    student5->height = 167;
    student5->weight = 80;
    student5->total_marks = 90;

    student_t *student6 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student6->name, "Sagar", strlen("Sagar"));
    student6->year_of_birth = 2002;
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
    student8->total_marks = 67;

    dll_t *student_db2 = get_new_dll();
    Add_front(student_db2, student5);
    Add_front(student_db2, student6);
    Add_front(student_db2, student7);
    Add_front(student_db2, student8);

    
   /* diff function is being called here to know whether two same data structures are clones or not of each other*/
    if(diff((void *)student_db1->head, (void *)student_db2->head, list_iterator, student_comparator, get_app_data_from_list_node) == 0)
        printf("Data sructures are clones of each other\n");
    else
        printf("Data sructures are not clones\n");
    return 0;
}
