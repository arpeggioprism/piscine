/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 01:10:03 by jshin             #+#    #+#             */
/*   Updated: 2021/09/20 17:03:40 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int	size)
{
	unsigned int	i;

	i = 0;
	while (*dest && i < size)
	{
		dest++;
		i++;
	}
	while (*src && (i + 1 < size))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
		*dest = 0;
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
