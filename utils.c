/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:08:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/11 10:24:36 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	<UTILS.C> : ft_test, ft_analyse, ft_table, ft_init, ft_resetflags
*/

/*
**	ft_test
**
**  [Usage] : checks if specified argument is too big to be displayed.
**			If so, ret is set to -1 and nothing is displayed on
**			the end.
**	[Call] : multiple times in parser.c,
**	[Arguments] : t_data structure and number to be checked
**	[Return] : 0 if argument is > 12 (e.g. max length of specified characters)
**			1 if all good.
**	[Nb] : none
*/

int		ft_test(t_data *data, int max)
{
	if (max >= 12)
	{
		data->ret = -1;
		return (0);
	}
	return (1);
}

/*
**	ft_analyse
**
**  [Usage] : turning 1 to conversions specificators in t_data.
**	[Call] :
**		In ft_take_args when the specificator is encountered.
**	[Arguments] : t_data structure and specificator encountered
**	[Return] : always 1
**	[Nb] : none
*/

int		ft_analyse(t_data *data, char flag)
{
	if (flag == '0' && data->minus == 0)
		data->zero = 1;
	else if (flag == '*')
		data->wildcard = 1;
	else if (flag == '-')
	{
		data->minus = 1;
		data->zero = 0;
	}
	else if (flag == '.')
		data->point = 1;
	else if (flag == 'w')
		data->width = 1;
	return (1);
}

/*
**	ft_table
**
**  [Usage] : determines type of conversion to process.
**	[Call] :
**		In ft_take_args to verify char is not yet a conversion.
**		In ft_parser to call the correct function.
**	[Arguments] : a character corresponding or not to a conversion
**	[Return] : number of the function in the functions tab t_func f[10], or 0
**		if none have been found.
**	[Nb] : none
*/

int		ft_table(char type)
{
	if (type == 'd' || type == 'i')
		return (fint);
	if (type == 'u')
		return (funsigned);
	if (type == 's')
		return (fstr);
	if (type == 'c')
		return (fchar);
	if (type == 'p')
		return (fadd);
	if (type == 'x')
		return (fhex);
	if (type == 'X')
		return (fhex_upcase);
	if (type == '%')
		return (fpercent);
	if (type == 'n')
		return (fn);
	return (0);
}

/*
**	ft_reset_flags
**
**  [Usage] : reset all flags – which work as booleans – to zero
**	[Call] : at each new call of ft_parser.
**	[Arguments] : pointer on t_data structure
**	[Return] : none
**	[Nb] : none
*/

void	ft_reset_flags(t_data *data)
{
	data->zero = 0;
	data->minus = 0;
	data->wildcard = 0;
	data->point = 0;
	data->width = 0;
	ft_bzero((void *)data->precision, 12);
	ft_bzero((void *)data->twidth, 12);
}

/*
**	ft_strtreat
**
**  [Usage] : handles %p and displays address of the pointer
**	[Call] : in ft_parser
**	[Arguments] : pointer on t_data structure and list of args
**	[Return] : none
**	[Nb] : none
*/

void	str_treat(t_data *data, char *str)
{
	int	precision;
	int	width;
	int	i;
	int	str_len;

	i = 0;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	str_len = ft_strlen(str);
	if (data->minus == 0)
		ft_str_right_align(data, str, precision, width);
	else
		ft_str_left_align(data, str, precision, width);
}
