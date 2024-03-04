/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:15:22 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/10 13:46:52 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_obj;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	n_list = NULL;
	while (lst)
	{
		n_obj = ft_lstnew(f(lst->content));
		if (!n_obj)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, n_obj);
		lst = lst->next;
	}
	return (n_list);
}
