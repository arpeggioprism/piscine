/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:19:28 by jshin             #+#    #+#             */
/*   Updated: 2021/09/22 17:19:27 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_baseidx(char	c, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_valid(char	*base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\f' || base[i] == '\v'
			|| base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_atoi_base(char	*str, char	*base)
{
	int	i;
	int	result;
	int	sign;
	int	basenbr;

	result = 0;
	sign = 1;
	basenbr = ft_valid(base);
	if (!basenbr)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\f' || base[i] == '\v'
			|| base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
	while (*str)
	{
		i = ft_baseidx(*str++, base);
		if (i != -1)
			result = result * basenbr + i;
		else
			break ;
	}
	return (result * sign);
}

int main(void)
{
	ft_atoi_base("   124et55", "0123456789");
	return (0);
}
