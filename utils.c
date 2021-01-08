/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:08:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 18:07:36 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	<UTILS.C> : ft_analyse, ft_table, ft_init, ft_resetflags
*/

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
**	[Arguments] : type of conversion
**	[Return] : number of the function in the functions tab t_func f[10], or 0
**	if none have been found.
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
