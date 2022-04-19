/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:31:46 by jshin             #+#    #+#             */
/*   Updated: 2021/09/20 17:04:21 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char	*dest, char	*src, unsigned int	nb)
{
	unsigned int	i;
	unsigned int	p;

	i = 0;
	p = 0;
	while (dest[i])
		i++;
	while (p < nb && src[p])
	{
		dest[i + p] = src[p];
		p++;
	}
	dest[i + p] = 0;
	return (dest);
}
