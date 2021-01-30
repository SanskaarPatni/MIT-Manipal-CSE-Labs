#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coeff,exp;
    struct node *next;
}*NODE;
typedef struct hnode
{
    int count;
    struct node *next;
}*HNODE;
NODE insert_sort(NODE f,int co,int e)
{
    NODE n=(NODE)malloc(sizeof(struct node));
    n->coeff=co;
    n->exp=e;
    n->next=NULL;
    if(f==NULL)
    {
        n->next=n;
        return n;
    }
    if(f->exp>e)
    {
        n->next=f;
        NODE p=f;
        while(p->next!=f)
        {
            p=p->next;
        }
        p->next=n;
        return n;
    }
    NODE t=f;
    NODE prev=t;
    while(t->exp<e&&t->next!=f)
    {
        prev=t;
        t=t->next;
    }
    if(t->exp<e&&t->next==f)
    {
        t->next=n;
        n->next=f;
    }
    else
    {
        prev->next=n;
        n->next=t;
    }
    return f;
}
void display(NODE f)
{
    NODE t=f;
    printf("\nLIST ELEMENTS: ");
    while(t->next!=f)
    {
        if((t->next)->coeff>0)
        printf("%dX^%d+",t->coeff,t->exp);
        else if((t->next)->coeff!=0)
        printf("%dX^%d",t->coeff,t->exp);
        
        t=t->next;
    
    }
    printf("%dX^%d\n",t->coeff,t->exp);
}
void multiply(HNODE A,HNODE B)
{
    int l=0;
    int i=0;
    int j,k;
    NODE p=A->next;
    NODE f=A->next;
    NODE q=B->next;
    NODE s=B->next;
    NODE m=NULL;
    for(j=0;j<A->count-1;j++)
    {
        f=f->next;
    }
    for(j=0;j<B->count-1;j++)
    {
        s=s->next;
    }
    l=f->exp+s->exp;
    f=p;
    s=q;
    while(i<=l)
    {
        f=p;
        s=q;
        int multi=0;
        for(j=0;j<A->count;j++)
        {
            for(k=0;k<B->count;k++)
            {
                if(f->exp+s->exp==i)
                {
                    multi=f->coeff*s->coeff+multi;
                }
                s=s->next;
            }
            f=f->next;
        }
        m=insert_sort(m,multi,i);
        i=i+1;
    }
    display(m);
}
void subtract(HNODE A,HNODE B)
{
    NODE p=A->next;
    NODE f=A->next;
    NODE q=B->next;
    NODE s=B->next;
    NODE m=NULL;
    HNODE C=(HNODE)malloc(sizeof(struct hnode));
    C->count=0;
    int c=0,e=0;
    int i,j;
    int flag=0;
    for(i=0;i<A->count;i++)
    {
        c=f->coeff;
        e=f->exp;
        flag=0;
        for(j=0;j<B->count;j++)
        {
            if(e==s->exp)
            {
                m=insert_sort(m,c-s->coeff,e);
                C->count+=1;
                flag=1;
                break;
            }
            s=s->next;
        }
        if(flag==0)
        {
            m=insert_sort(m,c,e);
            C->count+=1;
        }
        f=f->next;
        s=q;
    }
    NODE t=m;
    s=q;
    for(j=0;j<B->count;j++)
    {
        flag=0;
        e=s->exp;
        c=-s->coeff;
        for(i=0;i<C->count;i++)
        {
            if(e==t->exp)
            {
                flag=1;
                break;
            }
            t=t->next;
        }
        if(flag==0)
        {
            m=insert_sort(m,c,e);
            C->count++;
        }
        s=s->next;
    }
    C->next=m;
    display(m);
}

int main()
{
    NODE f=NULL;
    NODE s=NULL;
    HNODE A=(HNODE)malloc(sizeof(struct hnode));
    A->count=0;
    HNODE B=(HNODE)malloc(sizeof(struct hnode));
    B->count=0;
    int ch;
    int c;
    int e;
    printf("INPUT THE FIRST LIST:");
    do
    {
        printf("\nINPUT YOUR CHOICE\n");
        printf("1.PUSH\t2.EXIT AND INPUT NEW LIST\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("INPUT COEFFICIENT AND EXPONENT:\n");
            scanf("%d%d",&c,&e);
            f=insert_sort(f,c,e);
            A->count+=1;
            break;
            case 2:
            printf("\nINPUT SECOND LIST:");
            break;
        }
    }while(ch!=2);
    do
    {
        printf("\nINPUT YOUR CHOICE\n");
        printf("1.PUSH\t2.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
            printf("INPUT COEFFICIENT AND EXPONENT:\n");
            scanf("%d%d",&c,&e);
            s=insert_sort(s,c,e);
            B->count+=1;
            break;
            case 2:
            printf("\nDISPLAYING GIVEN LISTS:\n");
            break;
        }
    }while(ch!=2);
    display(f);
    display(s);
    A->next=f;
    B->next=s;
    printf("\nAFTER SUBTRACTION:");
    subtract(A,B);
    printf("\nAFTER MULTIPLICATION:");
    multiply(A,B);
    return 0;
}
