/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:47:02 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/08 16:29:53 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_converthex / ft_converthex_uppercase
**
**  [Usage] : handles %x and %X arguments (hexadecimal)
**	[Call] : in ft_parser
**	[Arguments] : pointer on t_data structure and list of args
**	[Return] : none
**	[Nb] : none
*/

void	ft_converthex(t_data *data, va_list *args)
{
	unsigned int	uint;
	char			*output;

	uint = va_arg(*args, unsigned int);
	output = ft_itoa_base(uint, 16);
	if (!output)
	{
		data->ret = -1;
		return ;
	}
	ft_handle_spaces(data, output);
	free(output);
}

void	ft_converthex_uppercase(t_data *data, va_list *args)
{
	unsigned int	uint;
	char			*output;

	uint = va_arg(*args, unsigned int);
	output = ft_itoa_base(uint, 16);
	if (!output)
	{
		data->ret = -1;
		return ;
	}
	output = ft_strtoupper(output);
	ft_handle_spaces(data, output);
	free(output);
}
