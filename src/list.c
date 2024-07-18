/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:37:30 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:13:55 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

t_list	*list_new(char *content)
{
	t_list	*result;
	char	*content_copy;

	result = malloc(sizeof(t_list));
	content_copy = ft_strdup(content);
	if (result == NULL || content_copy == NULL)
		return (free(result), free(content_copy), NULL);
	result->content = content_copy;
	result->next = NULL;
	return (result);
}

t_list	*list_last(t_list *l)
{
	t_list	*node;

	if (l == NULL)
		return (NULL);
	node = l;
	while (node->next)
		node = node->next;
	return (node);
}

int	list_add_back(t_list **l, char *content)
{
	t_list	*new;

	new = list_new(content);
	if (new == NULL)
		return (list_clear(l), 1);
	if (*l)
		list_last(*l)->next = new;
	else
		*l = new;
	return (0);
}

void	list_clear(t_list **l)
{
	t_list	*next_node;
	t_list	*node;

	if (*l == NULL)
		return ;
	node = *l;
	*l = NULL;
	while (node)
	{
		next_node = node->next;
		free(node->content);
		free(node);
		node = next_node;
	}
}

void	list_print(t_list *l)
{
	while (l)
	{
		ft_putendl_fd(l->content, 1);
		l = l->next;
	}
}
