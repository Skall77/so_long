/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:03:01 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/09 11:03:04 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static void	copy_split(char *dst, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	put_words(char **split, char const *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && str[i + j] != c)
				j++;
			split[k] = malloc(sizeof(char) * (j + 1));
			if (split[k] == NULL)
				return (0);
			copy_split(split[k], str + i, c);
			i = i + j;
			k++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	split = malloc(sizeof(char *) * (size + 1));
	if (split == NULL)
		return (NULL);
	split[size] = 0;
	if (put_words(split, s, c) == 0)
		return (NULL);
	return (split);
}
