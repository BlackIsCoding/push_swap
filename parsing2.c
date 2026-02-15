/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:51:44 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:52:11 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(int argc, char **argv)
{
	char	*join;
	char	**splitted;

	join = args_joining(argc, argv);
	splitted = ft_split(join, ' ');
	free(join);
	return (splitted);
}

size_t	count_arguments(char **splitted, int *fail)
{
	size_t	count;

	if (splitted == NULL)
	{
		*fail = -1;
		return (0);
	}
	count = 0;
	while (splitted[count])
		count++;
	return (count);
}

void	args_atoi(char **splitted, long *array)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		array[i] = ft_atoi(splitted[i]);
		i++;
	}
}

int	check_duplicates(long *array, long element, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		if (array[i] == element)
			return (1);
		i++;
	}
	return (0);
}

int	check_sort(long *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
