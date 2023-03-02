/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:11:30 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:58:11 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_extremes(char *argv[])
{
	int	max;
	int	min;
	int	index;

	max = 2147483647;
	min = -2147483648;
	index = 0;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) > max || ft_atoi(argv[index]) < min)
			return (0);
		index++;
	}
	return (1);
}

static int	check_for_words(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_argv(int argc, char *argv[])
{
	(void) argv;
	if (argc < 5 || argc > 6)
		return (0);
	if (!check_for_words(argv))
		return (0);
	if (!check_extremes(argv))
		return (0);
	return (1);
}
