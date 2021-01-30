#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    char item;
    struct node * left;
    struct node * right;
}*Btree;

Btree root; 
char expression[25];
Btree stack[25];
int stackPtr = -1;
void push(Btree root)
{
    stack[++stackPtr] = root;
}

Btree pop()
{
    return (stack[stackPtr--]);
}

void operandFunc(char var)
{
    Btree root = (Btree)malloc(sizeof(struct node));
    root->item= var;
    root->left= NULL;
    root->right= NULL;
    push(root);
}

void operatorFunc(char var)
{
    Btree root = (Btree)malloc(sizeof(struct node));
    root->item = var;
    root->right = pop();
    root->left = pop();
    push(root);
}
int calculate(char operator,int op1,int op2)
{
    //printf("Operator = %c , num1 = %d, num2 = %d\n",operator,op1,op2);
    switch(operator)
    {
        case '+':   return(op1+op2);
                    break;
        case '-':   return(op1-op2);
                    break;
        case '*':   return(op1*op2);
                    break;
        case '/':   return(op1/op2);
                    break;
        case '%':   return(op1%op2);
                    break;
        case '$':   return pow(op1,op2);
                    break;
        default:    printf("\n illegal operation.");
                    exit;
    }
}
int isOperand(char var)
{
    switch(var)
    {
        case '+': 
        case '-':
        case '*':
        case '/':
        case '$':
        case '%':
                    return 0;
        default:
                    return 1;
    }
}

int solve(Btree root)
{
    Btree temp = root;
    char num1,num2;
    char operator;
    int result;
    if(temp)
    {
        Btree LEFTP = temp->left;
        Btree RIGHTP = temp->right; 

        if(LEFTP)
        {
            if(isOperand(LEFTP->item))
            {
                num1 = LEFTP->item;
            }   
            else
            {
                num1 = solve(LEFTP);
            }
        }

        if(RIGHTP)
        {
            if(isOperand(RIGHTP->item))
            {
                num2 = RIGHTP->item;
            }   
            else
            {
                num2 = solve(RIGHTP);
            }
        }

        operator = temp->item;
        //printf("Test 1 = %c, num1 = %c, num2 = %c\n",operator,num1,num2);
        result = calculate(operator,num1-'0',num2-'0');
       //printf("Test Result = %d\n",result);
        temp->item = (result+'0');
        //printf("Root Item = %c and %d\n",temp->item,temp->item);
        return root->item;
    }
    return NULL;
}
int main()
{
    int count = 0;
    printf("Please enter a postfix expression\n");
    while((expression[count++]=getchar())!='\n');
    expression[--count] = '\0';
    //puts(expression);

    for(count = 0;expression[count]!='\0';count++)
    {
        switch(expression[count])
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
            case '$':
                operatorFunc(expression[count]);
                break;
            default:
                operandFunc(expression[count]);
        }
    }
    if(stackPtr != 0)
    {
        printf("Incorrect postfix expression!\n");
    }
    else
    {
        printf("\nResult: %d",solve(stack[stackPtr])-'0');
        printf("\n");
        return 0;
    }
}

