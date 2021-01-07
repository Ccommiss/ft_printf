/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:34:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 17:15:20 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_right_align(t_data *data, char *str, int precision, int width)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (data->width == 1 && width != 0)
	{
		if (data->point == 1 && (precision < str_len))
			while (i++ < width - precision)
				write_buff(data, ' ');
		else
			while (i++ < width - str_len)
				write_buff(data, ' ');
	}
	i = 0;
	if (data->point == 1)
		while (i++ < precision && *str != '\0')
			write_buff(data, *str++);
	else
		while (*str != '\0')
			write_buff(data, *str++);
}

void	ft_str_left_align(t_data *data, char *str, int precision, int width)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (data->point == 1)
		while (i++ < precision && *str != '\0')
			write_buff(data, *str++);
	else
		while (*str != '\0')
			write_buff(data, *str++);
	i = 0;
	if (data->width == 1 && width != 0)
	{
		if (data->point == 1 && (precision < str_len))
			while (i++ < width - precision)
				write_buff(data, ' ');
		else
			while (i++ < width - str_len)
				write_buff(data, ' ');
	}
}

void	ft_convertstr(t_data *data, va_list *args)
{
	char	*str;
	int		precision;
	int		width;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	width = ft_atoi(data->twidth);
	precision = ft_atoi(data->precision);
	if (data->minus == 0)
		ft_str_right_align(data, str, precision, width);
	else
		ft_str_left_align(data, str, precision, width);
}

void	ft_percent(t_data *data, va_list *args)
{
	(void)args;
	ft_handle_spaces(data, "%");
}
