/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:10:58 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 14:29:34 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	initialize_arguments(int *argc, char ***argv)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], " ");
		if (*argv == NULL)
			return (ft_putendl_fd("Error", 2), exit(1));
		*argc = vector_length(*argv);
	}
	else
	{
		*argc = *argc - 1;
		*argv = malloc_argv(*argc, (*argv) + 1);
		if (*argv == NULL)
			return (ft_putendl_fd("Error", 2), exit(1));
	}
	if (*argc == 0)
		exit(0);
}

int	vector_length(char **v)
{
	int	i;

	i = 0;
	while (v[i] != NULL)
		i++;
	return (i);
}

char	**malloc_argv(int argc, char **argv)
{
	char	**result;
	int		i;

	result = ft_calloc(argc + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		result[i] = ft_strdup(argv[i]);
		if (result[i] == NULL)
			return (deep_free(result, i), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
