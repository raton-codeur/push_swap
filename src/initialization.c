/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:05:01 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:42:31 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	initialization(int *argc, char **argv, t_stack **a, t_stack **b)
{
	int		i;

	initialize_arguments(argc, &argv);
	if (wrong_input(*argc, argv))
		return (deep_free(argv, *argc), ft_putendl_fd("Error", 2), exit(1));
	*a = new_stack(*argc);
	*b = new_stack(*argc);
	if (a == NULL || b == NULL)
	{
		free_stacks(*a, *b);
		return (deep_free(argv, *argc), ft_putendl_fd("Error", 2), exit(1));
	}
	i = 0;
	while (i < *argc)
	{
		(*a)->array[i] = ft_atoi(argv[i]);
		i++;
	}
	deep_free(argv, *argc);
	(*a)->end = i - 1;
	(*a)->size_stack = *argc;
	*a = substitute_values(*a, *b);
}

t_stack	*substitute_values(t_stack *a, t_stack *b)
{
	t_stack	*result;
	int		i;

	result = new_stack(a->size_stack);
	if (result == NULL)
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1), NULL);
	result->size_stack = a->size_stack;
	result->end = a->end;
	i = 0;
	while (i < a->size_stack)
	{
		result->array[i] = get_new_value(a, i);
		i++;
	}
	free_stack(a);
	return (result);
}

int	get_new_value(t_stack *a, int i)
{
	int	j;
	int	result;

	result = 0;
	j = 0;
	while (j < a->size_stack)
	{
		if (a->array[j] < a->array[i])
			result++;
		j++;
	}
	return (result);
}

t_stack	*new_stack(int n)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (result == NULL)
		return (NULL);
	result->array = ft_calloc(n, sizeof(int));
	if (result->array == NULL)
		return (free(result), NULL);
	result->size_array = n;
	result->size_stack = 0;
	result->start = 0;
	result->end = 0;
	return (result);
}
