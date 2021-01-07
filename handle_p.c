#include "ft_printf.h"
 // A SUPP
#include <stdarg.h>
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
	char *output = NULL;
	char *prefix = "0x";
	output = ft_itoa_base(input, 16);
	output = ft_strjoin(prefix, output); // melloc
	str_treat(data, output);
}

void ft_convertadd(t_data *data, va_list *args)
{
	void *ptr;
	uintptr_t x;

	//ptr = va_arg(*args, char *);
	ptr = va_arg(*args, void *);
//	printf("%p\n", ptr);
//	if (ptr == NULL)
//	{
//		printf("VOID * = NULL\n");
//		x = 0;
//	}
//	else
		x = (uintptr_t)ptr;
	ft_converthexp(data, x);
}
