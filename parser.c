/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:10:04 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/11 10:32:19 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_getwildcard
**
**  [Usage] : gets width and precision from wildcards.
**			If data->point = 0, width is analyzed.
**			If data->point = 1, therefore a precision has been asked
**			and has to be handled.
**	[Call] : in ft_take_args
**	[Arguments] : t_data structure and args
**	[Return] : always 1
**	[Nb] : none
*/

void	ft_getwildcard(t_data *data, va_list *args)
{
	int		w;
	char	*get_num;

	w = va_arg(*args, int);
	get_num = ft_itoa(w);
	if (data->point == 0)
	{
		if (w < 0 && ft_analyse(data, '-'))
			get_num = ft_itoa(-w);
		data->width = 1;
		ft_bzero((void *)data->twidth, 12);
		if (ft_test(data, ft_strlen(get_num)) == 1)
			ft_strncat(data->twidth, get_num, ft_strlen(get_num));
		return ;
	}
	if (w < 0)
		data->point = 0;
	else if (ft_test(data, ft_strlen(get_num)) == 1)
		ft_strncat(data->precision, get_num, ft_strlen(get_num));
}

void	ft_get_width_zero(t_data *data, char *input, va_list *args, int *i)
{
	int	n;

	n = 0;
	while (input[*i] && ft_table(input[*i]) == 0 && input[*i] != '.')
	{
		if (input[*i] == '-' && data->minus == 0)
			ft_analyse(data, '-');
		if (input[*i] == '0' && data->width == 0)
			ft_analyse(data, '0');
		if (input[*i] == '*' && (ft_analyse(data, '*')))
			ft_getwildcard(data, args);
		if (ft_isdigit(input[*i]) && ft_analyse(data, 'w') && ft_test(data, n))
			data->twidth[n++] = input[*i];
		*i += 1;
	}
}

void	ft_get_precision(t_data *data, char *input, va_list *args, int *i)
{
	int	n;

	n = 0;
	ft_analyse(data, '.');
	*i += 1;
	if (input[*i] == '*' && (ft_analyse(data, '*') == 1))
	{
		ft_getwildcard(data, args);
		*i += 1;
		return ;
	}
	while (input[*i] && ft_table(input[*i]) == 0 && ft_isdigit(input[*i]))
	{
		if (n < 12)
			data->precision[n++] = input[*i];
		else if (n >= 12 && data->precision[0] != '\0' && ft_test(data, n) == 0)
			ft_bzero((void *)data->precision, 12);
		*i += 1;
	}
}

int		ft_take_args(t_data *data, char *input, va_list *args)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (input[i] == '-' || input[i] == '0' || input[i] == '*'
		|| ft_isdigit(input[i]))
		ft_get_width_zero(data, input, args, &i);
	if (input[i] == '.')
		ft_get_precision(data, input, args, &i);
	while (input[i] && ft_table(input[i]) == 0)
		i++;
	if (input[i] == '\0')
		i = 0;
	return (i);
}

void	ft_parser(const char *input, t_data *data, va_list *args)
{
	int	i;

	i = 0;
	ft_reset_flags(data);
	while (input[i] && input[i] != '%')
		write_buff(data, input[i++]);
	if (input[i] == '%')
	{
		i++;
		i = i + ft_take_args(data, (char *)input + i, args);
		if (ft_table(input[i]))
		{
			data->f[ft_table(input[i])](data, args);
			i++;
		}
	}
	if (input[i] != 0 && (input + i))
		ft_parser(input + i, data, args);
	else
		write_buff(data, '\0');
}
