/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:05:18 by jshin             #+#    #+#             */
/*   Updated: 2021/09/21 05:58:14 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lower(char	c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_is_upper(char	c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strcapitalize(char	*str)
{
	int	space;
	int	i;

	i = 0;
	space = 1;
	while (str[i])
	{
		if (ft_is_lower(str[i]) || ft_is_upper(str[i]))
		{
			if (space && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			if (!space && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			space = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			space = 0;
		else
			space = 1;
		i++;
	}
	return (str);
}
