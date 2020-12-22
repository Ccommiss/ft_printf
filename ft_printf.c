#include "ft_printf.h"

void ft_convertchar(t_data *data, va_list *args)
{
	char c;
	c = va_arg(*args, int);
	data->buff[data->len++] = c;
}



void ft_converthex(t_data *data, uintptr_t input)
{
	char HEX[17] = "0123456789abcdef";
	int index = 13;
	char output[15];

	output[0] = '0';
    output[1] = 'x';
	output[2] = 'f';
    while (input > 0 ) {
        output[index] = HEX[input & 15];
        input = input/16;
		index--;
    }
	output[14] = '\0';
	index = 0;
	while (index != 14)
		data->buff[data->len++] = output[index++];


}
void ft_convertadd(t_data *data, va_list *args)
{
	char *ptr;
	ptr = va_arg(*args, char *);
	uintptr_t x = (uintptr_t)ptr;
	ft_converthex(data, x);
}

void ft_convertints(t_data *data, va_list *args)
{
	int n;
	int precision;
	int i = 0;
	int s_nbr;
	char *nbr;
	n = va_arg(*args, int);
	nbr = ft_itoa(n);
	precision = ft_atoi(data->precision);
	s_nbr = (int)ft_strlen(nbr);

	if ((precision - s_nbr) > 0)
	{
		if (nbr[0] == '-')
		{
			data->buff[data->len++] = '-';
			ft_memdel((void *)&nbr);
			nbr = ft_itoa(-n);
		}
		while (i++ < (precision - s_nbr) && data->minus == 0) //gere les flags 0 et . pour les positifs
			data->buff[data->len++] = '0';
		if (n < 0 && data->zero == 0 && data->minus == 0) //extra 0 pour le flag . avec nb neg car c'est la largeur du nombre
				data->buff[data->len++] = '0';
	}
	while (*nbr != '\0' && !(n == 0 && data->point == 1))
		data->buff[data->len++] = *nbr++;
	while (data->minus == 1 && (precision-- - s_nbr) > 0)
		data->buff[data->len++] = ' ';
}

void ft_convertstr(t_data *data, va_list *args)
{
	char *str;
	int precision;
	int width;
	int i;

	i = 0;
	str = va_arg(*args, char *);
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);

	if (data->width == 1 && width != 0)
		while (i++ < width - (ft_strlen(str) - precision))
			data->buff[data->len++] = ' ';
	i = 0;
	if (data->point == 1)
		while (i++ < precision && *str != '\0')
			data->buff[data->len++] = *str++;
	else
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
	if (type == 'p')
		return(fadd);
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
		data->point = 1;
	else if (ft_isdigit((int)flag) == 1)
		data->width = 1;
	return 0;
}

int ft_fill_width(t_data *data, char *str)
{
	int i;

	i = 0;
	while (ft_table(*str) == 0 && *str != '.' && data->point == 0) // tant qu'on est pas tombe sur le flag, on avance
		data->twidth[i++] = *str++;

	return (i);
}

int ft_fill_precision(t_data *data, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (data->zero == 1)
	{
		while (*str == 0) //on trime les 0 si y en a bcp en input
			str++;
		while (ft_table(*str) == 0) // tant qu'on est pas tombe sur le flag, on avance
			data->precision[i++] = *str++;
	}
	else if (data->width == 1 && data->point == 0)
	{
		while (ft_table(*str) == 0 && *str != '.' && data->point == 0) // tant qu'on est pas tombe sur le flag, on avance
				data->twidth[i++] = *str++;
		if (*str == '.' && *str++)
		{
			data->point = 1;
			while (ft_table(*str) == 0)
				data->precision[n++] = *str++;
			i = n + i + 1;
		}
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
	i = 0;

	ft_reset_flags(data);
	while (input[i] && input[i] != '%')
		data->buff[data->len++] = input[i++];
	if (input[i] == '%')
	{
		while ((ft_table(input[++i])) == 0) // tant qu'on a pas le type
		{
			ft_analyse(data, input[i++]);
			if (data->point == 1 || data->zero == 1 || data->minus == 1 || (data->width == 1 && i--))
			{
				i = i + ft_fill_precision(data, input + i);
				break; // i prend la valeur i + la ou on va s'arreter soit qd on va arriver au type
			}
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
	data->point = 0;
	data->width = 0;
	while (i <= 12)
	{
		data->twidth[i] = 0;
		data->precision[i++] = 0;
	}
}

void init_printf(t_data *data)
{
	int i;

	i = 0;
	data->len = 0; //longueur totale du buffer qu'on aura a afficher
	data->f[fint] = (func)&ft_convertints;
	data->f[fstr] = (func)&ft_convertstr;
	data->f[fchar] = (func)&ft_convertchar;
	data->f[fadd] = (func)&ft_convertadd;
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
	//char str[4] = "tata";
	int i = 8;
	//ft_printf("Addresse : %04p oo\n", &i);
//	printf("Addresse : %04p oo\n\n", &i);

	ft_printf("%10.2s\n\nWTF", "tati");
	printf("\n\n%10.2s\n", "tati");

	ft_printf("\n\n%.9d lol %-10d he %10s\n", 2, -1234, "tati");
	printf("%.9d lol %-10d he %10s\n", 2, -1234, "tati");

	ft_printf("%02d lol %06d he %.0s\n", 0, -1234, "tati");
	printf("%02d lol %06d he %.0s\n", 0, -1234, "tati");

	ft_printf("%.6d lol %.6d\n", -425, 1234);
	printf("%.6d lol %.6d\n", -425, 1234);

	ft_printf("yo %s lol la vie est %s\n", "hello", "belle");
	ft_printf("je suis un char %c kiki\n", 'p');

//	printf("PRINTF : je suis prems la chaine %09d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %0000000000000000000023d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %.9d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %.9d lol %d\n", 456745, 1234);
//	printf("coucou", "ca va", "YO", "j'ai froid");
}
