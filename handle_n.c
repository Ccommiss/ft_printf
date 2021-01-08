#include "ft_printf.h"

void	ft_convert_n(t_data *data, va_list *args)
{
	int *add;
	add = va_arg(*args, int *);
	*add = data->len + data->ret;
}


