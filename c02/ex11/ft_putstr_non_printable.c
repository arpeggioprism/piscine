/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:19:48 by jshin             #+#    #+#             */
/*   Updated: 2021/09/21 04:23:04 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_print_non(unsigned char	np)
{
	ft_putchar('\\');
	if (np / 16 >= 10)
		ft_putchar((np / 16) - 10 + 'a');
	else
		ft_putchar((np / 16) + '0');
	if (np % 16 >= 10)
		ft_putchar((np % 16) - 10 + 'a');
	else
		ft_putchar((np % 16) + '0');
}

void	ft_putstr_non_printable(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_print_non(str[i]);
		i++;
	}
}
