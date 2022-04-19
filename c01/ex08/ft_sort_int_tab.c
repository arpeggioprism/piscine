/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:53:54 by jshin             #+#    #+#             */
/*   Updated: 2021/09/16 14:07:28 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int	*tab, int	size)
{
	int	idx_1;
	int	idx_2;
	int	temp;

	idx_1 = 0;
	while (idx_1 < size - 1)
	{
		idx_2 = idx_1 + 1;
		while (idx_2 < size)
		{
			if (tab[idx_1] > tab[idx_2])
			{
				temp = tab[idx_1];
				tab[idx_1] = tab[idx_2];
				tab[idx_2] = temp;
			}
			idx_2++;
		}
		idx_1++;
	}
}
