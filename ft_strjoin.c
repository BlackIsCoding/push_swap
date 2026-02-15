/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:54:37 by akoudri           #+#    #+#             */
/*   Updated: 2026/01/16 13:54:48 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 3);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i++] = ' ';
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = ' ';
	ptr[i + j + 1] = '\0';
	return (free((void *)s1), ptr);
}
