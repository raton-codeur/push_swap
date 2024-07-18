/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:45 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/29 18:47:20 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

t_list	*sort(t_stack *a, t_stack *b)
{
	t_list	*result;

	result = NULL;
	if (!is_sorted(a))
	{
		if (a->size_stack == 5)
			sort_5(a, b, &result);
		else
			sort_recursive((t_sub_stack){a, b, top_a, a->size_stack}, &result);
	}
	free_stacks(a, b);
	return (result);
}

void	sort_recursive(t_sub_stack ss, t_list **operations)
{
	t_next	next;
	t_pivot	pivot;

	if (ss.size <= 3)
		return (base_case(ss, operations));
	next = get_next_sub_stacks(ss);
	pivot.a = get_value(ss, (ss.size + 1) / 3);
	pivot.b = get_value(ss, ((ss.size + 1) / 3) * 2);
	push_sub_stack(&ss, &next, pivot, operations);
	sort_recursive(next.high, operations);
	sort_recursive(next.medium, operations);
	sort_recursive(next.low, operations);
}

int	is_sorted(t_stack *s)
{
	int	i;
	int	j;
	int	value;
	int	next_value;
	int	next_i;

	if (s->size_stack <= 1)
		return (1);
	j = 0;
	i = s->start;
	value = s->array[i];
	while (j < s->size_stack - 1)
	{
		next_i = (i + 1) % s->size_array;
		next_value = s->array[next_i];
		if (value > next_value)
			return (0);
		i = next_i;
		value = s->array[i];
		j++;
	}
	return (1);
}
