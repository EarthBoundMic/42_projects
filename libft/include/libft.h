/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:06:53 by mkass             #+#    #+#             */
/*   Updated: 2018/08/31 16:21:29 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <stddef.h>
# include <sys/types.h>
# include <time.h>

/*
**	CHK macros:
**	if beginning, do middle, return end
**	so if a, do b, return c
*/

# define CHK1(a, b) if(1){if(a) return(b);}
# define CHK2(a, b, c) if(1){if(a){ b; return(c);}}
# define CHK3(a, b, c, d) if(1){if(a){ b; c; return(d);}}
# define CHK4(a, b, c, d, e) if(1){if(a){ b; c; d; return(e);}}
# define CHK5(a, b, c, d, e, f) if(1){if(a){ b; c; d; e; return(f);}}

/*
**	CHKV macros:
**	if beginning, do rest
**	in case returns are inappropriate
*/

# define CHKV1(a, b) if(1){if(a) b;}
# define CHKV2(a, b, c) if(1){if(a){ b; c;}}
# define CHKV3(a, b, c, d) if(1){if(a){ b; c; d;}}
# define CHKV4(a, b, c, d, e) if(1){if(a){ b; c; d; e;}}
# define CHKV5(a, b, c, d, e, f) if(1){if(a){ b; c; d; e; f;}}

/*
**	CHKE macro:
**	if a, do b, else do c
**	combine with other CHK macros for flexibility;
**	CHKE in a CHKE could be an else if statement...
**	so can do CHKE(a, CHK2(b, c, d), CHKV3(e, f, g, h)) for example
**	or CHKE(a, b, CHKE(c, d, CHKE(e, f, g)))
**	talk about compounding macros
*/

# define CHKE(a, b, c) if(a){ b;}else{ c;}

/*
**	CHKCE macro:
**	same as CHKE except uses conditional expression
**	also a couple others for max/min
*/

# define CHKCE(a, b, c) (a ? b : c)
# define CHKMIN(a, b) (a < b ? a : b)
# define CHKMAX(a, b) (a > b ? a : b)
# define CHKABS(a) (a < 0 ? -a : a)

/*
**	Same concept here but with while loop
**	if you don't need if condition than just...
**	WHLE(a, CHKV2(1, b, c))
*/

# define WHLE(a, b) if(1){while(a) b;}

/*
**	test macro set so no worry of using if statements so much
**	basically like CHKV without the CHK
*/

# define LST2(a, b) if(1){ a; b;}
# define LST3(a, b, c) if(1){ a; b; c;}
# define LST4(a, b, c, d) if(1){ a; b; c; d;}
# define LST5(a, b, c, d, e) if(1){ a; b; c; d; e;}
# define LST6(a, b, c, d, e, f) if(1){ a; b; c; d; e; f;}

/*
**	macros for checking for null or less than 0...different endings based on
**	function they are inserted into
*/

# define CHKNULLR1(a) if((a) == NULL){return (-1);}
# define CHKNULLR2(a) if((a) == NULL){return (NULL);}
# define CHKNULLE(a) if((a) == NULL){exit(2);}
# define CHKNEGR1(a) if((a) < 0){return (-1);}
# define CHKNEGR2(a) if((a) < 0){return (NULL);}
# define CHKNEGE(a) if((a) < 0){exit(2);}

/*
**  Found that a macro can prevent norminette error for a return
**  **only use for inside non-CHKx macros**
*/

# define RET return

/*
**	Here are common characters for functions
*/

# define NL '\n'
# define NIL '\0'
# define TAB '\t'
# define SPCE ' '

/*
**	Max numbers here so don't have to remember
*/

# define MAX_INT 2147483647
# define MAX_LONG 4294967295

/*
**	Macros primarily used for ft_printf
*/

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

/*
**	Here is buff size...be careful when changing it
*/

# define BUFF_SIZE 32

/*
**	Basic link list
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	ft_printf only
*/

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
**	Other potentially useful structs can go below...
**	might do a hashtable in the future
*/

/*
**	Here's the library:
*/

/*
**	Functions for direct memory:
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
**	Functions for char memory:
*/

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strdup(const char *s1);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);

/*
**	Functions for true/false
*/

int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_realstrcmp(const char *s1, const char *s2);
int					ft_realstrncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

