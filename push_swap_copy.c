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

int only_spaces_check(char *s)
{
    if (!s)
        return 1;

    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == ' ')
            i++;
        else
            return 0;
    }
    return 1;
}

int args_space_check (int argc , char **argv)
{
    int i;
    int check;

    i = 1;
    check = 0;
    while (i < argc)
    {
        if (only_spaces_check(argv[i]))
        {
            check = 1;
            break;
        }
        i++;
    }
    if (check == 1)
        return 0;
    return 1;
}

int check_letters(char *s)
{
    int i;
    int j;

    i = 0;
    while (s[i] == ' ')
        i++;
    if(s[i] == '-' || s[i] == '+')
            i++;
    if(!(s[i] >= '0' && s[i] <= '9'))
            return 0;
    while(s[i])
    {
        if ((s[i] == '+' || s[i] == '-') && (s[i + 1] >= '0' && s[i + 1] <= '9') && s[i - 1] == ' ')
            {
                i++;
                continue;
            }
        if(!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
            return 0;
        i++;
    }

return 1;
}

int intgr_valid(int argc, char **argv)
{
    int i;
    int j;
    long long n;

    i = 1;
    while (i < argc)
    {
        if (!check_letters(argv[i]))
            return 0;
          n = ft_atoi(argv[i]);
            if (n <= INT32_MAX && n >= INT32_MIN)
                i++;
            else
               return 0;
        }
    return 1;
}

char *args_joining(int argc, char **argv)
{
    int i;
    char *join;

    join = malloc(1);  
    if(!join)
        return NULL;
    join[0] = '\0';

    i = 1;
    while(i < argc)
    {
        join = ft_strjoin(join, argv[i]);
        if(join == NULL)
            break;
        i++;
    }
    return join;
}

char **split_args(int argc, char **argv)
{
    char *join = args_joining(argc, argv);
    char **splitted = ft_split(join, ' ');
    free(join);
    return splitted;
}

size_t count_arguments(char **splitted)
{
    size_t count;

    count = 0;
    while(splitted[count])
        count++;
    return count;
}

void args_atoi(char **splitted, size_t count, long long *array)
{
    int i = 0;
    while (splitted[i])
    {
        array[i] = ft_atoi(splitted[i]);
        i++;
    }
}

int check_duplicates(long long *array, long long element, int index)
{
    int i = 0;
    while(i < index)
    {
        if(array[i] == element)
            return 1;
        i++;
    }
    return 0;
}

int dupli_range_check (long long *array, int count)
{
    int i = 0;
    while (i < count)
    {
        if (check_duplicates(array, array[i], i) || (array[i] > INT32_MAX || array[i] < INT32_MIN))
            return 0;
        i++;
    }
    return 1;
}

void free_splitted(char **s)
{
    int i = 0;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

void reverse_array(long long *array, long long count)
{
    int i = 0;
    int j = count - 1;
    long long temp;

    while(i < j)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        i++;
        j--;
    }
}

void push_to_stackA(long long *arr, size_t count, struct stack **top)
{
    int i = 0;
    while(i < count)
    {
        push(arr[i], top);
        i++;
    }
    free(arr);
}

int split_count_atoi_checks_args (int argc, char **argv, struct stack **top)
{
    char **s;
    size_t count;
    long long *array;

    s = split_args(argc, argv);
    count = count_arguments(s);
    array = malloc(count * sizeof(long long));
    if(!array)
        return 0;
    args_atoi(s, count, array);
    free_splitted(s);
    if(dupli_range_check(array, count))
    {
        reverse_array(array, count);
        push_to_stackA(array, count, top);
        return 1;
    }
    else
    {
        free(array);
        return 0;
    }
}





int main (int argc, char **argv)
{
    if (argc == 1)
        return 0;
        
        long long *arr;
        struct stack *top = NULL;

    if(!args_space_check(argc, argv) || !intgr_valid(argc, argv))
    {
        printf("Error\n");
        exit(1);
    }else
    {
    printf("all good\n");
    int k =split_count_atoi_checks_args(argc, argv, &top);
    if(!k)
    {
        printf("---error---");
        exit(1);
    }

struct stack *temp;
    while(top)
    {
        printf("%d ", top->data);
        temp = top;
        top = top -> ptr;
        free(temp);
    }
}
}


// input : "44 11" 45 "5 gr"       done
// strjoin = "44 11 45 5 gr"    done
// split(strjoin,' ')      done 
// array of strings = 44 11 45 566666544333    done
// start converting using atoi     done   
// store them in an array   done 
// check duplicates && if >intmax || <intmin  done
// reverse
// then push to stack

