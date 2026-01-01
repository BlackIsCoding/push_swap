#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main (int argc, char **argv)
{

    if (argc == 1)
        return 0;

struct stack *top_a = NULL;
struct stack *top_b = NULL;
int i, j, k;
int arr[argc - 1];

i = 1;
k = 0;
while (i < argc)
{
    j = 0;
    while(argv[i][j])
    {
        while (argv[i][j] == ' ')
            j++;
        if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
            j++;
        if ((argv[i][j] >= '0' && argv[i][j] <= '9'))
            j++;
        else 
            break;
    }
     if (argv[i][j] == '\0' && ((argv[i][j - 1] >= '0' && argv[i][j-1] <= '9') || argv[i][j - 1] == ' '))
        arr[k++] = ft_atoi(argv[i]);
    else
    {
        printf("Error");
        exit (1);
    }
    i++;
}

 i = 0;
while (i < argc - 1)
    printf("%d ", arr[i++]);
}
