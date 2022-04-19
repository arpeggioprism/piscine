/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:48:44 by jshin             #+#    #+#             */
/*   Updated: 2021/09/19 19:20:41 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char	*str, char	*to_find)
{
	char	*a;
	char	*b;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		a = str;
		b = to_find;
		while (*b && (*a == *b))
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return (str);
		str++;
	}
	return (0);
}
