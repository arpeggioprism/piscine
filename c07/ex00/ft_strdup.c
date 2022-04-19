/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:59:12 by jshin             #+#    #+#             */
/*   Updated: 2021/09/27 16:04:17 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char	*src)
{
	char	*dest;
	int		len;
	char	*dest_p;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == 0)
		return ((char *)0);
	dest_p = dest;
	while (*src)
		*(dest_p++) = *(src++);
	*dest_p = 0;
	return (dest);
}
