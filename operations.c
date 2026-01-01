#include "push_swap.h"


void sa(struct stack *topA)
{
    if (topA == NULL || topA -> ptr == NULL)
        return ;
    
    int temp;

    temp = topA -> data;
    topA->data = topA->ptr->data;
    topA->ptr->data = temp; 
}

void sb(struct stack *topB)
{
    if (topB == NULL || topB -> ptr == NULL)
        return ;
    
    int temp;

    temp = topB -> data;
    topB->data = topB->ptr->data;
    topB->ptr->data = temp; 
}

void ss(struct stack *topA, struct stack *topB)
{
    sa(topA);
    sb(topB);
}

void pa(struct stack **topA, struct stack **topB)
{
    if (!(*topB))
        return ;
    push((*topB) -> data, topA);
    pop(topB);
}

void pb(struct stack **topA, struct stack **topB)
{
    if (!(*topA))
        return ;
    push((*topA) -> data, topB);
    pop(topA);
}

void ra(struct stack **topA)
{
    int clone = (*topA) -> data;
    pop(topA);
    struct stack *temp = *topA;
    while(temp)
        temp = temp -> ptr;
}