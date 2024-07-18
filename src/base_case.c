/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:11:11 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:40:27 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_case(t_sub_stack ss, t_list **operations)
{
	t_sub_stack	ss_top_a;

	ss_top_a = (t_sub_stack){ss.a, ss.b, top_a, 0};
	if (ss.size == 1)
	{
		if (ss.position != top_a)
			push_sub_stack_top(&ss, &ss_top_a, operations);
	}
	else if (ss.size == 2)
		base_2(ss, ss_top_a, operations);
	else if (ss.position == top_a)
		base_3_top_a(ss, operations);
	else if (ss.position == top_b)
		base_3_top_b(ss, operations);
	else if (ss.position == bottom_a)
		base_3_bottom_a(ss, operations);
	else if (ss.position == bottom_b)
		base_3_bottom_b(ss, operations);
}

void	base_2(t_sub_stack ss, t_sub_stack ss_top_a, t_list **operations)
{
	int	*array;
	int	i;
	int	top;
	int	second;

	get_array_and_start(ss, &array, &i);
	top = array[i];
	i = get_next_index(ss, i);
	second = array[i];
	if (ss.position == top_a)
	{
		if (top > second)
			sa(ss.a, ss.b, operations);
	}
	else if (ss.position == bottom_b && top < second)
		base_bottom_b_ab(ss, operations);
	else
	{
		push_sub_stack_top(&ss, &ss_top_a, operations);
		push_sub_stack_top(&ss, &ss_top_a, operations);
		if (top < second)
			sa(ss.a, ss.b, operations);
	}
}

void	base_bottom_b_ab(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

int	get_case_3(t_sub_stack ss)
{
	int	*array;
	int	i;
	int	n1;
	int	n2;
	int	n3;

	get_array_and_start(ss, &array, &i);
	n1 = array[i];
	i = get_next_index(ss, i);
	n2 = array[i];
	i = get_next_index(ss, i);
	n3 = array[i];
	if (n1 < n2 && n2 < n3)
		return (abc);
	if (n1 < n3 && n3 < n2)
		return (acb);
	if (n2 < n1 && n1 < n3)
		return (bac);
	if (n3 < n1 && n1 < n2)
		return (bca);
	if (n2 < n3 && n3 < n1)
		return (cab);
	else
		return (cba);
}
