/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:20:21 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/08 15:25:52 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_convert_n
**
**  [Usage] : handles %n argument, which stores the number of characters
**		printed until there to parameter of printf – an int address.
**	[Call] : in ft_parser
**	[Arguments] : t_data structure and list of args
**	[Return] : none
**	[Nb] : none
*/

void	ft_convert_n(t_data *data, va_list *args)
{
	int *add;

	add = va_arg(*args, int *);
	*add = data->len + data->ret;
}
