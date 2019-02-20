/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_attr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:59:13 by mkass             #+#    #+#             */
/*   Updated: 2018/10/06 14:59:29 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ext_perm(const char *file, char *buf)
{
	acl_t		acl_chk;
	acl_entry_t	useless;
	int			xattr_chk;
	int			chk;

	acl_chk = acl_get_link_np(file, ACL_TYPE_EXTENDED);
	chk = acl_get_entry(acl_chk, ACL_FIRST_ENTRY, &useless);
	if (acl_chk && chk < 0)
	{
		acl_free(acl_chk);
		acl_chk = NULL;
	}
	xattr_chk = listxattr(file, NULL, 0, 1);
	if (xattr_chk > 0)
		buf[10] = '@';
	else if (acl_chk)
		buf[10] = '+';
	acl_free(acl_chk);
}
