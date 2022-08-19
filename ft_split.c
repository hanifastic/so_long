/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:27:19 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:30:38 by hsisman          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wordcounter(const char *p, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*p)
	{
		if (*p != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*p == c)
			trigger = 0;
		p++;
	}
	return (i);
}

static char	*worddup(const char *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	i;
	int		a;
	int		start;

	if (!s)
		return (0);
	i = -1;
	a = 0;
	start = -1;
	split = malloc(sizeof(char *) * (wordcounter(s, c) + 1));
	if (!split)
		return (0);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[a++] = worddup(s, start, i);
			start = -1;
		}
	}
	split[a] = NULL;
	return (split);
}
