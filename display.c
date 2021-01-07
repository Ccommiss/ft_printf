/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:12:21 by ccommiss          #+#    #+#             */
/*   Updated: 2021/01/07 16:12:26 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_spec(int len, char *str)
{
	int	i;

	i = 0;
	if (!str)
		ft_putchar(0);
	while (i < len && len <= 2048)
		ft_putchar(str[i++]);
}

void	write_buff(t_data *data, char c)
{
	data->buff[data->len++] = c;
	if (data->len == 2048)
	{
		ft_putstr_spec(2048, data->buff);
		ft_bzero((void *)data->buff, 2048);
		data->ret = data->ret + data->len;
		data->len = 0;
	}
}
