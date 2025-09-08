/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:29:58 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/07 14:41:59 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row(int *tab, int *views, int size, int i)
{
	int	j;
	int	max_vleft;
	int	max_vright;
	int	n_left;
	int	n_right;

	max_vleft = 0;
	max_vright = 0;
	n_left = 0;
	n_right = 0;
	j = -1;
	while (++j < size)
	{
		if (tab[i / size * size + j] > max_vleft && ++n_left)
			max_vleft = tab[i / size * size + j];
		if (tab[i / size * size + size - j - 1] > max_vright && ++n_right)
			max_vright = tab[i / size * size + size - j - 1];
	}
	return (n_left == views[size * 2 + i / size]
		&& n_right == views[size * 3 + i / size]);
}

int	check_column(int *tab, int *views, int size, int i)
{
	int	j;
	int	max_vtop;
	int	max_vbottom;
	int	n_top;
	int	n_bottom;

	max_vtop = 0;
	max_vbottom = 0;
	n_top = 0;
	n_bottom = 0;
	j = -1;
	while (++j < size)
	{
		if (tab[size * j + i % size] > max_vtop && ++n_top)
			max_vtop = tab[size * j + i % size];
		if (tab[size * (size - j - 1) + i % size] > max_vbottom && ++n_bottom)
			max_vbottom = tab[size * (size - j - 1) + i % size];
	}
	return (n_top == views[i % size]
		&& n_bottom == views[size + i % size]);
}

int	solve(int *tab, int *views, int size, int i)
{
	int	n;
	int	j;

	if (i == size * size)
		return (1);
	n = 0;
	while (++n <= size)
	{
		j = -1;
		while (++j < size)
			if (tab[i / size * size + j] == n || tab[size * j + i % size] == n)
				j = size + 1;
		if (j == size)
		{
			tab[i] = n;
			if ((i % size != size - 1 || check_row(tab, views, size, i))
				&& (i / size != size - 1 || check_column(tab, views, size, i))
				&& solve(tab, views, size, i + 1))
				return (1);
		}
	}
	tab[i] = 0;
	return (0);
}
