/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:47:02 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 16:47:38 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converthex(t_data *data, va_list *args)
{
	unsigned int	uint;
	char			*output;

	uint = va_arg(*args, unsigned int);
	output = ft_itoa_base(uint, 16);
	ft_handle_spaces(data, output);
}

void	ft_converthex_uppercase(t_data *data, va_list *args)
{
	unsigned int	uint;
	char			*output;

	uint = va_arg(*args, unsigned int);
	output = ft_itoa_base(uint, 16);
	output = ft_strtoupper(output);
	ft_handle_spaces(data, output);
}
