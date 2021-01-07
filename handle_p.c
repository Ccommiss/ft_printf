/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:32:31 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 16:45:23 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_treat(t_data *data, char *str)
{
	int	precision;
	int	width;
	int	i;
	int	str_len;

	i = 0;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	str_len = ft_strlen(str);
	if (data->minus == 0)
		ft_str_right_align(data, str, precision, width);
	else
		ft_str_left_align(data, str, precision, width);
}

static void	ft_converthexp(t_data *data, uintptr_t input)
{
	char	*output;
	char	*tmp;

	output = NULL;
	tmp = NULL;
	tmp = ft_itoa_base(input, 16);
	output = ft_strjoin("0x", tmp);
	if (!output)
	{
		free(tmp);
		return ;
	}
	str_treat(data, output);
	free(tmp);
	free(output);
}

void		ft_convertadd(t_data *data, va_list *args)
{
	void		*ptr;
	uintptr_t	x;

	ptr = va_arg(*args, void *);
	x = (uintptr_t)ptr;
	ft_converthexp(data, x);
}
