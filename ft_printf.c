/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:09:30 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/08 15:25:04 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printf(const char *input, ...)
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
