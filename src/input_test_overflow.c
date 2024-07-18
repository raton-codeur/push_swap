/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_test_overflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:43:18 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 14:43:26 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

static char	*skip_zero(char *s)
{
	int		i;
	char	*result;

	i = 0;
	result = s;
	while (s[i] == '0')
	{
		result++;
		i++;
	}
	if (s[i] == '\0')
		result--;
	return (result);
}

static int	string_is_greater(char *s, char *model)
{
	int	i;
	int	length_s;
	int	length_model;

	length_s = ft_strlen(s);
	length_model = ft_strlen(model);
	if (length_s > length_model)
		return (1);
	else if (length_s < length_model)
		return (0);
	else
	{
		i = 0;
		while (i < length_model)
		{
			if (s[i] > model[i])
				return (1);
			else if (s[i] < model[i])
				return (0);
			else
				i++;
		}
		return (0);
	}
}

int	input_test_overflow(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '+')
		{
			if (string_is_greater(skip_zero(argv[i] + 1), "2147483647"))
				return (1);
		}
		else if (argv[i][0] == '-')
		{
			if (string_is_greater(skip_zero(argv[i] + 1), "2147483648"))
				return (1);
		}
		else if (string_is_greater(skip_zero(argv[i]), "2147483647"))
			return (1);
		i++;
	}
	return (0);
}
