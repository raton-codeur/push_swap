/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:24:36 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/30 15:40:15 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_H
# define F_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size_array;
	int	size_stack;
	int	start;
	int	end;
}	t_stack;

enum e_position {top_a, top_b, bottom_a, bottom_b};

typedef struct s_sub_stack
{
	t_stack			*a;
	t_stack			*b;
	enum e_position	position;
	int				size;
}	t_sub_stack;

typedef struct s_next
{
	t_sub_stack	high;
	t_sub_stack	medium;
	t_sub_stack	low;
}	t_next;

enum e_permutation_3 {
	abc,
	acb,
	bac,
	bca,
	cab,
	cba
};

typedef struct s_pivot
{
	int	a;
	int	b;
}		t_pivot;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

enum e_case_2_nodes
{
	sa_sb,
	ra_rb,
	rra_rrb,
	sa_sa,
	sb_sb,
	pa_pb,
	ra_rra,
	rb_rrb,
	other
};

/* initialization.c */
void	initialization(int *argc, char **argv, t_stack **a, t_stack **b);
t_stack	*substitute_values(t_stack *a, t_stack *b);
int		get_new_value(t_stack *a, int i);
t_stack	*new_stack(int n);

/* initialize_arguments.c */
void	initialize_arguments(int *argc, char ***argv);
int		vector_length(char **v);
char	**malloc_argv(int argc, char **argv);

/* free.c */
void	deep_free(char **a, int i);
void	free_stack(t_stack *s);
void	free_stacks(t_stack *a, t_stack *b);

/* wrong_input.c */
int		wrong_input(int argc, char **argv);
int		input_test_is_number(int argc, char **argv);
int		input_test_duplicate(int argc, char **argv);

/* input_test_overflow.c */
int		input_test_overflow(int argc, char **argv);

/* operation_generic.c */
void	swap(t_stack *s);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

/* operation_generic_utils.c */
void	swap_int(int *a, int *b);
int		get_previous_index(t_stack *s, int i);

/* operation_1.c */
void	sa(t_stack *a, t_stack *b, t_list **operations);
void	sb(t_stack *a, t_stack *b, t_list **operations);
void	ss(t_stack *a, t_stack *b, t_list **operations);
void	pb(t_stack *a, t_stack *b, t_list **operations);
void	pa(t_stack *a, t_stack *b, t_list **operations);

/* operation_2.c */
void	ra(t_stack *a, t_stack *b, t_list **operations);
void	rb(t_stack *a, t_stack *b, t_list **operations);
void	rr(t_stack *a, t_stack *b, t_list **operations);

/* operation_3.c */
void	rra(t_stack *a, t_stack *b, t_list **operations);
void	rrb(t_stack *a, t_stack *b, t_list **operations);
void	rrr(t_stack *a, t_stack *b, t_list **operations);

/* sort.c */
t_list	*sort(t_stack *a, t_stack *b);
void	sort_recursive(t_sub_stack ss, t_list **operations);
int		is_sorted(t_stack *s);

/* sort_5.c */
void	sort_5(t_stack *a, t_stack *b, t_list **operations);

/* get_from_sub_stack_1.c */
t_next	get_next_sub_stacks(t_sub_stack ss);
int		get_value(t_sub_stack ss, int i);
int		get_next_value(t_sub_stack ss, int n);
int		get_lowest_value(t_sub_stack ss);

/* get_from_sub_stack_2.c */
void	get_array_and_start(t_sub_stack ss, int **array, int *i);
int		get_next_index(t_sub_stack ss, int i);

/* push_sub_stack.c */
void	push_sub_stack(\
	t_sub_stack *ss, t_next *next, t_pivot pivot, t_list **operations);
void	push_sub_stack_top(\
	t_sub_stack *ss1, t_sub_stack *ss2, t_list **operations);

/* optimization.c */
int		optimize(t_list **operations);

/* base_case.c */
void	base_case(t_sub_stack ss, t_list **operations);
void	base_2(t_sub_stack ss, t_sub_stack ss_top_a, t_list **operations);
void	base_bottom_b_ab(t_sub_stack ss, t_list **operations);
int		get_case_3(t_sub_stack ss);

/* base_3_generic.c */
void	base_3_top_a(t_sub_stack ss, t_list **operations);
void	base_3_top_b(t_sub_stack ss, t_list **operations);
void	base_3_bottom_a(t_sub_stack ss, t_list **operations);
void	base_3_bottom_b(t_sub_stack ss, t_list **operations);

/* base_3_top_a.c */
void	base_only_3_a(t_sub_stack ss, t_list **operations);
void	base_top_a_acb(t_sub_stack ss, t_list **operations);
void	base_top_a_bca(t_sub_stack ss, t_list **operations);
void	base_top_a_cab(t_sub_stack ss, t_list **operations);
void	base_top_a_cba(t_sub_stack ss, t_list **operations);

/* base_3_top_b_1.c */
void	base_top_b_abc(t_sub_stack ss, t_list **operations);
void	base_top_b_acb(t_sub_stack ss, t_list **operations);
void	base_top_b_bac(t_sub_stack ss, t_list **operations);

/* base_3_top_b_2.c */
void	base_top_b_bca(t_sub_stack ss, t_list **operations);
void	base_top_b_cab(t_sub_stack ss, t_list **operations);
void	base_top_b_cba(t_sub_stack ss, t_list **operations);

/* base_3_bottom_a_1.c */
void	base_bottom_a_abc(t_sub_stack ss, t_list **operations);
void	base_bottom_a_acb(t_sub_stack ss, t_list **operations);
void	base_bottom_a_bac(t_sub_stack ss, t_list **operations);

/* base_3_bottom_a_2.c */
void	base_bottom_a_bca(t_sub_stack ss, t_list **operations);
void	base_bottom_a_cab(t_sub_stack ss, t_list **operations);
void	base_bottom_a_cba(t_sub_stack ss, t_list **operations);

/* base_3_bottom_b_1.c */
void	base_bottom_b_abc(t_sub_stack ss, t_list **operations);
void	base_bottom_b_acb(t_sub_stack ss, t_list **operations);
void	base_bottom_b_bac(t_sub_stack ss, t_list **operations);

/* base_3_bottom_b_2.c */
void	base_bottom_b_bca(t_sub_stack ss, t_list **operations);
void	base_bottom_b_cab(t_sub_stack ss, t_list **operations);
void	base_bottom_b_cba(t_sub_stack ss, t_list **operations);

/* list.c */
t_list	*list_new(char *content);
t_list	*list_last(t_list *l);
int		list_add_back(t_list **l, char *content);
void	list_clear(t_list **l);
void	list_print(t_list *l);

#endif