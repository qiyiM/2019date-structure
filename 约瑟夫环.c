#include <stdio.h>
#include <stdlib.h>
# define N 7
typedef struct Node
{
     int  data;
     int  number;
     struct Node *next;

}List;
 List *creat()
 {
     List* head;
     head=(List*)malloc(sizeof(List));
     scanf("%d",&head->data);
     head->number=1;
     head->next=NULL;
     return head;

 }
 List*insert(List* head ,int password ,int i,int n)
 {
    List *p,*t;
	t=head;
	p=(List *)malloc(sizeof(List));
	p->data=password;
	p->number=i+1;
	while(t->next!=NULL)
	t=t->next;
	t->next=p;
	p->next=NULL;
	if(i==n-1)
        p->next=head;
	return head;
 }

  void Delete(List* head,int password,int n)
 {
     List *p= head;
     List *apnext;
     int j=0;
     while(n>1)
     {

         for(j=1;j<password;j++)
         {
             p=p->next;
         }

                    apnext=p->next;
                    p->next=apnext->next;
                    password=apnext->data;
                    printf("%d\n",apnext->number);
                    free(apnext);

            n--;
     }
     printf("%d\n",p->number);
 }

void main()
{

    int i=0,passworad,m;
    int n=N;
    printf("input the max password:");
    scanf("%d",&m);
    printf("input the password:");
     List *group=creat();
    for(i=1;i<n;i++)
    {
        scanf("%d",&passworad);

        insert(group,passworad,i,n);

    }
    Delete(group,m-1,n);

}
