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

	w = va_arg(*args, int);
	get_num = ft_itoa(w);
	i = 0;
	n = 0;
	if (data->point == 0)
	{
		data->width = 1;
		if (w < 0)
		{
			data->minus = 1;// TEST SI JAMAIS "-2" EN * : EST CE QUE CA COMPTE COMME MINUS ? SEMBLE OK
			data->zero = 0; // 0 ignore si minus
			get_num = ft_itoa(-w);
		}
		if (data->zero == 1) // TEST SI JAMAIS "02" EN * : EST CE QUE CA COMPTE COMME MINUS ? SEMBLE OK
			while (get_num[i] != '\0')
				data->precision[n++] = get_num[i++];
		else 
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

	// NEW ONE DOESNT WORK 

	// while (input[i] && ft_table(input[i]) == 0)
	// {
	// 	if (input[i] == '-')
	// 		ft_analyse(data, '-');
	// 	if (input[i] == '*' && (ft_analyse(data, '*') == 1))
	// 		ft_getwildcard(data, args);
	// 	if (input[i] == '0' && data->minus == 0 && (ft_analyse(data, '0') == 1)) // car flag 0 ignore si minus
	// 	{
	// 		while (input[i] == 0) //on trime les 0 si y en a bcp en input
	// 			i++;
	// 		while (input[i] && ft_table(input[i]) == 0 && input[i] != '.' && ft_isdigit(input[i])) // tant qu'on est pas tombe sur le flag, on avance
	// 			data->precision[n++] = input[i++];
	// 		if (input[i] == '.')
	// 		ft_bzero((void *)data->precision, n);
	// 	}
	// 	n = 0;
	// 	if (ft_isdigit(input[i]) == 1 && (ft_analyse(data, 'w') == 1))
	// 		while (input[i] != '.' && ft_table(input[i]) == 0 && ft_isdigit(input[i]))
	// 			data->twidth[n++] = input[i++];
	// 	n = 0;
	// 	if (input[i] == '.' && (ft_analyse(data, '.') == 1) && input[i + 1] != '*' && i++) 
	// 		while (ft_table(input[i++]) == 0 && ft_isdigit(input[i]))
	// 			data->precision[n++] = input[i];
	// 	i++;
	// 	ft_take_args(data, input + i, args);
	// }

	///OLD ONE  forme extreme : %0*.*i 

	if (input[i] == '-' && (ft_analyse(data, '-') == 1))
		i++;

	if (input[i] == '0' && data->minus == 0 && (ft_analyse(data, '0') == 1)) // car flag 0 ignore si minus
	{
		while (input[i] == '0') //on trime les 0 si y en a bcp en input
			i++;
		while (input[i] && ft_table(input[i]) == 0 && input[i] != '.' && ft_isdigit(input[i])) // tant qu'on est pas tombe sur le flag, on avance
			data->precision[n++] = input[i++];
		if (input[i] == '.')
		{
			ft_memcpy(data->twidth, data->precision, n); // test, si y a un point, ce qu'il y a avant est la width et non la prec
			ft_bzero((void *)data->precision, n);
		}
	}
	if (input[i] == '*' && (ft_analyse(data, '*') == 1))
	{
		ft_getwildcard(data, args);
		i++;
	}
	if (input[i] == '-' && (ft_analyse(data, '-') == 1)) // test si jamais forme 0-d par ex
		i++;
	n = 0;
	if (ft_isdigit(input[i]) == 1 && (ft_analyse(data, 'w') == 1))
		while (input[i] != '.' && ft_table(input[i]) == 0 && ft_isdigit(input[i]))
			data->twidth[n++] = input[i++];
	n = 0;
	if (input[i] == '.' && (ft_analyse(data, '.') == 1) && input[i + 1] != '*')
		while (ft_table(input[++i]) == 0 && ft_isdigit(input[i]))
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
