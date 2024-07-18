/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:54:06 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 14:44:10 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

int	wrong_input(int argc, char **argv)
{
	return (input_test_is_number(argc, argv)
		|| input_test_overflow(argc, argv)
		|| input_test_duplicate(argc, argv));
}

int	input_test_is_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!ft_isdigit(argv[i][j++]))
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_test_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
