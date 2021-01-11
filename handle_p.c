/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:32:31 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/11 10:33:01 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_convertadd
**
**  [Usage] : handles %p and displays address of the pointer
**	[Call] : in ft_parser
**	[Arguments] : pointer on t_data structure and list of args
**	[Return] : none
**	[Nb] : none
*/

void	ft_convertadd(t_data *data, va_list *args)
{
	void		*ptr;
	uintptr_t	x;

	ptr = va_arg(*args, void *);
	x = (uintptr_t)ptr;
	ft_converthexp(data, x);
}

/*
**	ft_address_right, ft_address_left
**
**  [Usage] : handles %p when precision is specified : writes 0 after the 0x
**	[Call] : in ft_handle_spaces_p via ft_converthexp
**	[Arguments] : pointer on t_data structure, string containing the address,
**		precision asked and padding.
**	[Return] : none
**	[Nb] : none
*/

void	ft_address_right(t_data *data, char *str, int precision, int padding)
{
	int i;

	i = 0;
	while (i++ < 2)
		write_buff(data, *str++);
	while (precision-- > 0)
		write_buff(data, '0');
	while (*str)
		write_buff(data, *str++);
	if (data->point == 1)
		padding = padding - precision;
	while (padding-- > 0)
		write_buff(data, ' ');
}

void	ft_address_left(t_data *data, char *str, int precision, int padding)
{
	int i;

	i = 0;
	padding = padding - precision;
	while (padding-- > 0)
		write_buff(data, ' ');
	while (i++ < 2)
		write_buff(data, *str++);
	while (precision-- > 0)
		write_buff(data, '0');
	while (*str)
		write_buff(data, *str++);
}

void	ft_handle_spaces_p(t_data *data, char *str)
{
	int len_str;
	int precision;
	int padding;
	int i;

	i = 0;
	len_str = (int)ft_strlen(str);
	precision = ft_atoi(data->precision) - len_str + 2;
	if (precision < 0)
		precision = 0;
	padding = ft_atoi(data->twidth) - len_str;
	if (data->minus == 0)
		ft_address_left(data, str, precision, padding);
	else
		ft_address_right(data, str, precision, padding);
}

void	ft_converthexp(t_data *data, uintptr_t input)
{
	char	*output;
	char	*tmp;

	tmp = ft_itoa_base(input, 16);
	if (tmp[0] == '0' && ft_strlen(tmp) == 1 && data->point == 1
		&& ft_atoi(data->precision) == 0)
	{
		output = strdup("0x");
		data->point = 0;
	}
	else
		output = ft_strjoin("0x", tmp);
	if (!output)
	{
		free(tmp);
		data->ret = -1;
		return ;
	}
	if (ft_atoi(data->precision) != 0)
		ft_handle_spaces_p(data, output);
	else
		str_treat(data, output);
	free(tmp);
	free(output);
}
