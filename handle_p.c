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
				write_buff(data, ' ');
		i = 0;
		if (data->point == 1)
			while (i++ < precision && *str != '\0')
				write_buff(data, *str++);
		else
			while (*str != '\0')
				write_buff(data, *str++);
	}
	else if (data->minus == 1)
	{
		if (data->point == 1)
			while (i++ < precision && *str != '\0')
				write_buff(data, *str++);
		else
			while (*str != '\0')
				write_buff(data, *str++);
		if (data->width == 1)
			while ((str_len < precision && width-- - precision > 0) || (str_len > precision && width-- - str_len > 0))
				write_buff(data, ' ');
	}
}

static void ft_converthexp(t_data *data, uintptr_t input)
{
	char HEX[17] = "0123456789abcdef";
	int index = 13;
	char output[15];

	ft_bzero((void *)output, 15);
	output[0] = '0';
	output[1] = 'x';
	if (input != 0)
		output[2] = 'f';
	else
		output[2] = '0';
	while (input > 0)
	{
		output[index] = HEX[input & 15];
		input = input / 16;
		index--;
	}
	//output[14] = '\0';
	index = 0;
	str_treat(data, output);
}

void ft_convertadd(t_data *data, va_list *args)
{
	char *ptr;
	uintptr_t x;

	ptr = va_arg(*args, char *);
	if (ptr == NULL)
		x = 0;
	else
		x = (uintptr_t)ptr;
	ft_converthexp(data, x);
}
