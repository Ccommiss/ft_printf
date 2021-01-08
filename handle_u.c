/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:17:29 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/08 16:28:34 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_convertunsignedints
**
**  [Usage] : handles %u (unsigned ints : [0 ; 4 294 967 295])
**	[Call] : in ft_parser
**	[Arguments] : pointer on t_data structure and list of args
**	[Return] : none
**	[Nb] : none
*/

void	ft_convertunsignedints(t_data *data, va_list *args)
{
	unsigned int	n;
	char			*nbr;

	n = va_arg(*args, unsigned int);
	if (!n)
		n = 0;
	nbr = ft_utoa(n);
	ft_handle_spaces(data, nbr);
}
