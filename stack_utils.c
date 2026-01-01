#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void push (int element, struct stack **top)
{
    struct stack *node;
    
    node = malloc (sizeof(struct stack));
    if (node == NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    node-> data = element;
    node -> ptr = NULL;

     node -> ptr = *top;
     *top = node;
}

int isEmpty(struct stack *top)
{
    if (!top)
        return 1;
    else
        return 0;
}

int pop (struct stack **top)
{
    if (isEmpty(*top))
    {
        printf("stack underflow");
        exit(1);
    }
    struct stack *temp;
    int hold;

    hold = (*top) -> data;
    temp = *top;
    *top = (*top) -> ptr;
    free (temp);

    return hold;
}

// int peek (struct stack *top)
// {
//     if (isEmpty)
//     {
//         printf("stack underflow");
//         exit(1); 
//     }
//     return top -> data;
// }


// int main ()
// {
//     struct stack *top = NULL;
//     push(3, &top);
//     push(4, &top);
//     push(5, &top);
//     struct stack *temp = top;
//     // while(temp)
//     // {
//     //     printf("%d ", temp -> data);
//     //     temp = temp -> ptr;
//     // }
//     reverse_ready(top);
// }