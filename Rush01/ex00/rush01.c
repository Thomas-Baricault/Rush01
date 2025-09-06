/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:25:35 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/06 13:12:38 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		solve(int *tab, int *views, int size, int i);
void	display_tab(int *tab, int size);

int	read_size(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			result = result * 10 + (*str++) - '0';
		else
			return (0);
	}
	return (result);
}

int	*read_views(char *str, int size)
{
	int	*views;
	int	i;
	int	j;

	views = malloc(sizeof(int) * size * 4);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (j < size * 4 && i % 2 == 0 && '0' <= str[i] && str[i] <= '9')
			views[j++] = str[i++] - '0';
		else if (i % 2 == 1 && str[i] == ' ')
			i++;
		else
		{
			free(views);
			return (NULL);
		}
	}
	return (views);
}

int	*init_tab(int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size * size);
	i = 0;
	while (i < size * size)
		tab[i++] = 0;
	return (tab);
}

void	run(int *tab, int *views, int size)
{
	int	found;

	found = solve(tab, views, size, 0);
	if (found)
		display_tab(tab, size);
	else
		write(1, "Error\n", 6);
	free(views);
	free(tab);
	return ;
}

int	main(int argc, char **argv)
{
	int	*views;
	int	size;

	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
			size = read_size(argv[2]);
		else
			size = 4;
		if (size > 0)
		{
			views = read_views(argv[1], size);
			if (views)
			{
				run(init_tab(size), views, size);
				return (0);
			}
		}
	}
	write(1, "Error\n", 6);
	return (0);
}
