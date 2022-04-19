/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:00:24 by jshin             #+#    #+#             */
/*   Updated: 2021/09/26 22:37:27 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	is_charset(char	c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long	charset_void_cnt(char	*str, char	*charset)
{
	long long	cnt;

	cnt = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			str++;
			cnt++;
			while (*str && !is_charset(*str, charset))
				str++;
			str--;
		}
		str++;
	}
	return (cnt);
}

void	ft_strcpy(char	*dest, char *src, char *fin)
{
	while (src < fin)
		*(dest++) = *(src++);
	*dest = 0;
}

char	**ft_split(char	*str, char *charset)
{
	char	**ans;
	char	*temp;
	int		i;

	i = 0;
	ans = (char **)malloc(sizeof(char *) * charset_void_cnt(str, charset) + 1);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			temp = str;
			str++;
			while (!is_charset(*str, charset) && *str)
				str++;
			ans[i] = (char *)malloc(str - temp + 1);
			ft_strcpy(ans[i++], temp, str);
		}
		str++;
	}
	ans[i] = 0;
	return (ans);
}
