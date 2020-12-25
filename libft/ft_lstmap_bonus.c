/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:35:58 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/25 12:16:22 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_f(void *d)
{
	return (d);
}

static void	ft_del(void *d)
{
	(void)d;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_start;

	if (!f)
		f = &ft_f;
	if (!del)
		del = &ft_del;
	if (!lst)
		return (NULL);
	if (!ft_assign((void **)&result, ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	result_start = result;
	while (lst)
	{
		if (!ft_assign((void **)&result->next, ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result_start, del);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (result_start);
}
