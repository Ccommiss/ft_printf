/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:17:29 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 16:19:22 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertunsignedints(t_data *data, va_list *args)
{
	unsigned int	n;
	int				precision;
	int				s_nbr;
	char			*nbr;

	n = va_arg(*args, unsigned int);
	if (!n)
		n = 0;
	nbr = ft_utoa(n);
	precision = ft_atoi(data->precision);
	s_nbr = (int)ft_strlen(nbr);
	ft_handle_spaces(data, nbr);
}
