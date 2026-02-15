/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:44:49 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/18 19:04:57 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stackk_size(t_stack *top)
{
	size_t	count;

	count = 0;
	while (top)
	{
		count++;
		top = top->ptr;
	}
	return (count);
}

static void	push_to_b(t_stack **topA, t_stack **topB,
			size_t *start, size_t *end)
{
	pb(topA, topB);
	if ((*topB)->index <= *start)
		rb(topB, 1);
	(*end)++;
	(*start)++;
}

static void	help_fun(t_stack **topA, t_stack **topB,
		t_stack *max_node, size_t target_pos)
{
	size_t	size;

	size = stackk_size(*topB);
	if (target_pos <= (size / 2) + 1)
	{
		while (target_pos--)
			rb(topB, 1);
	}
	else
	{
		while (target_pos++ < size)
			rrb(topB, 1);
	}
	if ((*topB)->data == max_node->data - 1)
		pa(topA, topB);
	else
	{
		pa(topA, topB);
		if ((*topA)->ptr && (*topA)->data > (*topA)->ptr->data)
			sa(topA, 1);
	}
}

static void	push_back(t_stack **topA, t_stack **topB)
{
	size_t	target_pos;
	t_stack	*max_node;
	t_stack	*prev_node;

	while (*topB)
	{
		update_positions(*topB);
		max_node = find_max(*topB);
		prev_node = find_value(*topB, max_node->data - 1);
		if (prev_node && prev_node->position < max_node->position)
			target_pos = prev_node->position;
		else
			target_pos = max_node->position;
		help_fun(topA, topB, max_node, target_pos);
	}
}

void	chunks_sorting(t_stack **topA, t_stack **topB)
{
	size_t	size;
	ssize_t	chunk;
	size_t	start;
	size_t	end;

	size = stackk_size(*topA);
	if (size <= 100)
		chunk = size / 5;
	else
		chunk = size / 14;
	end = chunk - 1;
	start = 0;
	while (*topA)
	{
		if ((*topA)->index <= end)
			push_to_b(topA, topB, &start, &end);
		else
			ra(topA, 1);
	}
	push_back(topA, topB);
}
