/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:52:37 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:53:26 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_positions(t_stack *topA)
{
	size_t	set_position;

	set_position = 0;
	while (topA)
	{
		topA->position = set_position;
		set_position++;
		topA = topA->ptr;
	}
}

static void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

static void	bubble_sort(int arr[], size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static size_t	search_return_index(int arr[], size_t size, int data)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return (0);
}

void	index_nodes(t_stack *topA)
{
	size_t		n;
	size_t		i;
	int			*arr;
	t_stack		*temp;

	n = stackk_size(topA);
	arr = malloc(n * sizeof(int));
	if (!arr)
		return ;
	i = 0;
	temp = topA;
	while (i < n && temp)
	{
		arr[i++] = temp->data;
		temp = temp->ptr;
	}
	bubble_sort(arr, n);
	temp = topA;
	while (temp)
	{
		temp->index = search_return_index(arr, n, temp->data);
		temp = temp->ptr;
	}
	free(arr);
}
