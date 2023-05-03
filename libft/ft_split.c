/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:35:14 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/23 12:25:01 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	**free_tab(char **tab, size_t count)
{
	size_t	i;

	i = 0;
	while (i <= count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	space_count;
	size_t	i;

	i = 0;
	space_count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		space_count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (space_count);
}

static char	**pupulate_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	last_space;
	size_t	space_count;

	i = 0;
	last_space = 0;
	space_count = 0;
	while (s[i] == c && s[i])
		last_space = ++i;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		tab[space_count] = ft_substr(s, last_space, i - last_space);
		if (!tab[space_count])
			return (free_tab(tab, space_count));
		space_count++;
		while (s[i] == c && s[i])
		{
			i++;
			last_space = i;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	space_count;

	if (!s)
		return (NULL);
	space_count = count_words(s, c);
	result = malloc((space_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[space_count] = 0;
	return (pupulate_tab(result, s, c));
}
