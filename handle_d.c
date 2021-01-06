#include "ft_printf.h"

void	ft_right_align(t_data *data, int padding, int precision, char *str)
{
	int i;

	i = 0;
	if (data->point == 0) //si pas de precision, le padding = des 0 ou des espaces selon.
			while (i++ < padding)
				if (data->zero == 0)
					write_buff(data, ' ');
				else
				{
					if (*str == '-')
						write_buff(data, *str++);
					write_buff(data, '0');
				}
	else // si precision, alors pendant padding - precision, on remplit de blancs
		{
			padding = padding - precision; //padding = les espaces ou les 0 de largeurs
			while (i++ < padding)
				write_buff(data, ' ');
			i = 0;
			if (*str == '-')
				write_buff(data, *str++);
			while (i++ < precision)
				write_buff(data, '0');
		}
	while (*str)
		write_buff(data, *str++);
}

void	ft_left_align(t_data *data, int padding, int precision, char *str) //option 0 ignoree
{
	int i;

	i = 0;
	if (*str == '-')
		write_buff(data, *str++);
	if (data->point == 1)
		while (i++ < precision)
			write_buff(data, '0');
	while (*str)
		write_buff(data, *str++);
	if (data->point == 1)
		padding = padding - precision;
	i = 0;
	while (i++ < padding)
		write_buff(data, ' ');
}

void ft_handle_spaces(t_data *data, char *str)
{
	int precision;
	int padding;
	int len_str;
	int i;
	len_str = (int)ft_strlen(str);
	precision = ft_atoi(data->precision) - len_str;
	padding = ft_atoi(data->twidth) - len_str;

	if (data->point == 1 && *str == '-') // car la longueur de la chaine fait perdre un pt de precision
		precision = precision + 1;

	if (padding < 0)
		padding = 0;
	if (precision < 0)
		precision = 0;

	i = 0;
	//exception si precison = 0 et nb = 0 : ca ne renvoie rien
	if (len_str == 1 && str[0] == '0' && data->point == 1 && (precision + len_str)  == 0)
	{
	 	str[0] = '\0';
	 	if (padding != 0)
			str[0] = ' ';
	}
	if (data->minus == 0)
		ft_right_align(data, padding, precision, str);
	if (data->minus == 1)
		ft_left_align(data, padding, precision, str);


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
	ft_handle_spaces(data, nbr);
}
