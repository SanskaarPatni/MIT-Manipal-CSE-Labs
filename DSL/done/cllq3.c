#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char data;
    struct Node * next;
}NODE;

typedef NODE * NODE_p_t;

NODE_p_t createNode () {
    NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE));
    temp->next = temp;
    temp->data = '\0';
    return temp;
}

void insert (NODE_p_t list, char item) {
    NODE_p_t temp = createNode();
    NODE_p_t p;
    
    temp->data = item;
    temp->next = list;
    
    if (list->next == list)
        list->next = temp;
    
    else {
        p = list->next;
        
        while (p->next != list)
            p = p->next;
        p->next = temp;
        
    }
}

void display (NODE_p_t list) {
    NODE_p_t temp = list->next;
    
    if (temp != list)  {
        while (temp->next != list) {
            printf(" %c ->", temp->data);
            temp = temp->next;
        }
        printf(" %c", temp->data);
        temp = temp->next;
    }
}


int main (int argc, const char * argv []) {
    
    NODE_p_t list1 = createNode();
    NODE_p_t list2 = createNode();
    NODE_p_t newList = createNode();
    
    int i, n;
    char item;
    
    printf("\nList 1: Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter List 1 elements in ascending order: ");
    for (i = 0; i < n; ++i) {
        scanf(" %c", &item);
        insert(list1, item);
    }
    
    printf("\nList 2: Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter List 2 elements in ascending order: ");
    for (i = 0; i < n; ++i) {
        scanf(" %c", &item);
        insert(list2, item);
    }
    
    NODE_p_t temp1 = list1->next;
    NODE_p_t temp2 = list2->next;
    
    while (temp1 != list1 && temp2 != list2) {
        char c1 = temp1->data;
        char c2 = temp2->data;
        if (c1 > c2) {
            insert(newList, c2);
            temp2 = temp2->next;
        }
        else {
            insert(newList, c1);
            temp1 = temp1->next;
        }
    }
    while (temp1 != list1) {
        insert(newList, temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != list2) {
        insert(newList, temp2->data);
        temp2 = temp2->next;
    }
    
    printf("\nList 1: ");
    display(list1);
    printf("\nList 2: ");
    display(list2);
    printf("\nMerged: ");
    display(newList);
    
    printf("\n\n");
}