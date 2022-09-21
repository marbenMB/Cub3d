/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:19:27 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/20 18:29:00 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_f_trim(char const *s, char const *t)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == t[j])
		{
			k++;
			i++;
			j = 0;
		}
		else if (!t[j])
			break ;
		else
			j++;
	}
	return (k);
}

static int	ft_n_l_trim(char const *s, char const *t)
{
	int	j;
	int	k;
	int	len_s;

	k = 0;
	j = 0;
	len_s = (ft_strlen((char *)s) - 1);
	while (s[len_s])
	{
		if (s[len_s] == t[j])
		{
			k++;
			len_s--;
			j = 0;
		}
		else if (!t[j])
			break ;
		else
			j++;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*str;
	int		f;
	int		l;

	if (!s1)
		return (0);
	k = 0;
	i = 0;
	f = ft_n_f_trim(s1, set);
	l = (ft_strlen((char *)s1) - ft_n_l_trim(s1, set));
	if (l == 0)
		l = ft_n_l_trim(s1, set);
	str = (char *)malloc (((l - f) + 1) * sizeof(char));
	if (str || (l - f) == 0)
	{
		while (f < l && s1)
			str[i++] = (char )s1[f++];
		str[i] = 0;
		return (str);
	}
	return (0);
}
