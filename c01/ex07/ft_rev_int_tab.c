/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:30:10 by jshin             #+#    #+#             */
/*   Updated: 2021/09/16 14:08:19 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int	*a, int	*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int	*tab, int	size)
{
	int	low;
	int	high;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		swap(&tab[low], &tab[high]);
		low++;
		high--;
	}
}
