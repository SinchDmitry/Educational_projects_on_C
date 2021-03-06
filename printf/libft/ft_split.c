/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchiba <aarchiba@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:58:02 by aarchiba          #+#    #+#             */
/*   Updated: 2021/11/08 22:58:02 by aarchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	to_malloc_big(char const *s, char c)
{
	size_t	i;
	size_t	f;

	i = 0;
	f = 0;
	if (s[0] && s[0] != c)
	{
		f++;
		i++;
	}
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			f++;
		i++;
	}
	return (f + 1);
}

static void	delall(char	**res, size_t	a)
{
	while (a)
	{
		a--;
		free(res[a]);
	}
	free (res);
}

static char	**to_malloc_str(char **res, char const *s, char c, long i)
{
	size_t	a;
	long	j;
	size_t	f;

	i = -1;
	a = 0;
	while (s[++i] && s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i] && s[i] != c && i == 0))
		{
			j = i++;
			if (s[i - 1] && s[i - 1] != c && i == 1)
				j--;
			f = 0;
			while (s[i] && s[i] != c)
				i++;
			res[a] = malloc (sizeof(char) * ((i--) - j));
			if (!res[a])
				delall(res, a);
			while (++j <= i)
				res[a][f++] = s[j];
			res[a++][f] = '\0';
		}	
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	f;
	char	**res;

	i = 0;
	if (s && *s)
	{
		f = to_malloc_big(s, c);
		res = malloc(sizeof(char *) * f);
		if (!res)
			return (NULL);
		res[f - 1] = NULL;
		return (to_malloc_str(res, s, c, i));
	}
	res = malloc(sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = NULL;
	return (res);
}
