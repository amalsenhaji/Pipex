/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:11 by amsenhaj          #+#    #+#             */
/*   Updated: 2022/03/05 22:18:52 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_lstcount(t_cmd *lst)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_cmd	*ft_lstlast(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_cmd **lst, t_cmd *new)
{
	if (!new)
		return ;
	new->next = lst[0];
	lst[0] = new;
}

void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new)
		return ;
	if (!lst[0])
	{
		lst[0] = new;
		return ;
	}
	tmp = ft_lstlast(lst[0]);
	tmp->next = new;
}

void	free_list(t_cmd *a)
{
	while (a)
	{
		if (a)
		{
			free_tab(a->cmd);
			if (a->path)
				free(a->path);
			free(a);
		}
		a = a->next;
	}
}
