/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:50:46 by mkass             #+#    #+#             */
/*   Updated: 2018/08/07 16:34:30 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <stddef.h>
# include <sys/types.h>
# include <time.h>
# include "../../libft.h"

# define BIN 2
# define OCT 8
# define DEC 10
# define HEX 16

typedef struct		s_flag
{
	int				hash : 1;
	int				zero : 1;
	int				dash : 1;
	int				spce : 1;
	int				plus : 1;
	int				wdth : 1;
	int				prec : 1;
	int				hex : 1;
	unsigned int	fldwidth;
	unsigned int	precision;
	enum {
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				length;
}					t_flag;

typedef int			(*t_conv_check)(char**, va_list*, t_flag*);

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);

/*
**	flags.c
*/

char				*pf_check_first_flags(char **format, t_flag *f);
char				*check_field_width(char **format, va_list *list, t_flag *f);
char				*check_precision(char **format, va_list *list, t_flag *f);
char				*pf_check_length(char **format, t_flag *f);

/*
**	conv_init.c
*/

t_conv_check		pf_conv_init(int c);

/*
**	pf_check_conv_*
*/

/*
**	conv_chars.c
*/

void				print_wchar(wchar_t s);
int					pf_check_conv_percent(char **format,
										va_list *list, t_flag *f);
int					pf_check_conv_char(char **format, va_list *list, t_flag *f);
int					pf_check_conv_wchar(char **format,
										va_list *list, t_flag *f);

/*
**	conv_strs.c
*/

int					pf_check_conv_wstr(char **format, va_list *list, t_flag *f);
int					pf_check_conv_str(char **format, va_list *list, t_flag *f);

/*
**	conv_digits.c
*/

int					pf_check_conv_int(char **format, va_list *list, t_flag *f);
int					pf_check_conv_long(char **format, va_list *list, t_flag *f);
int					pf_check_conv_uint(char **format, va_list *list, t_flag *f);
int					pf_check_conv_void(char **format, va_list *list, t_flag *f);

/*
**	conv_trans.c
*/

int					pf_parse_uint(uintmax_t n, int base, char *sign, t_flag *f);
int					pf_check_conv_oct(char **format, va_list *list, t_flag *f);
int					pf_check_conv_hex(char **format, va_list *list, t_flag *f);
int					pf_check_conv_bin(char **format, va_list *list, t_flag *f);

/*
**	conv_others.c
*/

int					pf_check_conv_null(char **format, va_list *list, t_flag *f);
int					pf_hash_nbr(uintmax_t n, int base, char *sign, t_flag *f);
uintmax_t			pf_unsigned_nbr(va_list *list, t_flag *f);
int					pf_check_conv_time(char **format, va_list *list, t_flag *f);

/*
**	conv_helpers.c
*/

void				width_padding(int start, int width, char pad);
void				print_lbase(uintmax_t n, size_t base);
void				print_ubase(uintmax_t n, size_t base);
unsigned int		unlen(uintmax_t n, int base);
unsigned int		pf_nbrlen(uintmax_t n, int base, char *sign, t_flag *f);

#endif
