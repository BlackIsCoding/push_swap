/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_oprs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:46:32 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:46:38 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **topA, int sign)
{
	t_stack	*current;
	t_stack	*prev;

	if (*topA == NULL || (*topA)->ptr == NULL)
		return ;
	current = *topA;
	prev = NULL;
	while (current->ptr)
	{
		prev = current;
		current = current->ptr;
	}
	prev->ptr = NULL;
	current->ptr = *topA;
	*topA = current;
	if (sign == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **topB, int sign)
{
	t_stack	*current;
	t_stack	*prev;

	if (*topB == NULL || (*topB)->ptr == NULL)
		return ;
	current = *topB;
	prev = NULL;
	while (current->ptr)
	{
		prev = current;
		current = current->ptr;
	}
	prev->ptr = NULL;
	current->ptr = *topB;
	*topB = current;
	if (sign == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **topA, t_stack **topB)
{
	rra(topA, 0);
	rrb(topB, 0);
	write(1, "rrr\n", 4);
}
