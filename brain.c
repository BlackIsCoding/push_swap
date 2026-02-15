/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:58:47 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 14:01:18 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dupli_range_check(long *array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (check_duplicates(array, array[i], i)
			|| (array[i] > 2147483647 || array[i] < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

static void	free_splitted(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	push_to_stacka(long *arr, size_t count, t_stack **top)
{
	size_t	i;
	int		failure;

	i = count - 1;
	while (1)
	{
		failure = push(arr[i], top);
		if (failure == 0)
			return (0);
		if (i == 0)
			break ;
		i--;
	}
	free(arr);
	return (1);
}

static int	dup_range_push(int argc, char **argv, t_stack **top)
{
	char	**s;
	size_t	count;
	long	*array;
	int		fail;

	s = split_args(argc, argv);
	count = count_arguments(s, &fail);
	if (fail == -1)
		return (1);
	array = malloc(count * sizeof(long));
	if (!array)
		return (1);
	args_atoi(s, array);
	free_splitted(s);
	if (dupli_range_check(array, count))
	{
		if (check_sort(array, count))
			return (free(array), 2);
		fail = push_to_stacka(array, count, top);
		if (fail == 0)
			return (1);
		return (0);
	}
	return (free(array), 1);
}

int	main(int argc, char **argv)
{
	t_stack	*topa;
	t_stack	*topb;
	int		recieve;

	if (argc == 1)
		return (0);
	topa = NULL;
	topb = NULL;
	if (!space_valid(argc, argv) || !letters_valid(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	recieve = dup_range_push(argc, argv, &topa);
	if (recieve == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (recieve == 2)
		return (0);
	sort_numbers(&topa, &topb);
	free_nodes(topa);
	return (0);
}
