/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:30:33 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/06 12:30:47 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_tab(int *tab, int size)
{
	int		i;
	char	c;

	i = -1;
	while (++i < size * size)
	{
		c = '0' + tab[i];
		write(1, &c, 1);
		if (i % size != size - 1)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
	}
	return ;
}
