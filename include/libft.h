/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:49:32 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 18:36:43 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_list
{
	struct s_list	*previous;
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_atoi(const char *str);

void			*ft_calloc(size_t nitems, size_t size);
char			*ft_strdup(const char *s1);

char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoin_arr(char **arr, char sep);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstfirst(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

t_btree			*ft_btree_create_node(void *item);
void			ft_btree_apply_prefix(t_btree *root, void (*f)(void *));
void			ft_btree_apply_infix(t_btree *root, void (*f)(void *));
void			ft_btree_apply_suffix(t_btree *root, void (*f)(void *));

void			*ft_ternary(int test, void *a, void *b);
int				ft_ternaryi(int test, int a, int b);
long			ft_ternaryl(int test, long a, long b);
unsigned long	ft_ternaryul(int test, unsigned long a, unsigned long b);
double			ft_ternaryd(int test, double a, double b);

void			*ft_assign(void **var, void *valeur);

#endif
