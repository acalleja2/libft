/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 06:43:04 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/15 14:30:28 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	bol;

	i = 0;
	count = 0;
	while (s[i])
	{
		bol = 0;
		while (s[i] != c && s[i])
		{
			if (bol == 0)
			{
				bol = 1;
				count++;
			}
			i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static char		**ft_cpy(char const *s, char c, char **tab)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		if (k > 0)
		{
			tab[j][k] = '\0';
			j++;
		}
		if (s[i] && s[i] == c)
			i++;
	}
	return (tab);
}

static char		**ft_norm(char const *s, char c, size_t i, size_t j)
{
	size_t	k;
	size_t	words;
	char	**tab;

	words = ft_words(s, c);
	if (!(tab = malloc(sizeof(char *) * words + 1)))
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			k++;
			i++;
		}
		if (k > 0)
			tab[j++] = (char *)malloc(sizeof(char) * k + 1);
		if (s[i] && s[i] == c)
			i++;
	}
	tab = ft_cpy(s, c, tab);
	tab[words] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (s)
	{
		words = ft_words(s, c);
		if (!(tab = ft_norm(s, c, 0, 0)))
			return (NULL);
		tab = ft_cpy(s, c, tab);
		tab[words] = 0;
		return (tab);
	}
	return (NULL);
}
