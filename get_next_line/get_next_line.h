/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:40:35 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/10 16:51:47 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_list
{
	char			*str_buf;
	struct t_list	*next;
}					t_list;

int		is_new_line_found(t_list *list);
t_list	*find_last_element(t_list *list);
char	*get_new_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_till_newline(t_list *list);
void	adjust_list(t_list **list);
char	*get_next_line(int fd);
void	final_clean(t_list **list, t_list *clean_node, char *buf);
void	create_list(t_list **list, int fd);
#endif
