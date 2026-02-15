/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:50:12 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:51:30 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	only_spaces_check(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	space_valid(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i < argc)
	{
		if (only_spaces_check(argv[i]))
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check == 1)
		return (0);
	return (1);
}

static int	check_letters(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && (s[i + 1] >= '0'
				&& s[i + 1] <= '9') && s[i - 1] == ' ')
		{
			i++;
			continue ;
		}
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	letters_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_letters(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*args_joining(int argc, char **argv)
{
	int		i;
	char	*join;

	join = malloc(1);
	if (!join)
		return (NULL);
	join[0] = '\0';
	i = 1;
	while (i < argc)
	{
		join = ft_strjoin(join, argv[i]);
		if (!join)
		{
			free(join);
			break ;
		}
		i++;
	}
	return (join);
}
