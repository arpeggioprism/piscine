/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 07:47:56 by jshin             #+#    #+#             */
/*   Updated: 2021/09/22 10:16:03 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	ft_valid(char	*base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putnbr_base(int	nbr, char	*base)
{
	int	basenbr;

	basenbr = ft_valid(base);
	if (!basenbr)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr_base((nbr / basenbr) * -1, base);
		ft_putchar(base[(nbr % basenbr) *(-1)]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr >= basenbr)
	{
		ft_putnbr_base((nbr / basenbr), base);
		ft_putnbr_base((nbr % basenbr), base);
	}
	else
		ft_putchar(base[nbr]);
}
