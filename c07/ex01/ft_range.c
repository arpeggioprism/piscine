/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:12:53 by jshin             #+#    #+#             */
/*   Updated: 2021/09/23 21:24:47 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int	min, int	max)
{
	int	*arr;
	int	i;
	int	len;

	if (min >= max)
		return (0);
	i = 0;
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
