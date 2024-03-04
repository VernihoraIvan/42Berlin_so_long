/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:27:14 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/11 18:23:09 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			words++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

static void	assemble(const char *s, char c, char **result)
{
	int			i;
	const char	*str;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str = s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(str, 0, s - str);
			if (!result[i++])
			{
				while (--i >= 0)
					free(result[i]);
				free(result);
				return ;
			}
		}
		else
			s++;
	}
	result[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	int		word_count;
	char	**result;

	word_count = wordcount(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	assemble(s, c, result);
	return (result);
}
