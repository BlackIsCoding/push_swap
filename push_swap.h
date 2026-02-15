/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:47:51 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:47:59 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*ptr;
	size_t			index;
	size_t			position;
}	t_stack;

t_stack		*find_max(t_stack *topB);
t_stack		*find_value(t_stack *topB, int value);
void		sort_three(t_stack **topA);
void		rotate_min_to_top(t_stack **topA, t_stack *min);
void		sort_five(t_stack **topA, t_stack **topB);
void		free_nodes(t_stack *topA);
size_t		stackk_size(t_stack *top);
char		**split_args(int argc, char **argv);
size_t		count_arguments(char **splitted, int *fail);
void		args_atoi(char **splitted, long *array);
int			check_duplicates(long *array, long element, size_t index);
int			letters_valid(int argc, char **argv);
int			space_valid(int argc, char **argv);
int			check_sort(long *array, size_t size);
char		*args_joining(int argc, char **argv);
void		chunks_sorting(t_stack **topA, t_stack **topB);
void		index_nodes(t_stack *topA);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
long		ft_atoi(const char *nptr);
int			push(int element, t_stack **top);
void		sa(t_stack **topA, int sign);
void		sb(t_stack **topB, int sign);
void		ss(t_stack **topA, t_stack **topB);
void		pa(t_stack **topA, t_stack **topB);
void		pb(t_stack **topA, t_stack **topB);
void		ra(t_stack **topA, int sign);
void		rb(t_stack **topB, int sign);
void		rr(t_stack **topA, t_stack **topB);
void		rra(t_stack **topA, int sign);
void		rrb(t_stack **topB, int sign);
void		rrr(t_stack **topA, t_stack **topB);
void		sort_numbers(t_stack **topA, t_stack **topB);
void		update_positions(t_stack *topA);

#endif
