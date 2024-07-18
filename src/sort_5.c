/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:08:28 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:41:14 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

static int	max_on_top_b(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->start;
	j = 0;
	while (j < a->size_stack)
	{
		if (a->array[i] > b->array[b->start])
			return (0);
		i = (i + 1) % a->size_array;
		j++;
	}
	return (1);
}

static void	insert_top_b(t_stack *a, t_stack *b, t_list **operations)
{
	if (max_on_top_b(a, b))
	{
		while (!is_sorted(a))
			ra(a, b, operations);
		pa(a, b, operations);
		ra(a, b, operations);
	}
	else
	{
		while (b->array[b->start] > a->array[a->start])
			ra(a, b, operations);
		pa(a, b, operations);
	}
}

void	sort_5(t_stack *a, t_stack *b, t_list **operations)
{
	pb(a, b, operations);
	pb(a, b, operations);
	base_only_3_a((t_sub_stack){a, b, top_a, 3}, operations);
	if (b->array[b->start] > b->array[(b->start + 1) % b->size_array])
		sb(a, b, operations);
	insert_top_b(a, b, operations);
	insert_top_b(a, b, operations);
	if (!is_sorted(a))
	{
		while (!is_sorted(a))
			ra(a, b, operations);
	}
}
