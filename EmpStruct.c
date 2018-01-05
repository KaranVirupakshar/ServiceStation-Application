#include "header.c"
/*Employee Structure*/
struct node
{
   struct employee
   {
     int id;
     char name[10];
     char department[15];
     int  salary;
   }empdata;
   struct node *next;
};
typedef struct node node;
