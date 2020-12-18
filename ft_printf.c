#include "ft_printf.h"

void ft_convertchar(t_data *data, va_list *args)
{
	char c;
	c = va_arg(*args, int);
	data->buff[data->len++] = c;
}

void ft_convertints(t_data *data, va_list *args)
{
	int n;
	int precision;
	int i = 0;
	n = va_arg(*args, int);
	char *nbr;
	nbr = ft_itoa(n);
	precision = ft_atoi(data->precision);

	int s_nbr = (int)ft_strlen(nbr);

	if ((precision - s_nbr) > 0)
		while (i++ < (precision - s_nbr))
			data->buff[data->len++] = '0';
	while (*nbr != '\0')
		data->buff[data->len++] = *nbr++;
}

void ft_convertstr(t_data *data, va_list *args)
{
	char *str;
	str = va_arg(*args, char *);
	while (*str != '\0')
		data->buff[data->len++] = *str++;
}

int		ft_table(char type)
{
	if (type == 'd' || type == 'i')
		return (fint);
	if (type == 's')
		return (fstr);
	if (type == 'c')
		return (fchar);
	return (0);
}

int		ft_analyse(t_data *data, char flag) //faire une fonction reset pour le prochain arg
{
	if (flag == '0')
		data->zero = 1;
	else if (flag == '*')
		data->wildcard = 1;
	else if (flag == '-')
		data->minus = 1;
	else if (flag == '.')
		data->precision[0] = '.';
	return 0;
}


int ft_fill_precision(t_data *data, char *str)
{
	int i;

	i=0;
	if (data->zero == 1)
	{
		while (*str == 0) //on trime les 0 si y en a bcp en input
			str++;
		while (ft_table(*str == 0)) // tant qu'on est pas tombe sur le flag, on avance
			data->precision[i++] = *str++;
	}
	else
	{
		while (ft_table(*str) == 0)
			data->precision[i++] = *str++;
	}
	return (i);
}

void ft_parser(char *input, t_data *data, va_list *args)
{
	int i;
	//int var;
	i = 0;

	ft_reset_flags(data);
	while (input[i] && input[i] != '%')
		data->buff[data->len++] = input[i++];
	if (input[i] == '%')
	{
		while ((ft_table(input[++i])) == 0) // tant qu'on a pas le type
		{
			ft_analyse(data, input[i++]);
			if (data->precision[0] == '.' || data->zero == 1)
			{
				i = i + ft_fill_precision(data, input + i);
				break ;
			} // i prend la valeur i + la ou on va s'arreter soit qd on va arriver au type
		}
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
	int i;

	i = 0;
	data->zero = 0;
	data->minus = 0;
	data->wildcard = 0;
	while (i <= 12)
		data->precision[i++] = 0;

}

void init_printf(t_data *data)
{
	int i;

	i = 0;
	data->len = 0; //longueur totale du buffer qu'on aura a afficher
	data->f[fint] = (func)&ft_convertints;
	data->f[fstr] = (func)&ft_convertstr;
	data->f[fchar] = (func)&ft_convertchar;
	data->zero = 0;
	while (i <= 12)
		data->precision[i++] = 0;
}

void	ft_printf(char *input, ...)
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
}

int main()
{
	ft_printf("%.4d lol %d\n", 425, 1234);

	//ft_printf("yo %s lol la vie est %s\n", "hello", "belle");
//	ft_printf("je suis un char %c kiki\n", 'p');

//	printf("PRINTF : je suis prems la chaine %09d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %0000000000000000000023d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %.9d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %.9d lol %d\n", 456745, 1234);
//	printf("coucou", "ca va", "YO", "j'ai froid");
}
