/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_generic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:45:34 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 13:34:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	swap(t_stack *s)
{
	int	*a;
	int	*b;

	if (s->size_stack >= 2)
	{
		a = s->array + s->start;
		b = s->array + ((s->start + 1) % s->size_array);
		swap_int(a, b);
	}
}

void	push(t_stack *a, t_stack *b)
{
	if (a->size_stack == 0)
		return ;
	b->start = get_previous_index(b, b->start);
	if (b->size_stack == 0)
		b->end = b->start;
	b->array[b->start] = a->array[a->start];
	b->size_stack = b->size_stack + 1;
	a->start = (a->start + 1) % a->size_array;
	a->size_stack = a->size_stack - 1;
}

void	rotate(t_stack *s)
{
	if (s->size_stack >= 2)
	{
		s->end = (s->end + 1) % s->size_array;
		s->array[s->end] = s->array[s->start];
		s->start = (s->start + 1) % s->size_array;
	}
}

void	reverse_rotate(t_stack *s)
{
	if (s->size_stack >= 2)
	{
		s->start = get_previous_index(s, s->start);
		s->array[s->start] = s->array[s->end];
		s->end = get_previous_index(s, s->end);
	}
}
