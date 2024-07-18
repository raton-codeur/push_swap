/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:48:59 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/30 15:53:03 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

static void	update_node_and_result(t_list **node, int case_nodes, int *result)
{
	if (case_nodes == other)
		*node = (*node)->next;
	else
	{
		*result = 1;
		*node = (*node)->next->next;
	}
}

static int	process_nodes(
	char *node_content, int case_nodes, t_list **new_operations)
{
	if (case_nodes == sa_sb)
		return (list_add_back(new_operations, "ss"));
	else if (case_nodes == ra_rb)
		return (list_add_back(new_operations, "rr"));
	else if (case_nodes == rra_rrb)
		return (list_add_back(new_operations, "rrr"));
	else if (case_nodes == sa_sa)
		return (0);
	else if (case_nodes == sb_sb)
		return (0);
	else if (case_nodes == pa_pb)
		return (0);
	else if (case_nodes == ra_rra)
		return (0);
	else if (case_nodes == rb_rrb)
		return (0);
	else
		return (list_add_back(new_operations, node_content));
}

static int	get_case_nodes_2(char *a, char *b)
{
	if (!ft_strcmp(a, "sb") && !ft_strcmp(b, "sb"))
		return (sb_sb);
	else if (!ft_strcmp(a, "pa") && !ft_strcmp(b, "pb"))
		return (pa_pb);
	else if (!ft_strcmp(a, "pb") && !ft_strcmp(b, "pa"))
		return (pa_pb);
	else if (!ft_strcmp(a, "ra") && !ft_strcmp(b, "rra"))
		return (ra_rra);
	else if (!ft_strcmp(a, "rra") && !ft_strcmp(b, "ra"))
		return (ra_rra);
	else if (!ft_strcmp(a, "rb") && !ft_strcmp(b, "rrb"))
		return (rb_rrb);
	else if (!ft_strcmp(a, "rrb") && !ft_strcmp(b, "rb"))
		return (rb_rrb);
	else
		return (other);
}

static int	get_case_nodes_1(char *a, char *b)
{
	if (!ft_strcmp(a, "sa") && !ft_strcmp(b, "sb"))
		return (sa_sb);
	else if (!ft_strcmp(a, "sb") && !ft_strcmp(b, "sa"))
		return (sa_sb);
	else if (!ft_strcmp(a, "ra") && !ft_strcmp(b, "rb"))
		return (ra_rb);
	else if (!ft_strcmp(a, "rb") && !ft_strcmp(b, "ra"))
		return (ra_rb);
	else if (!ft_strcmp(a, "rra") && !ft_strcmp(b, "rrb"))
		return (rra_rrb);
	else if (!ft_strcmp(a, "rrb") && !ft_strcmp(b, "rra"))
		return (rra_rrb);
	else if (!ft_strcmp(a, "sa") && !ft_strcmp(b, "sa"))
		return (sa_sa);
	else
		return (get_case_nodes_2(a, b));
}

int	optimize(t_list **operations)
{
	t_list	*new_operations;
	int		result;
	t_list	*node;
	int		case_nodes;

	result = 0;
	new_operations = NULL;
	node = *operations;
	while (node && node->next)
	{
		case_nodes = get_case_nodes_1(node->content, node->next->content);
		if (process_nodes(node->content, case_nodes, &new_operations))
		{
			list_clear(operations);
			return (ft_putendl_fd("Error", 2), exit(1), 0);
		}
		update_node_and_result(&node, case_nodes, &result);
	}
	if (node && list_add_back(&new_operations, node->content))
		return (list_clear(operations), ft_putendl_fd("Error", 2), exit(1), 0);
	list_clear(operations);
	*operations = new_operations;
	return (result);
}
