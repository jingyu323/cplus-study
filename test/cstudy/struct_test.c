#include <stdio.h>


struct Student
{
  char s_id[8];
  char s_name[8];
  char s_sex[4];
  int s_age;
} Student ;

typedef  struct  Teacher
{
  char s_id[8];
  char s_name[8];
  char s_sex[4];
  int s_age;
}Teacher , *TeacherP ;



typedef struct node{
	int data;
	struct node *next;
}Lnode,*LNODE;


int main(int argc, char const *argv[])
{       

Lnode head , ppp;
	head.data = 3;
	head.next = &ppp;
	printf("A%d %d\n",head.data,head.next);
	
	LNODE p;
	printf("www ==  %d\n",p->data); 
    

    
        return 0;
}
