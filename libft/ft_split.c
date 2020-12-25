/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:41:18 by rbourgea          #+#    #+#             */
/*   Updated: 2020/12/25 12:17:19 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cs(char const *s, char c)
{
	int		strings;
	size_t	i;

	i = 0;
	strings = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			strings++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	strings += 1;
	return (strings);
}

static size_t	to_sep(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	*free_result(char **result)
{
	char	**saved;

	saved = result;
	while (*result)
	{
		free(*result);
		result++;
	}
	free(saved);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	nbs[3];

	nbs[0] = 0;
	nbs[1] = 0;
	if (!s || !ft_assign((void *)&res, malloc(sizeof(char *) * (cs(s, c) + 1))))
		return (NULL);
	while (s[nbs[0]])
	{
		if (s[nbs[0]] != c && s[nbs[0]])
		{
			if (!ft_assign((void **)&res[nbs[1]], malloc(sizeof(char *)
							* (to_sep(&s[nbs[0]], c) + 1))))
				return (free_result(res));
			nbs[2] = 0;
			while (s[nbs[0]] != c && s[nbs[0]])
				res[nbs[1]][nbs[2]++] = s[nbs[0]++];
			res[nbs[1]][nbs[2]] = '\0';
			nbs[1]++;
		}
		while (s[nbs[0]] == c && s[nbs[0]])
			nbs[0]++;
	}
	res[nbs[1]] = NULL;
	return (res);
}
