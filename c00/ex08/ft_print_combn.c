/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:44:34 by jshin             #+#    #+#             */
/*   Updated: 2021/09/18 14:56:38 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_arr(int	*arr, int	len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

void	recursive(int	*arr, int	len, int	idx, int	cnt)
{
	if (cnt > 9)
	{
		if (idx == 0)
			return ;
		recursive(arr, len, idx - 1, arr[idx - 1] + 1);
		return ;
	}
	arr[idx] = cnt;
	if (idx == len - 1)
	{
		ft_arr(arr, len);
		if (arr[0] <= 9 - len)
			write(1, ", ", 2);
		recursive(arr, len, idx, cnt + 1);
		return ;
	}
	else
	{
		recursive(arr, len, idx + 1, cnt + 1);
	}
}

void	ft_print_combn(int	n)
{
	int	arr[9];

	recursive(arr, n, 0, 0);
}
