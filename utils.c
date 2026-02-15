/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:19:52 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/19 08:20:00 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_stack *topA)
{
	t_stack	*tmp;

	while (topA)
	{
		tmp = topA->ptr;
		free(topA);
		topA = tmp;
	}
}

int	push(int element, t_stack **top)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		free_nodes(*top);
		return (0);
	}
	node->data = element;
	node->ptr = *top;
	*top = node;
	return (1);
}

void	sort_five(t_stack **topA, t_stack **topB)
{
	int		i;
	t_stack	*min;
	t_stack	*temp;

	i = 0;
	while (i < 2)
	{
		update_positions(*topA);
		temp = *topA;
		min = temp;
		while (temp)
		{
			if (temp->index < min->index)
				min = temp;
			temp = temp->ptr;
		}
		rotate_min_to_top(topA, min);
		pb(topA, topB);
		i++;
	}
	sort_three(topA);
	pa(topA, topB);
	pa(topA, topB);
}

t_stack	*find_value(t_stack *topB, int value)
{
	t_stack	*temp;

	temp = topB;
	while (temp)
	{
		if (temp->data == value)
			return (temp);
		temp = temp->ptr;
	}
	return (temp);
}

t_stack	*find_max(t_stack *topB)
{
	t_stack	*max;

	max = topB;
	while (topB)
	{
		if (topB->index > max->index)
			max = topB;
		topB = topB->ptr;
	}
	return (max);
}
