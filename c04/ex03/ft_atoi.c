/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 06:35:38 by jshin             #+#    #+#             */
/*   Updated: 2021/09/22 11:44:44 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isspace(unsigned char	c)
{
	if (c == '\t' || c == '\n' || c == '\f')
		return (1);
	if (c == ' ' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int	ft_number(unsigned char	c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char	*str)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_number(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}
