/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:28:56 by akoudri           #+#    #+#             */
/*   Updated: 2025/10/24 12:29:05 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (free((void *)s1), NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(s1_len + s2_len + 3);
	if (ptr == NULL)
		return (free((void *)s1), NULL);
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
	free ((void *)s1);
	return (ptr);
}
