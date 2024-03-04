/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:44:07 by iverniho          #+#    #+#             */
/*   Updated: 2023/12/11 19:02:03 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list			*temp;
	int				i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
