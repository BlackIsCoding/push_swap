#include <stdio.h>
#include <stdlib.h>

#ifndef size
#define size 5
#endif

int isEmpty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFULL (int top)
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

int push(int element, int *ptr_arr, int *top)
{   
    
    if(!isFULL(*top))
    {
        (*top)++;
        ptr_arr[*top] = element;
    }
    else 
    {
        printf("stack overflow\n");
    }
    return *top;
}

int pop (int *ptr_arr, int *top)
{
    if(isEmpty(*top)){
        printf("stack underflow");
        exit(1);
    }
    (*top)--;
    return ptr_arr[*top + 1];
}

void print_elmnts(int *stack_arr, int top)
{
    int i;

    i = 0;
    while (i <= top)
        printf("%d", stack_arr[i++]);
    printf("\n");
}

int main ()
{
    int x, topush;
    static int  top = -1;
    int stack_arr[size];

    printf("1. push\n2. pop\n3. print the top element\n4. print all elements of the stack\n5. Quit\n");
    
    while (1)
    {
        printf("Please enter your choice : ");
        scanf("%d", &x);
        if (x == 1)
        {
            printf("enter the element to push :");
            scanf("%d", &topush);
            push(topush, stack_arr, &top);
            }
        else if (x == 2)
        {
            topush = pop(stack_arr, &top);
            printf ("deleted element is : %d\n", topush);
            }
        else if (x == 3)
            printf("%d\n", stack_arr[top]);
        else if (x == 4)
            print_elmnts(stack_arr, top);
        else if ( x == 5)
        {
            printf("u did quit\n");
            exit(1);
        }
    }
}