/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:36:21 by jshin             #+#    #+#             */
/*   Updated: 2021/09/26 21:50:17 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	is_whitespace(char c);
int	is_valid(char *base, int	*len);
int	ft_strlen(long long nbr, int	base_len);

long long	nbr_to_base(char	*str, char *base, int	len)
{
	long long	ans;
	int			sign;
	int			i;

	ans = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		i = -1;
		while (++i < len)
		{
			if (*str == base[i])
				break ;
		}
		if (i == len)
			break ;
		ans = ans * len + (sign * i);
		str++;
	}
	return (ans);
}

char	*base_to_base(long long	nbr, char	*base, int	len)
{
	long long	temp;
	char		*ans;
	int			size;

	if (nbr == 0)
	{
		ans = (char *)malloc(2);
		ans[0] = base[0];
		ans[1] = 0;
		return (ans);
	}
	temp = nbr;
	size = ft_strlen(temp, len);
	ans = (char *)malloc(size + 1);
	ans[size] = 0;
	if (temp < 0)
		temp *= -1;
	while (temp)
	{
		ans[--size] = base[temp % len];
		temp /= len;
	}
	if (nbr < 0)
		ans[0] = '-';
	return (ans);
}

char	*ft_convert_base(char	*nbr, char	*base_from, char	*base_to)
{
	int	fr_len;
	int	to_len;

	if (!is_valid(base_from, &fr_len) || !is_valid(base_to, &to_len))
		return (0);
	return (base_to_base(nbr_to_base(nbr, base_from, fr_len), base_to, to_len));
}
