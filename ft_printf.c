/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:09:30 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 15:09:33 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	char	*var;
	t_data	data;
	va_list	args;

	init_printf(&data);
	va_start(args, input);
	ft_parser(input, &data, &args);
	var = va_arg(args, char *);
	va_end(args);
	data.ret = data.ret + data.len - 1;
	ft_putstr_spec(data.len - 1, data.buff);
	return (data.ret);
}
