/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:29:09 by jshin             #+#    #+#             */
/*   Updated: 2021/09/19 16:42:05 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char	*dest, char	*src)
{
	char	*temp;

	temp = dest;
	while (*temp)
		temp++;
	while (*src)
	{
		*temp = *src;
		src++;
		temp++;
	}
	*temp = 0;
	return (dest);
}
