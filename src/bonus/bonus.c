/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:22:01 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/15 18:48:13 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../f.h"

static void	do_operation_2(char *s, t_stack *a, t_stack *b)
{
	if (ft_strcmp(s, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(s, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(s, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(s, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(s, "rrr\n") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (ft_putendl_fd("Error", 2), free_stacks(a, b), free(s), exit(1));
}

static void	do_operation_1(char *s, t_stack *a, t_stack *b)
{
	if (s == NULL)
		return ;
	if (ft_strcmp(s, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(s, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(s, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(s, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(s, "ra\n") == 0)
		rotate(a);
	else
		do_operation_2(s, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*s;

	if (argc >= 2)
	{
		initialization(&argc, argv, &a, &b);
		s = get_next_line(0);
		do_operation_1(s, a, b);
		while (s)
		{
			free(s);
			s = get_next_line(0);
			do_operation_1(s, a, b);
		}
		if (b->size_stack == 0 && is_sorted(a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stacks(a, b);
	}
	return (0);
}
