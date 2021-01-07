#include "ft_printf.h"

void ft_convertstr(t_data *data, va_list *args)
{
	char *str;
	int precision;
	int width;
	int i;
	int str_len;

	i = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	width = ft_atoi(data->twidth);
	precision = ft_atoi(data->precision);
	str_len = ft_strlen(str);

	if (data->minus == 0)
	{
		if (data->width == 1 && width != 0)
		{
			if (data->point == 1 && (precision < str_len))
				while (i++ < width - precision)
					write_buff(data, ' ');
			else // si la chaine est plus petite que la precision, on ne s'occupe pas de la precision
				while (i++ < width - str_len)
					write_buff(data, ' ');
		}
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
		i = 0;
		if (data->width == 1 && width != 0)
		{
			if (data->point == 1 && (precision < str_len))
				while (i++ < width - precision)
					write_buff(data, ' ');
			else // si la chaine est plus petite que la precision, on ne s'occupe pas de la precision
				while (i++ < width - str_len)
					write_buff(data, ' ');
		}

	}
}

void ft_percent(t_data *data, va_list *args)
{
	(void)args;
	ft_handle_spaces(data, "%");
}
