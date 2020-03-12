/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:20:18 by fallard           #+#    #+#             */
/*   Updated: 2019/09/20 15:45:08 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[i] != c)
		j = j + 1;
	while (str[i] && i < (ft_strlen(str) - 1))
	{
		if (str[i] == c && str[i + 1] != c)
			j = j + 1;
		i = i + 1;
	}
	return (j);
}

static int		word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i = i + 1;
	while (s[i] != c && s[i])
	{
		i = i + 1;
		len = len + 1;
	}
	return (len);
}

static char		**ft_freemem(char **fresh, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(fresh[i]);
		i = i + 1;
	}
	free(fresh);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s || !(fresh = malloc(sizeof(*fresh) * (count_words(s, c) + 1))))
		return (NULL);
	while (i < count_words(s, c))
	{
		j = 0;
		if (!(fresh[i] = ft_strnew(word_len(&s[k], c))))
			ft_freemem(fresh, i);
		while (s[k] == c)
			k = k + 1;
		while (s[k] != c && s[k])
			fresh[i][j++] = s[k++];
		fresh[i][j] = '\0';
		i = i + 1;
	}
	fresh[i] = NULL;
	return (fresh);
}