/*
**	Functions for string manipulations
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int str_base);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
void				ft_strbcpy(char *dst, const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_dtoa(double nbr, int prec, int cap);
char				*ft_ldtoa(long double nbr, int prec, int cap);
size_t				ft_strlen(const char *s);
size_t				ft_strlen_diff(const char *s1, const char *s2);
size_t				ft_splitlen(char **s);
int					ft_nlen(int n);
int					ft_llnlen(long long n);
size_t				ft_dlen(double nbr, int prec);
size_t				ft_ldlen(long double nbr, int prec);
size_t				ft_word_count(const char *s, char c);
size_t				ft_word_len(const char *s, char c);
void				ft_word_cpy(char *d, const char *s, char c);
char				*ft_fndfile(char *file);
char				*ft_fndpath(char *file);
int					ft_strswch(char **s1, char **s2);

/*
**	Functions for printing
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, int len);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(char const *s, int len, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbrendl_fd(int n, int fd);

/*
**	Functions for traversing
*/

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_sort(char **buf, int (cmp)(), void *option);
void				ft_revsort(char **buf, int (cmp)(), void *option);

/*
**	Functions for t_list
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	Complex functions
*/

int					get_next_line(const int fd, char **line);

/*
**	Other useful functions
*/

int					ft_exit(void);
int					ft_pow(int n, int x);
long long			ft_llpow(int n, int x);
double				ft_dpow(double n, double x);
long double			ft_ldpow(double n, double x);

/*
**	Functions for practice/fun
*/

char				*ft_strrev(char *str);

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);

/*
**	flags.c
*/

char				*pf_check_first_pfflags(char **format, t_pfflag *f);
char				*pf_check_field_width(char **format, va_list *list,
										t_pfflag *f);
char				*pf_check_precision(char **format, va_list *list,
										t_pfflag *f);
char				*pf_check_length(char **format, t_pfflag *f);

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

void				pf_print_wchar(wchar_t s);
int					pf_check_conv_percent(char **format,
										va_list *list, t_pfflag *f);
int					pf_check_conv_char(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_wchar(char **format,
										va_list *list, t_pfflag *f);

/*
**	conv_strs.c
*/

int					pf_check_conv_wstr(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_str(char **format, va_list *list,
										t_pfflag *f);

/*
**	conv_digits.c
*/

int					pf_check_conv_int(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_long(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_uint(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_void(char **format, va_list *list,
										t_pfflag *f);

/*
**	conv_trans.c
*/

int					pf_parse_uint(uintmax_t n, int base, char *sign,
										t_pfflag *f);
int					pf_check_conv_oct(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_hex(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_bin(char **format, va_list *list,
										t_pfflag *f);

/*
**	conv_double.c
*/

int					pf_check_conv_fdbl(char **format, va_list *list,
										t_pfflag *f);
int					pf_check_conv_ffdbl(char **format, va_list *list,
										t_pfflag *f);

/*
**	conv_others.c
*/

int					pf_check_conv_null(char **format, va_list *list,
										t_pfflag *f);
int					pf_hash_nbr(uintmax_t n, int base, char *sign, t_pfflag *f);
uintmax_t			pf_unsigned_nbr(va_list *list, t_pfflag *f);
int					pf_check_conv_time(char **format, va_list *list,
										t_pfflag *f);

/*
**	conv_helpers.c
*/

void				pf_width_padding(int start, int width, char pad);
void				pf_print_lbase(uintmax_t n, size_t base);
void				pf_print_ubase(uintmax_t n, size_t base);
unsigned int		pf_unlen(uintmax_t n, int base);
unsigned int		pf_nbrlen(uintmax_t n, int base, char *sign, t_pfflag *f);

/*
**	conv_helpers2.c
*/

void				pf_left_width1(int len, t_pfflag *f);
void				pf_left_width2(int len, t_pfflag *f);
void				pf_right_width(int len, t_pfflag *f);
unsigned int		pf_ldnbrlen(long double nbr, t_pfflag *f);
int					pf_wide_strlen_precision(wchar_t *s, int prec, int ret);

/*
**	conv_colors.c && color_check.c
*/

int					pf_color_parse(char **format);
int					pf_check_options(char *options);

#endif
