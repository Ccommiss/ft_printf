#include "ft_printf.h"

void ft_convertchar(t_data *data, va_list *args)
{
	char c;
	c = va_arg(*args, int);

	int precision;
	int width;
	int i;
	int str_len;

	i = 0;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	str_len = 1;

	if (data->minus == 0)
	{
		if (data->width == 1 && width != 0)
			while (i++ < width - str_len - precision)
				data->buff[data->len++] = ' ';
		i = 0;
		// if (data->point == 1)
		// 	while (i++ < precision && c != '\0')
		// 		data->buff[data->len++] = c;
		// else
		// 	while (c!= '\0')
				data->buff[data->len++] = c;
	}
	else if (data->minus == 1)
	{
		if (data->point == 1)
			while (i++ < precision && c != '\0')
				data->buff[data->len++] = c;
		else
			data->buff[data->len++] = c;
		if (data->width == 1)
			while ((str_len < precision && width-- - precision > 0) || (str_len > precision && width-- - (str_len - precision) > 0))
				data->buff[data->len++] = ' ';
	data->buff[data->len++] = c;
	}

}

int ft_table(char type)
{
	if (type == 'd' || type == 'i')
		return (fint);
	if (type == 's')
		return (fstr);
	if (type == 'c')
		return (fchar);
	if (type == 'p')
		return (fadd);
	return (0);
}

int ft_analyse(t_data *data, char flag) //faire une fonction reset pour le prochain arg
{
	if (flag == '0')
		data->zero = 1;
	else if (flag == '*')
		data->wildcard = 1;
	else if (flag == '-')
		data->minus = 1;
	else if (flag == '.')
		data->point = 1;
	//else if (ft_isdigit((int)flag) == 1)
	else if (flag == 'w')
		data->width = 1;
	return (1);
}

void ft_getwildcard(t_data *data, va_list *args)
{
	int w;
	char *get_num;
	int i;
	int n;
	w = va_arg(*args, int);
	get_num = ft_itoa(w);
	i = 0;
	n = 0;


	if (data->point == 0)
	{
		data->width = 1;
		while (get_num[i] != '\0')
			data->twidth[n++] = get_num[i++];
	}
	else
	{
		while (get_num[i] != '\0')
			data->precision[n++] = get_num[i++];
	}
//	ft_memdel((void *)get_num);

}

int ft_take_args(t_data *data, char *input, va_list *args)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (input[i] == '-' && (ft_analyse(data, '-') == 1))
		i++;
	if (input[i] == '*' && (ft_analyse(data, '*') == 1))
	{
		ft_getwildcard(data, args);
		i++;
	}
	if (input[i] == '0' && data->minus == 0 && (ft_analyse(data, '0') == 1)) // car flag 0 ignore si minus
	{
		while (input[i] == 0) //on trime les 0 si y en a bcp en input
			i++;
		while (ft_table(input[i]) == 0 && input[i] != '.') // tant qu'on est pas tombe sur le flag, on avance
			data->precision[n++] = input[i++];
		if (input[i] == '.')
			ft_bzero((void *)data->precision, n);
	}
	n = 0;
	if (ft_isdigit(input[i]) == 1 && (ft_analyse(data, 'w') == 1))
		while (input[i] != '.' && ft_table(input[i]) == 0)
			data->twidth[n++] = input[i++];
	n = 0;
	if (input[i] == '.' && (ft_analyse(data, '.') == 1) && input[i + 1] != '*')
		while (ft_table(input[++i]) == 0)
			data->precision[n++] = input[i];

	if (input[i + 1] == '*')
		i++;
	if (input[i] == '*' && (ft_analyse(data, '*') == 1))
	{
		ft_getwildcard(data, args);
		i++;
	}
	return (i);
}

void ft_parser(const char *input, t_data *data, va_list *args)
{
	int i;
	i = 0;

	ft_reset_flags(data);
	while (input[i] && input[i] != '%')
		data->buff[data->len++] = input[i++];
	if (input[i] == '%')
	{
		i++;
		i = i + ft_take_args(data, (char *)input + i, args);
		data->f[ft_table(input[i])](data, args); //va_arg(*args, char *));
		i++;
	}
	if (input[i] != 0 && (input + i))
		ft_parser(input + i, data, args);
	else
		data->buff[data->len] = '\0';
}

void ft_reset_flags(t_data *data)
{
	data->zero = 0;
	data->minus = 0;
	data->wildcard = 0;
	data->point = 0;
	data->width = 0;
	ft_bzero((void *)data->precision, 12);
	ft_bzero((void *)data->twidth, 12);
}

void init_printf(t_data *data)
{
	data->len = 0; //longueur totale du buffer qu'on aura a afficher
	data->f[fint] = (func)&ft_convertints;
	data->f[fstr] = (func)&ft_convertstr;
	data->f[fchar] = (func)&ft_convertchar;
	data->f[fadd] = (func)&ft_convertadd;
	data->zero = 0;
	data->ret = 0;
	ft_bzero((void *)data->precision, 12);
	ft_bzero((void *)data->twidth, 12);
}


int ft_printf(const char *input, ...)
{
	char *var;
	t_data data;
	va_list args;
	init_printf(&data);
	va_start(args, input);
	ft_parser(input, &data, &args);
	//ft_putstr(input);
	var = va_arg(args, char *);
	ft_putstr(data.buff);
	va_end(args);
	//return (data.len);
	//printf ("LEN IS = %d\n", data.len);
	data.ret = data.ret + data.len;
	return (data.ret);
}
