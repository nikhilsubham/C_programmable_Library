#include <stdlib.h>

/*Step 5 : */

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

      /*Write your code here*/
      while(root1 && root2)
      {
        void* stud1 = get_app_data(root1);
        void* stud2 = get_app_data(root2);
      
        if(comparator(stud1, stud2)!=0)
          {
             return -1;
          } 
         root1 =  iterator(root1);    
         root2 =  iterator(root2);
      }

      if(!root1 && !root2)
         return 0;
     
      return -1;
}
