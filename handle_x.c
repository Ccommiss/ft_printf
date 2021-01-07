#include "ft_printf.h"

void ft_converthex(t_data *data, va_list *args)
{
	unsigned int uint;
	char *output;

	uint = va_arg(*args, unsigned int);
	output = ft_itoa_base(uint, 16);
	ft_handle_spaces(data, output);
}

void ft_converthexU(t_data *data, va_list *args)
{
	unsigned int uint;
	char *output;
	int i;

	uint = va_arg(*args, unsigned int);
	output = ft_itoa_base(uint, 16);
	i = 0;

	output = ft_strtoupper(output);
	ft_handle_spaces(data, output);
}
