/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:37:54 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/04 12:46:38 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct t_list	*next;
// }					t_list;

void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
char	ft_tolower(int c);
char	ft_toupper(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **alst, t_list *new);
// int		ft_lstsize(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);
// void	ft_lstadd_back(t_list **alst, t_list *new);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// void	ft_lstclear(t_list **lst, void (*del)(void*));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
