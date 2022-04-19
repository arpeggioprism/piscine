/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:20:25 by jshin             #+#    #+#             */
/*   Updated: 2021/09/26 21:34:43 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_strlen(char	*str)
{
	long long	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strcat(char	*ans, char	*str)
{
	while (*str)
		*(ans++) = *(str++);
	return (ans);
}

char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	char		*ans;
	char		*temp;
	long long	len;
	int			i;

	if (size == 0)
	{
		ans = (char *)malloc(1);
		ans[0] = 0;
		return (ans);
	}
	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	ans = (char *)malloc(len + (size - 1) * ft_strlen(sep) + 1);
	i = 1;
	temp = ft_strcat(ans, strs[0]);
	while (i < size)
	{
		temp = ft_strcat(temp, sep);
		temp = ft_strcat(temp, strs[i++]);
	}
	*temp = 0;
	return (ans);
}
