#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *ptr;       
};

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
long long	ft_atoi(const char *nptr);
void push (int element, struct stack **top);
int isEmpty(struct stack *top);
int pop (struct stack **top);
int peek (struct stack *top);
void push (int element, struct stack **top);
int pop (struct stack **top);
int isEmpty(struct stack *top);

#endif