/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:08:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/08 15:20:34 by ccommiss         ###   ########.fr       */
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
**	ft_init_printf
**
**  [Usage] : reinitialize functions tab in t_data
**	[Call] : at the very beginning of ft_printf
**	[Arguments] : pointer on t_data structure
**	[Return] : none
**	[Nb] : none
*/

void	init_printf(t_data *data)
{
	data->len = 0;
	data->f[fint] = (t_func)(&ft_convertints);
	data->f[fstr] = (t_func)(&ft_convertstr);
	data->f[fchar] = (t_func)(&ft_convertchar);
	data->f[fadd] = (t_func)(&ft_convertadd);
	data->f[fhex] = (t_func)(&ft_converthex);
	data->f[fhex_upcase] = (t_func)(&ft_converthex_uppercase);
	data->f[fpercent] = (t_func)(&ft_percent);
	data->f[funsigned] = (t_func)(&ft_convertunsignedints);
	data->f[fn] = (t_func)(&ft_convert_n);
	data->ret = 0;
	ft_bzero((void *)data->buff, 2048);
}
