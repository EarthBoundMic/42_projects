/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:48:23 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 14:50:41 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			pf_width_padding(int start, int width, char pad)
{
	while (start < width)
	{
		ft_putchar(pad);
		start++;
	}
}

void			pf_print_lbase(uintmax_t n, size_t base)
{
	char		*s;

	s = "0123456789abcdef";
	if (n >= base)
	{
		pf_print_lbase(n / base, base);
		pf_print_lbase(n % base, base);
	}
	else
		ft_putchar(s[n]);
}

void			pf_print_ubase(uintmax_t n, size_t base)
{
	char		*s;

	s = "0123456789ABCDEF";
	if (n >= base)
	{
		pf_print_ubase(n / base, base);
		pf_print_ubase(n % base, base);
	}
	else
		ft_putchar(s[n]);
}

unsigned int	pf_unlen(uintmax_t n, int base)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

unsigned int	pf_nbrlen(uintmax_t n, int base, char *sign, t_pfflag *f)
{
	unsigned int	nlen;
	unsigned int	tlen;

	nlen = pf_unlen(n, base);
	if (!n && f->prec && !f->precision)
		tlen = 0;
	else if (f->prec)
		tlen = CHKMAX(nlen, f->precision);
	else
		tlen = nlen;
	if (f->hash && sign != NULL && n)
		tlen += ft_strlen(sign);
	return (tlen);
}
