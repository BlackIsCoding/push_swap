/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:58:25 by akoudri           #+#    #+#             */
/*   Updated: 2025/10/25 22:25:50 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	function(const char *nptr, int i, int sign, long long *nbr)
{
	long long	temp;

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = *nbr;
		*nbr = *nbr * 10 + (nptr[i] - '0');
		if (temp > *nbr)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (*nbr * sign);
}

long long	ft_atoi(const char *nptr)
{
	long long			nbr;
	size_t				i;
	int					sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	return (function (nptr, i, sign, &nbr));
}

