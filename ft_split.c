/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoudri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:56:00 by akoudri           #+#    #+#             */
/*   Updated: 2025/10/27 16:36:06 by akoudri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_strings(const char *string, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if ((i == 0 && string[i] != c)
			|| (string[i] != c && (string[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static size_t	words_detect(char const *s, char c, size_t *index_ptr)
{
	size_t	i;
	size_t	start_ptr;
	size_t	end_ptr;

	i = *index_ptr;
	while (s[i] == c)
		i++;
	start_ptr = i;
	while (s[i] != c && s[i])
		i++;
	end_ptr = i;
	*index_ptr = i;
	return (end_ptr - start_ptr);
}

static char	**free_mem(char **ptr, int i)
{
	while (i >= 0)
	{
		free (ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

static char	**fill_ptrs(char **ptr, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	word_len;
	size_t	current_index;

	i = 0;
	current_index = 0;
	while (i < count)
	{
		word_len = words_detect(s, c, &current_index);
		ptr[i] = malloc(word_len + 1);
		if (ptr[i] == NULL)
			return (free_mem(ptr, i));
		j = 0 ;
		while (j < word_len)
		{
			ptr[i][j] = s[(current_index - word_len) + j];
			j++;
		}
		ptr[i][j] = '\0';
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = count_strings(s, c);
	ptr = malloc(sizeof(char *) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	return (fill_ptrs(ptr, s, c, count));
}

// int main(){
// 	char **ptr = ft_split("", ' ');
// 	int i = 0 ;
// 	while (ptr[i])
// 		printf("%s", ptr[i++]);
// 	if(ptr[i][0] == '\0')
// 		printf("no");
// }
