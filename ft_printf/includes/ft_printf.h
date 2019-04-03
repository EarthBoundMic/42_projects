/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:50:46 by mkass             #+#    #+#             */
/*   Updated: 2018/07/10 18:18:30 by mkass            ###   ########.fr       */
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
# include "../libft/libft.h"

# define BIN 2
# define OCT 8
# define DEC 10
# define HEX 16

# define CONV '%'
# define HASH '#'
# define ZERO '0'
# define DASH '-'
# define PLUS '+'
# define STAR '*'
# define PRID '.'
# define HALF 'h'
# define LNGG 'l'
# define LNGL 'L'
# define INTM 'j'
# define SIZT 'z'
# define CBGN '{'
# define CEND '}'
# define SPRT ';'

typedef struct		s_pfflag
{
	int				hash : 1;
	int				zero : 1;
	int				dash : 1;
	int				spce : 1;
	int				plus : 1;
	int				wdth : 1;
	int				prec : 1;
	int				hex : 1;
	int				cap : 1;
	unsigned int	fldwidth;
	unsigned int	precision;
	enum {
		none,
		h,
		hh,
		l,
		ll,
		j,
		z,
		lL
	}				length;
}					t_pfflag;

typedef int			(*t_conv_check)(char**, va_list*, t_pfflag*);

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);

/*
**	flags.c
*/

char				*check_first_pfflags(char **format, t_pfflag *f);
char				*check_field_width(char **format, va_list *list,
										t_pfflag *f);
char				*check_precision(char **format, va_list *list, t_pfflag *f);
char				*check_length(char **format, t_pfflag *f);

/*
**	colors.c
*/

int					color_parse(char **format);

/*
**	color_check.c
*/

int					check_options(char *options);

/*
**	conv_init.c
*/

t_conv_check		conv_init(int c);

/*
**	check_conv_*
*/

/*
**	conv_chars.c
*/

void				print_wchar(wchar_t s);
int					check_conv_percent(char **format, va_list *list,
										t_pfflag *f);
int					check_conv_char(char **format, va_list *list, t_pfflag *f);
int					check_conv_wchar(char **format, va_list *list, t_pfflag *f);

/*
**	conv_strs.c
*/

int					check_conv_wstr(char **format, va_list *list, t_pfflag *f);
int					check_conv_str(char **format, va_list *list, t_pfflag *f);

/*
**	conv_digits.c
*/

int					check_conv_int(char **format, va_list *list, t_pfflag *f);
int					check_conv_long(char **format, va_list *list, t_pfflag *f);
int					check_conv_uint(char **format, va_list *list, t_pfflag *f);
int					check_conv_void(char **format, va_list *list, t_pfflag *f);

/*
**	conv_trans.c
*/

int					parse_uint(uintmax_t n, int base, char *sign, t_pfflag *f);
int					check_conv_oct(char **format, va_list *list, t_pfflag *f);
int					check_conv_hex(char **format, va_list *list, t_pfflag *f);
int					check_conv_bin(char **format, va_list *list, t_pfflag *f);

/*
**	conv_others.c
*/

int					check_conv_null(char **format, va_list *list, t_pfflag *f);
int					hash_nbr(uintmax_t n, int base, char *sign, t_pfflag *f);
uintmax_t			unsigned_nbr(va_list *list, t_pfflag *f);
int					check_conv_time(char **format, va_list *list, t_pfflag *f);

/*
**	conv_double.c
*/

int					check_conv_fdbl(char **format, va_list *list, t_pfflag *f);
int					check_conv_ffdbl(char **format, va_list *list, t_pfflag *f);

/*
**	conv_helpers.c
*/

void				width_padding(int start, int width, char pad);
void				print_lbase(uintmax_t n, size_t base);
void				print_ubase(uintmax_t n, size_t base);
unsigned int		unlen(uintmax_t n, int base);
unsigned int		nbrlen(uintmax_t n, int base, char *sign, t_pfflag *f);

/*
**	conv_helpers2.c
*/

void				left_width1(int len, t_pfflag *f);
void				left_width2(int len, t_pfflag *f);
void				right_width(int len, t_pfflag *f);
unsigned int		ldnbrlen(long double nbr, t_pfflag *f);
int					wide_strlen_precision(wchar_t *s, int prec, int ret);

#endif
