#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char a[20];
    struct node *l,*r;
}* NODE;
NODE insert(NODE f)
{
    NODE n=(NODE)malloc(sizeof(struct node));
    printf("INPUT THE WORD TO INSERT: ");
    scanf("%s",(n->a));
    fflush(stdin);
    n->l=NULL;
    n->r=NULL;
    if(f==NULL)
    {
        n->l=NULL;
        n->r=NULL;
        return n;
    }
    NODE t=f;
    while(t->r!=NULL)
    {
        t=t->r;
    }
    t->r=n;
    n->l=t;
    return f;
}
void display(NODE f)
{
    if(f==NULL)
    {
        printf("\nEMPTY LIST\n");
        return;
    }
    printf("LINKED LIST ELEMENTS: ");
    while(f!=NULL)
    {
        printf("%s ",f->a);
        f=f->r;
    }
    printf("\n");
    return;
}
NODE reverse(NODE f)
{
    NODE t=f;
    NODE rev=f;
    int i=0;
    int c=0;
    while(t->r!=NULL)
    {
        c++;
        t=t->r;
    }
    while(i<=(c/2))
    {
        char ta[20];
        strcpy(ta,rev->a);
        strcpy(rev->a,t->a);
        strcpy(t->a,ta);
        rev=rev->r;
        t=t->l;
        i++;
    }
    return f;
}
int main()
{
    NODE f=NULL;
    int ch;
    do
    {
        printf("\nINPUT YOUR CHOICE\n");
        printf("1.PUSH\t2.EXIT\n");
        scanf("%d",&ch);
        fflush(stdin);
        switch(ch)
        {
            case 1:
            f=insert(f);
            break;
            default:
            printf("ORIGINAL LINKED LIST:\n");
            display(f);
            f=reverse(f);
            printf("AFTER REVERSAL:\n");
            display(f);
            printf("\nEXIT STATUS INITIATED\n");
            break;
        }
    }while(ch!=2);
    return 0;
}
