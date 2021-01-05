#include "ft_printf.h"



void ft_handle_spaces(t_data *data, char *str)
{
	int precision;
	int width;
	int len_str;
	int i;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	if (str[0] == '-' && data->point == 1)
		precision = precision + 1;



	//if (str[0] == '-')
		//width = width - 1;
//	(data->len != 0 && data->buff[data->len - 1] == '-') ? (width = width - 1) : (width);
	len_str = (int)ft_strlen(str);
	i = 0;
	//exception si precison = 0 et nb = 0 : ca ne renvoie rien
	if (len_str == 1 && str[0] == '0' && data->point == 1 && precision == 0)
	{
		str[0] = '\0';
		if (width != 0)
			str[0] = ' ';
	}
	if (width < 0)
	{
		width = -width;
		if (data->len != 0 && str[0] == '-')
			width = width - 2;// HEIN ??? POURQUOI ??
		data->minus = 1;
	}
	if (data->minus == 1)
	{
		if ((data->zero == 1 || data->point == 1) && str[0] == '-' && str++)//test pour mettre le - avant les 0
			write_buff(data, '-');
		while (precision-- - len_str > 0)
			write_buff(data, '0');
		while (*str != '\0')
			write_buff(data, *str++);
		precision = ft_atoi(data->precision);
		if (precision > len_str)
			while (width-- - precision > 0)
				write_buff(data, ' ');
		else
			while (width-- - len_str > 0)
				write_buff(data, ' ');
	}
	else if (data->minus == 0)
	{
		if (data->point == 1)
			while ((len_str <= precision && width-- - precision > 0) || (len_str > precision && width-- - len_str > 0))
				write_buff(data, ' ');
		else
			while (width-- - len_str > 0)
				write_buff(data, ' ');
		if ((data->zero == 1 || data->point == 1) && str[0] == '-' && str++)//test pour mettre le - ava nt les 0
			write_buff(data, '-');
		while (precision - len_str++ > 0) //????
			write_buff(data, '0');
		while (*str != '\0')
			write_buff(data, *str++);
	}
}

void ft_convertints(t_data *data, va_list *args)
{
	int n;
	int precision;
	int s_nbr;
	char *nbr;
	n = va_arg(*args, int);
	if (!n)
		n = 0;
	nbr = ft_itoa(n);
	precision = ft_atoi(data->precision);
	s_nbr = (int)ft_strlen(nbr);

	// if (nbr[0] == '-')
	// {
	// 	write_buff(data, '-');
	// 	ft_memdel((void *)&nbr);
	// 	nbr = ft_itoa(-n);
	// }
	ft_handle_spaces(data, nbr);
}
