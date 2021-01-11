/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:18:04 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/11 10:32:47 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_convertchar
**
**  [Usage] : handles char conversion and writes in buffer.
**	[Call] : in ft_parser
**	[Arguments] : structure and lists of arguments passed to ft_printf
**	[Return] : none
**	[Nb] :
**	Precision (.[prec]) is not handled by c conversion, undefined behaviour
*/

void	ft_convertchar(t_data *data, va_list *args)
{
	char	c;
	int		width;
	int		precision;

	c = va_arg(*args, int);
	precision = 0;
	width = ft_atoi(data->twidth);
	if (data->minus == 0)
	{
		if (data->zero == 0)
			while (width-- - 1 > 0)
				write_buff(data, ' ');
		else if (data->zero == 1)
			while (width-- - 1 > 0)
				write_buff(data, '0');
		write_buff(data, c);
	}
	else if (data->minus == 1)
	{
		write_buff(data, c);
		if (data->width == 1)
			while (width-- - 1 > 0)
				write_buff(data, ' ');
	}
}
