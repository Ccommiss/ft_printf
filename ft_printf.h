/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:16:32 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 18:07:58 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define FCYAN "\x1b[36m"
# define TEST1 "\x1b[37m"
# define NONE "\033[0m"

enum			e_fnames
{

	fint = 1,
	fchar,
	fstr,
	fadd,
	fhex,
	fhex_upcase,
	fpercent,
	funsigned,
	fn
};

typedef void	(*t_func)(void *, ...);

typedef struct	s_data
{
	char	buff[2048];
	int		len;
	char	precision[12];
	char	twidth[12];
	int		point;
	int		zero;
	int		minus;
	int		wildcard;
	int		width;
	t_func	f[10];
	int		ret;
}				t_data;

void			ft_reset_flags(t_data *data);

/*
**  <CONVERSIONS> :  functions related to conversions
*/

void			ft_convertadd(t_data *data, va_list *args);
void			ft_convertchar(t_data *data, va_list *args);
void			ft_convertints(t_data *data, va_list *args);
void			ft_convertunsignedints(t_data *data, va_list *args);
void			ft_convertstr(t_data *data, va_list *args);
void			ft_converthex(t_data *data, va_list *args);
void			ft_converthex_uppercase(t_data *data, va_list *args);
void			ft_convertadd(t_data *data, va_list *args);
void			ft_percent(t_data *data, va_list *args);
void			ft_convert_n(t_data *data, va_list *args);

/*
**  <UTILS> :  architecture of printf
*/

void			ft_parser(const char *input, t_data *data, va_list *args);
void			str_treat(t_data *data, char *str);
void			ft_handle_spaces(t_data *data, char *str);
void			ft_str_left_align(t_data *data, char *str, int prec, int wid);
void			ft_str_right_align(t_data *data, char *str, int prec, int wid);

/*
**  < UTILS.C > :  architecture of printf
*/

void			write_buff(t_data *data, char c);
void			init_printf(t_data *data);
void			ft_reset_flags(t_data *data);
int				ft_table(char type);
int				ft_analyse(t_data *data, char flag);

void			ft_putstr_spec(int len, char *str);
int				ft_printf(const char *input, ...);

#endif
