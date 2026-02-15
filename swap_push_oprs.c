/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_oprs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:45:26 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/18 18:43:16 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **topA, int flag)
{
	t_stack	*first;
	t_stack	*second;

	if (!topA || !*topA || !(*topA)->ptr)
		return ;
	first = *topA;
	second = first->ptr;
	first->ptr = second->ptr;
	second->ptr = first;
	*topA = second;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **topB, int flag)
{
	t_stack	*first;
	t_stack	*second;

	if (!topB || !*topB || !(*topB)->ptr)
		return ;
	first = *topB;
	second = first->ptr;
	first->ptr = second->ptr;
	second->ptr = first;
	*topB = second;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **topA, t_stack **topB)
{
	sa(topA, 0);
	sb(topB, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **topA, t_stack **topB)
{
	t_stack	*save_topb;

	if (!(*topB))
		return ;
	save_topb = *topB;
	*topB = save_topb->ptr;
	save_topb->ptr = *topA;
	*topA = save_topb;
	write(1, "pa\n", 3);
}

void	pb(t_stack **topA, t_stack **topB)
{
	t_stack	*save_topa;

	if (!(*topA))
		return ;
	save_topa = *topA;
	*topA = save_topa->ptr;
	save_topa->ptr = *topB;
	*topB = save_topa;
	write(1, "pb\n", 3);
}
