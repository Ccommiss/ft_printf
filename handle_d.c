/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:14:36 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 17:15:42 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** si pas de precision, le padding = des 0 ou des espaces selon./
** si precision, alors pendant padding - precision, on remplit de blancs
** padding = les espaces ou les 0 de largeurs
*/

void	ft_right_align(t_data *data, int padding, int precision, char *str)
{
	if (data->point == 0)
	{
		if (data->zero == 0)
			while (padding-- > 0)
				write_buff(data, ' ');
		else if (data->zero == 1 && *str == '-')
			write_buff(data, *str++);
		if (data->zero == 1)
			while (padding-- > 0)
				write_buff(data, '0');
	}
	else
	{
		padding = padding - precision;
		while (padding-- > 0)
			write_buff(data, ' ');
		if (*str == '-')
			write_buff(data, *str++);
		while (precision-- > 0)
			write_buff(data, '0');
	}
	while (*str)
		write_buff(data, *str++);
}

/*
** left-align;
** option 0 ignoree
*/

void	ft_left_align(t_data *data, int padding, int precision, char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		write_buff(data, *str++);
	if (data->point == 1)
		while (i++ < precision)
			write_buff(data, '0');
	while (*str)
		write_buff(data, *str++);
	if (data->point == 1)
		padding = padding - precision;
	i = 0;
	while (i++ < padding)
		write_buff(data, ' ');
}

void	ft_handles_zero(t_data *data, char *str, int precision, int padding)
{
	if (precision + 1 > 0)
		str[0] = '0';
	else if (data->width == 1 && padding >= 0)
		str[0] = ' ';
	else
		str[0] = '\0';
}

void	ft_handle_spaces(t_data *data, char *str)
{
	int	precision;
	int	padding;
	int	len_str;
	int	i;

	len_str = (int)ft_strlen(str);
	precision = ft_atoi(data->precision) - len_str;
	padding = ft_atoi(data->twidth) - len_str;
	if (data->point == 1 && *str == '-')
		precision = precision + 1;
	if (len_str == 1 && str[0] == '0' && data->point == 1)
		ft_handles_zero(data, str, precision, padding);
	if (padding < 0)
		padding = 0;
	if (precision < 0)
		precision = 0;
	i = 0;
	if (data->minus == 0)
		ft_right_align(data, padding, precision, str);
	if (data->minus == 1)
		ft_left_align(data, padding, precision, str);
}

void	ft_convertints(t_data *data, va_list *args)
{
	int		n;
	int		precision;
	int		s_nbr;
	char	*nbr;

	n = va_arg(*args, int);
	if (!n)
		n = 0;
	nbr = ft_itoa(n);
	precision = ft_atoi(data->precision);
	s_nbr = (int)ft_strlen(nbr);
	ft_handle_spaces(data, nbr);
}
