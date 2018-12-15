#include "dll.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>

/*Application specific data structures*/
typedef struct student_{

    char name[32];
    int age;
    int weight;
    unsigned int rollno;
} student_t;

static void
print_student_details(student_t *student){

    printf("Name = %s\n",   student->name);
    printf("Age = %d\n",    student->age);
    printf("weight = %d\n", student->weight);
    printf("rollno = %u\n", student->rollno);
    printf("\n");
}

static void print_student_db(dll_t *student_db) 
{
    if(!student_db || !student_db->head) return;

    struct Node *head = student_db->head;
    student_t *data = NULL;

    while(head){
        data = head->data;
        print_student_details(data);
        head = head->right;    
    }
}

/*Traditional search function implemented by application itself for finding student by roll no*/
student_t *search_student_by_rollno(dll_t *student_db, unsigned int rollno/*search key*/)
{
   if(!student_db || !student_db->head) return NULL;

    struct Node *head = student_db->head;
    student_t *data = NULL;

    while(head){
        data = head->data;
        if(data->rollno == rollno)
            return data;
        head = head->right;    
    }
}


/*Search callbacks*/
static int /*return 0 if matches, return -1 if do not match*/
search_student_db_by_key(void *data, void *key)
{
    student_t *student = (student_t *)data;
    char* name = (char*)key;
    if(!strcmp(student->name, name))
       return 0;
    return -1;
}

static int student_comparison_fn(void *stud1, void *stud2)
{
     /*Let us define the sorting order of students, 
     * Let us compare the students Alphabetically on their names
     * If two students have same name, younger students should 
     * come before elder student
     * If age is also same, lighter student comes before heavier
     * if Weight is also same, students with numerically lesser rollno
     * comes before in the DLL*/
    
     student_t *student1 = (student_t *)stud1;
     student_t *student2 = (student_t *)stud2;

     if(strncmp(student1->name, student2->name, 32) < 0)
         return -1;
     else if(strncmp(student1->name, student2->name, 32) > 0)
         return 1;
     else if(student1->age < student2->age)
         return -1;
     else if(student1->age > student2->age)
         return 1;
     else if(student1->weight < student2->weight)
         return -1;
     else if(student1->weight > student2->weight)
         return 1;
     else if(student1->rollno < student2->rollno)
         return -1;
     else if(student1->rollno > student2->rollno)
         return 1;
     assert(0); /*intentionally Crash the program !!*/
}


int main(int argc, char **argv)
{
    /*Student database*/
    student_t *student1 = calloc(1, sizeof(student_t));
    strncpy(student1->name, "Nikhil", strlen("Nikhil"));
    student1->age = 31;
    student1->weight = 75;
    student1->rollno = 800000;

    student_t *student2 = calloc(1, sizeof(student_t));
    strncpy(student2->name, "Joseph", strlen("Joseph"));
    student2->age = 41;
    student2->weight = 70;
    student2->rollno = 800400;

    student_t *student3 = calloc(1, sizeof(student_t));
    strncpy(student3->name, "Jack", strlen("Jack"));
    student3->age = 29;
    student3->weight = 55;
    student3->rollno = 800400;

    student_t *student4 = calloc(1, sizeof(student_t));
    strncpy(student4->name, "Nikhil", strlen("Nikhil"));
    student4->age = 29;
    student4->weight = 55;
    student4->rollno = 800399;

   
    /*Create a new Linked List*/
    dll_t *student_db = get_new_dll();
   
    register_key_match_callback(student_db, search_student_db_by_key);
    register_comparison_callback(student_db, student_comparison_fn);

    dll_priority_insert_data(student_db, student1);
    dll_priority_insert_data(student_db, student2);
    dll_priority_insert_data(student_db, student3);
    dll_priority_insert_data(student_db, student4);

    printf("Printing Stduents list\n");
    print_student_db(student_db);
    
    dll_t *student_db1 = get_new_dll();
    Add_front(student_db1, student1); 
    Add_front(student_db1, student2); 
    Add_front(student_db1, student3); 
    Add_front(student_db1, student4); 

   
    printf("Printing Stduents list without sorted order\n");
    print_student_db(student_db1);

    return 0;
}









