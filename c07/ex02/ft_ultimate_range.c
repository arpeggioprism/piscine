/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:27:24 by jshin             #+#    #+#             */
/*   Updated: 2021/09/23 21:41:41 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int	**range, int	min, int	max)
{
	int	size;
	int	*temp;

	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	temp = *range;
	while (min < max)
	{
		*temp = min;
		min++;
		temp++;
	}
	return (size);
}
