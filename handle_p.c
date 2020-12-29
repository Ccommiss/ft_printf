#include "ft_printf.h"

void str_treat(t_data *data, char *str)
{
	int precision;
	int width;
	int i;
	int str_len;

	i = 0;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	str_len = ft_strlen(str);

	if (data->minus == 0)
	{
		if (data->width == 1 && width != 0)
			while (i++ < width - str_len - precision)
				data->buff[data->len++] = ' ';
		i = 0;
		if (data->point == 1)
			while (i++ < precision && *str != '\0')
				data->buff[data->len++] = *str++;
		else
			while (*str != '\0')
				data->buff[data->len++] = *str++;
	}
	else if (data->minus == 1)
	{
		if (data->point == 1)
			while (i++ < precision && *str != '\0')
				data->buff[data->len++] = *str++;
		else
			while (*str != '\0')
				data->buff[data->len++] = *str++;
		if (data->width == 1)
			while ((str_len < precision && width-- - precision > 0) || (str_len > precision && width-- - str_len > 0))
				data->buff[data->len++] = ' ';
	}
}

void ft_converthex(t_data *data, uintptr_t input)
{
	char HEX[17] = "0123456789abcdef";
	int index = 13;
	char output[15];

	output[0] = '0';
	output[1] = 'x';
	output[2] = 'f';
	while (input > 0)
	{
		output[index] = HEX[input & 15];
		input = input / 16;
		index--;
	}
	output[14] = '\0';
	index = 0;
	str_treat(data, output);
}

void ft_convertadd(t_data *data, va_list *args)
{
	char *ptr;
	ptr = va_arg(*args, char *);
	uintptr_t x;
	x = (uintptr_t)ptr;
	ft_converthex(data, x);
}
