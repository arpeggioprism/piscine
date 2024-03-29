/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:51:27 by jshin             #+#    #+#             */
/*   Updated: 2021/09/18 14:59:31 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	lt(char i)
{
	write(1, &i, 1);
}

void	tr(int	x, int	y)
{
	lt(48 + x / 10);
	lt(48 + x % 10);
	lt(' ');
	lt(48 + y / 10);
	lt(48 + y % 10);
	if (x != 98)
	{
		lt(',');
		lt(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			tr(a, b);
			b++;
		}
		a++;
	}
}
