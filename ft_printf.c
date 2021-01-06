#include "ft_printf.h"

/*
**	ft_convertchar
**
**  [Usage] : handles char conversion and writes in buffer.
**	[Call] : in ft_parser
**	[Arguments] : structure and lists of arguments passed to ft_printf
**	[Return] : none
**	[Nb] :
**	Precision (.[prec]) is not handled by c conversion, undefined behaviour
*/

void ft_convertchar(t_data *data, va_list *args)
{
	char c;
	int width;

	c = va_arg(*args, int);
	width = ft_atoi(data->twidth);
	if (data->minus == 0)
	{
		if (data->width == 1 && width != 0)
			while (width-- - 1 > 0)
				write_buff(data, ' ');//data->buff[data->len++] = ' ';
		write_buff(data, c);
	}
	else if (data->minus == 1)
	{
		write_buff(data, c);
		if (data->width == 1)
			while (width-- - 1 > 0)
				write_buff(data, ' ');
	}
}


/*
**	ft_getwildcard
**
**  [Usage] : gets width and precision from wildcards.
**	[Call] :
**		In ft_take_args, before and after eventually encounters a '.'
		(precision specificator)
**	[Arguments] : t_data structure and specificator encountered
**	[Return] : always 1
**	[Nb] : none
*/


void ft_getwildcard(t_data *data, va_list *args)
{
	int w;
	char *get_num;
	int i;
	int n;

	w = va_arg(*args, int); //si on envoie un arg negatif
	get_num = ft_itoa(w);
	i = 0;
	n = 0;
	if (data->point == 0) // GET WIDTH
	{
		if (w < 0)
		{
			get_num = ft_itoa(-w);
			data->minus = 1; // vrmt chelou mais je crois c ca
		}
		data->width = 1;
			while (get_num[i] != '\0')
				data->twidth[n++] = get_num[i++];
	}
	else if (data->point == 1) // GET PRECISION
	{
		if (w < 0)
		{
			data->point = 0; // pas de precision si elle est negative
			ft_bzero((void *)data->precision, 12);
			return ;
		}
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

	// GET WIDTH, 0, WILDCARDS
	while (input[i] && ft_table(input[i]) == 0 && input[i] != '.') //on recupere tout ce que y a avant le point
	{
		if (input[i] == '-' && data->minus == 0) //si ya un moins mais slt si pas deja mis
		 	ft_analyse(data, '-');
		if (input[i] == '0' && data->width == 0) // On checke le flag 0 mais valable seulement si pas de width encore
		 	ft_analyse(data, '0');
		if (input[i] == '*' && (ft_analyse(data, '*') == 1))
			ft_getwildcard(data, args);
		if (ft_isdigit(input[i]) && ft_analyse(data, 'w') == 1) // On arrive a la width
				data->twidth[n++] = input[i];
		i++;
	}
	// GET PRECISION
	n = 0;
	if (input[i] == '.' && (ft_analyse(data, '.') == 1))
	{
		i++;
		if (input[i] == '*' && (ft_analyse(data, '*') == 1))
		{
			ft_getwildcard(data, args);
			i++;
		}
		else
			while (ft_table(input[i]) == 0 && ft_isdigit(input[i]))
				data->precision[n++] = input[i++];
	}
	return (i);
}

void ft_wrong(t_data *data, va_list *args)
{
	(void)args;
	(void)data;
}

void ft_parser(const char *input, t_data *data, va_list *args)
{
	int i;
	i = 0;

	ft_reset_flags(data);
	while (input[i] && input[i] != '%')
		write_buff(data, input[i++]);//data->buff[data->len++] = input[i++];
	if (input[i] == '%') //deuxieme partie = test
	{
		i++;
		i = i + ft_take_args(data, (char *)input + i, args);
		if (ft_table(input[i]))
			data->f[ft_table(input[i])](data, args);
		i++;
	}
	if (input[i] != 0 && (input + i))
		ft_parser(input + i, data, args);
	else
		write_buff(data, '\0');//data->buff[data->len] = '\0';
}






int ft_printf(const char *input, ...)
{
	char *var;
	t_data data;
	va_list args;
	init_printf(&data);
	va_start(args, input);
	ft_parser(input, &data, &args);
	var = va_arg(args, char *);
	ft_putstr(data.buff);
	va_end(args);
	data.ret = data.ret + data.len - 1;
	return (data.ret);
}
