/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:09:30 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/11 10:25:00 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*
**	ft_printf
**
**  [Usage] : The printf() function writes output to stdout, the standard
**		output stream, under the control of a format string that specifies
**		how subsequent arguments are converted for output.
**	[Arguments] : the user's input
**	[Return] : the number of characters printed (not including the trailing
**			`\0' used to end output to strings
**	[Nb] : none
*/

int		ft_printf(const char *input, ...)
{
	t_data	data;
	va_list	args;

	init_printf(&data);
	va_start(args, input);
	ft_parser(input, &data, &args);
	va_end(args);
	if (data.ret != -1)
		data.ret = data.ret + data.len - 1;
	if (data.ret != -1)
		ft_putstr_spec(data.len - 1, data.buff);
	return (data.ret);
}
