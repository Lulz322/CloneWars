/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:26:51 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:26:57 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HEADER_H
# define PF_HEADER_H

# define ULLI unsigned long long int
# define LLI long long int
# define IS_NUM (s[i] > '0' && s[i] <= '9')
# define STAR_PR (IS_NUM && i > 1 && s[i - 1] == '*' && s[i - 2] == '.')
# define IS_MINUS (i > 0 && s[i] == '-' && s[i - 1] != '.')
# define DELIMA (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == '\0')
# define DELIMB (s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == '%')
# define DELIMC (s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'f')
# define ZPA (i > 0 && s[i - 1] == '.')
# define ZPB (i > 1 && s[i - 1] == '0' && s[i - 2] == '.')
# define ZPC (i > 1 && (s[i - 1] == 'L' || s[i - 1] == 'l') && s[i - 2] == '.')
# define ZPD (i > 2 && s[i - 1] == 'L' && s[i - 2] == '0' && s[i - 3] == '.')
# define ZPE (i > 2 && s[i - 1] == 'l' && s[i - 2] == '0' && s[i - 3] == '.')
# define TRASH ((s[i] > 64 && s[i] < 88) || s[i] == 'Y' || s[i] == 'Z')
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define GREEN   "\x1b[32m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE    "\x1b[37m"
# define EOC "\x1b[0m"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	int			ms;
	int			ps;
	int			sp;
	int			zr;
	int			hs;
	int			dt;
	int			pr;
	int			zp;
	int			tr;
	int			ul;
	int			hh;
	int			ll;
	int			wd;
	int			id;
}				t_data;

t_data			g_s;
void			(*g_fps[121]) (va_list ap);
int				g_i;

int				ft_printf(const char *format, ...);
void			pf_read_format(const char *str, va_list ap);
void			pf_d_i_identifiers(va_list ap);
void			pf_o_u_x_identifiers(va_list ap);
void			pf_f_identifier(va_list ap);
void			pf_c_identifier(va_list ap);
void			pf_s_identifier(va_list ap);
void			pf_p_identifier(va_list ap);
int				pf_count_digits_base(ULLI num);
void			pf_putnbr_base_low(ULLI num, ULLI base);
void			pf_putnbr_base_up(ULLI num, ULLI base);
LLI				pf_get_value_sgn(va_list ap);
ULLI			pf_get_value_uns(va_list ap);
ULLI			pf_pow(ULLI num, int times);
size_t			pf_strlen(const char *s);
int				pf_count_digits_sgn(long long int n);
int				pf_count_digits_uns(unsigned long long int n);
int				pf_atoi(const char *s);
void			pf_putchar(char c);
void			pf_putstr(char const *s);
void			pf_putnstr(const char *s, int len);
void			pf_putnbr_uns(unsigned long long int num);
void			pf_putnbr_sgn(long long int n);
void			pf_mod_identifier(va_list ap);
void			pf_color_switch(const char *s, va_list ap);
void			pf_print_trash(const char *s);

#endif
