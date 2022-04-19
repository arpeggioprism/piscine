/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:33:23 by jshin             #+#    #+#             */
/*   Updated: 2021/09/20 15:47:12 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char	*str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!(*str <= 126 && *str >= 32))
			return (0);
		str++;
	}
	return (1);
}
