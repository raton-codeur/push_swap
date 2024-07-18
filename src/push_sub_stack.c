/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sub_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:54 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:50:38 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	push_sub_stack(\
	t_sub_stack *ss, t_next *next, t_pivot pivot, t_list **operations)
{
	int			i;
	int			*array;
	int			j;
	int			size;
	t_sub_stack	*ss2;

	i = 0;
	get_array_and_start(*ss, &array, &j);
	size = ss->size;
	while (i < size)
	{
		if (array[j] >= pivot.b)
			ss2 = &(next->high);
		else if (array[j] >= pivot.a)
			ss2 = &(next->medium);
		else
			ss2 = &(next->low);
		push_sub_stack_top(ss, ss2, operations);
		j = get_next_index(*ss, j);
		i++;
	}
}

void	push_sub_stack_top(\
	t_sub_stack *ss1, t_sub_stack *ss2, t_list **operations)
{
	if (ss1->position == ss2->position)
		return ;
	if (ss1->position == bottom_a)
		rra(ss1->a, ss1->b, operations);
	else if (ss1->position == bottom_b)
		rrb(ss1->a, ss1->b, operations);
	if ((ss1->position == top_a || ss1->position == bottom_a)
		&& (ss2->position == top_b || ss2->position == bottom_b))
		pb(ss1->a, ss1->b, operations);
	else if ((ss1->position == top_b || ss1->position == bottom_b)
		&& (ss2->position == top_a || ss2->position == bottom_a))
		pa(ss1->a, ss1->b, operations);
	if (ss2->position == bottom_a)
		ra(ss1->a, ss1->b, operations);
	else if (ss2->position == bottom_b)
		rb(ss1->a, ss1->b, operations);
	(ss1->size)--;
	(ss2->size)++;
}
