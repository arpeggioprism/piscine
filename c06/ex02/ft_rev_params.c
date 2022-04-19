/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:19:56 by jshin             #+#    #+#             */
/*   Updated: 2021/09/27 14:50:45 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	temp;

	while (*str)
	{
		temp = *str;
		write(1, &temp, 1);
		str++;
	}
}

int	main(int	argc, char **argv)
{
	argc--;
	while (argc != 0)
	{
		ft_putstr(argv[argc]);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
