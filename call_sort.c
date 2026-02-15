/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:56:23 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:57:01 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **topA)
{
	if ((*topA)->data < (*topA)->ptr->data)
		return ;
	sa(topA, 1);
}

void	sort_three(t_stack **topA)
{
	int	a;
	int	b;
	int	c;

	a = (*topA)->data;
	b = (*topA)->ptr->data;
	c = (*topA)->ptr->ptr->data;
	if (a < b && a < c && b < c)
		return ;
	else if (a < c && a < b && b > c)
	{
		rra(topA, 1);
		sa(topA, 1);
	}
	else if (a > b && a < c && b < c)
		sa(topA, 1);
	else if (a < b && a > c && b > c)
		rra(topA, 1);
	else if (a > b && a > c && b < c)
		ra(topA, 1);
	else if (a > b && a > c && b > c)
	{
		ra(topA, 1);
		sa(topA, 1);
	}
}

void	rotate_min_to_top(t_stack **topA, t_stack *min)
{
	size_t	i;
	size_t	size;

	size = stackk_size(*topA);
	if (min->position <= size / 2)
	{
		i = 0;
		while (i < min->position)
		{
			ra(topA, 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - min->position)
		{
			rra(topA, 1);
			i++;
		}
	}
}

static void	sort_four(t_stack **topA, t_stack **topB)
{
	t_stack	*temp;
	t_stack	*min;

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
	sort_three(topA);
	pa(topA, topB);
}

void	sort_numbers(t_stack **topA, t_stack **topB)
{
	size_t	count;

	count = stackk_size(*topA);
	index_nodes(*topA);
	if (count == 1 || count == 0)
		return ;
	else if (count == 2)
		sort_two(topA);
	else if (count == 3)
		sort_three(topA);
	else if (count == 4)
		sort_four(topA, topB);
	else if (count == 5)
		sort_five(topA, topB);
	else
		chunks_sorting(topA, topB);
}
