#include <stdio.h>
#include "queue_fun.h"
int main()
{
queue q;
q.front=-1;
q.rear=-1;
int ch,x,flag=1;
while(flag)
{
printf("\n\n1. Insert Queue\n2. Delete Queue\n3. Display Queue\n4. Exit\n\n");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter the Element:");
scanf("%d",&x);
insertq(&q,x);
break;
case 2:
x=deleteq(&q);
printf("\nRemoved %d from the Queue\n",x);
break;
case 3:
displayq(q);
break;
case 4:
flag=0;
break;
default:
printf("\nWrong choice!!! Try Again.\n");
}
}
return 0;
}