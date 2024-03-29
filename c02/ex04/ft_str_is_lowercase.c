/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:44:30 by jshin             #+#    #+#             */
/*   Updated: 2021/09/21 05:53:20 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char	*str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!(*str <= 'z' && *str >= 'a'))
			return (0);
		str++;
	}
	return (1);
}
