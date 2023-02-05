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
# include <string.h>
# include <ctype.h>
# include "get_next_line.h"

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

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strdup(const char *s1);

char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s1, const char *set);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstfirst(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));

#endif
