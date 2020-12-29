#include "ft_printf.h"

void ft_handle_spaces(t_data *data, char *str)
{
	int precision;
	int width;
	int len_str;
	int i;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	(data->len != 0 && data->buff[data->len - 1] == '-') ? (width = width - 1) : (width);
	len_str = (int)ft_strlen(str);
	i = 0;

	//printf("WIDTH = %d\n", width);
	if (width < 0)
	{
		width = -width;
		if (data->len != 0 && data->buff[data->len - 1] == '-')
			width = width - 2;// HEIN ??? POURQUOI ??
		data->minus = 1;
	}
	//printf("PREC = %d\n", precision);
	if (data->minus == 1)
	{
		while (precision-- - len_str > 0)
			data->buff[data->len++] = '0';
		while (*str != '\0')
			data->buff[data->len++] = *str++;
		precision = ft_atoi(data->precision);
		if (precision > len_str)
			while (width-- - precision > 0)
				data->buff[data->len++] = ' ';
		else
			while (width-- - len_str > 0)
				data->buff[data->len++] = ' ';
	}
	else if (data->minus == 0)
	{
		if (data->point == 1)
			while ((len_str < precision && width-- - precision > 0) || (len_str > precision && width-- - len_str > 0))
				data->buff[data->len++] = ' ';
		else
			while (width-- - len_str > 0)
				data->buff[data->len++] = ' ';
		while (precision - len_str++ > 0)
			data->buff[data->len++] = '0';
		while (*str != '\0')
			data->buff[data->len++] = *str++;
	}
}

void ft_convertints(t_data *data, va_list *args)
{
	int n;
	int precision;
	int s_nbr;
	char *nbr;
	n = va_arg(*args, int);
	nbr = ft_itoa(n);
	precision = ft_atoi(data->precision);
	s_nbr = (int)ft_strlen(nbr);

	if (nbr[0] == '-')
	{
		// if (data->precision[0] != '0' && data->twidth[0] != '0')
		// 	data->width = data->width - 2; //test
		data->buff[data->len++] = '-';
		ft_memdel((void *)&nbr);
		nbr = ft_itoa(-n);
	}
	ft_handle_spaces(data, nbr);
}
