/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:48:53 by jshin             #+#    #+#             */
/*   Updated: 2021/09/14 18:41:53 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int	nb)
{
	if (nb >= 0)
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar(48 + nb % 10);
	}
	else if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
}
