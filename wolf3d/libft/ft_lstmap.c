/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:02:24 by mkass             #+#    #+#             */
/*   Updated: 2018/02/27 14:44:02 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(new))))
		return (NULL);
	new = f(lst);
	if (lst->next)
	{
		new->next = ft_lstmap(lst->next, f);
		if (new->next == NULL)
		{
			free(new);
			return (NULL);
		}
	}
	else
		new->next = NULL;
	return (new);
}
