/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:36:13 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/11 18:43:19 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		elem = *alst;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = new;
	}
}
