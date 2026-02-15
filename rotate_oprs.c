/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oprs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:46:10 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:46:17 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **topA, int sign)
{
	t_stack	*saved_head;
	t_stack	*new_head;
	t_stack	*tail;

	if (*topA == NULL || (*topA)->ptr == NULL)
		return ;
	saved_head = *topA;
	new_head = saved_head->ptr;
	tail = saved_head;
	while (tail->ptr)
		tail = tail->ptr;
	tail->ptr = saved_head;
	*topA = new_head;
	saved_head->ptr = NULL;
	if (sign == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **topB, int sign)
{
	t_stack	*saved_head;
	t_stack	*new_head;
	t_stack	*tail;

	if (*topB == NULL || (*topB)->ptr == NULL)
		return ;
	saved_head = *topB;
	new_head = saved_head->ptr;
	tail = saved_head;
	while (tail->ptr)
		tail = tail->ptr;
	tail->ptr = saved_head;
	*topB = new_head;
	saved_head->ptr = NULL;
	if (sign == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **topA, t_stack **topB)
{
	ra(topA, 0);
	rb(topB, 0);
	write(1, "rr\n", 3);
}
