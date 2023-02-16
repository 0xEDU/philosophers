/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:11:30 by etachott          #+#    #+#             */
/*   Updated: 2023/02/16 20:11:47 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	validate_argv(int argc, char *argv[])
{
	(void) argv;
	if (argc < 4 || argc > 5)
		return (0);
	return (1);
}
