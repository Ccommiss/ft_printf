#include "ft_printf.h"

void ft_convertchar(t_data *data, va_list *args)
{
	char c;
	c = va_arg(*args, int);
	data->buff[data->len++] = c;
}


void ft_convertadd(t_data *data, va_list *args)
{
	char *ptr;
	ptr = va_arg(*args, char *);
	uintptr_t x = (uintptr_t)ptr;
	ft_converthex(data, x);
}

void ft_handle_spaces(t_data *data, char *str)
{
	int precision;
	int width;
	int len_str;
	int i;
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	(data->len != 0 && data->buff[data->len-1] == '-') ? (width = width - 1) : (width = width);
	len_str = (int)ft_strlen(str);
	i = 0;

	if (data->minus == 1)
	{
		while (precision-- - len_str > 0)
       		data->buff[data->len++] = '0';
		while (*str != '\0')
        	data->buff[data->len++] = *str++;
		precision = ft_atoi(data->precision);
		if (precision > len_str)
			while (width-- - precision > 0)
				data->buff[data->len++] = ' ';
		else
			while (width-- - len_str > 0)
				data->buff[data->len++] = ' ';
	}
	else if (data->minus == 0)
	{
		if (data->point == 1)
			while ((len_str < precision && width-- - precision > 0)
				|| (len_str > precision && width-- - len_str > 0))
				data->buff[data->len++] = ' ';
		else
			while (width-- - len_str > 0)
				data->buff[data->len++] = ' ';
		while (precision - len_str++ > 0)
       		data->buff[data->len++] = '0';
		while (*str != '\0')
        	data->buff[data->len++] = *str++;
	}
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

	if (nbr[0] == '-')
	{
		data->buff[data->len++] = '-';
		ft_memdel((void *)&nbr);
		nbr = ft_itoa(-n);
	}
	ft_handle_spaces(data, nbr);
}

void ft_convertstr(t_data *data, va_list *args)
{
	char *str;
	int precision;
	int width;
	int i;
	int str_len;

	i = 0;
	str = va_arg(*args, char *);
	precision = ft_atoi(data->precision);
	width = ft_atoi(data->twidth);
	str_len = ft_strlen(str);

	if (data->minus == 0)
	{
	if (data->width == 1 && width != 0)
		while (i++ < width - str_len - precision)
			data->buff[data->len++] = ' ';
	i = 0;
	if (data->point == 1)
		while (i++ < precision && *str != '\0')
			data->buff[data->len++] = *str++;
	else
		while (*str != '\0')
			data->buff[data->len++] = *str++;
	}
	else if (data->minus == 1)
	{
		if (data->point == 1)
			while (i++ < precision && *str != '\0')
				data->buff[data->len++] = *str++;
		else
			while (*str != '\0')
				data->buff[data->len++] = *str++;
		if (data->width == 1)
			while (i++ <= width)
				data->buff[data->len++] = ' ';
	}
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
	while (output[index] != '\0')
		data->buff[data->len++] = output[index++];

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

int ft_take_args(t_data *data, char *input)
{
	int i;
	int n;

	i = 0;
	n = 0;
		if (input[i] == '-' && (data->minus = 1))
			i++;
		if (input[i] == '0' && data->minus == 0 && (data->zero = 1)) // car flag 0 ignore si minus
		{
			while (input[i] == 0) //on trime les 0 si y en a bcp en input
				i++;
			while (ft_table(input[i]) == 0 && input[i] != '.') // tant qu'on est pas tombe sur le flag, on avance
				data->precision[n++] = input[i++];
			if (input[i] == '.')
				ft_bzero((void *)data->precision, n);
		}
		n = 0;
		if (ft_isdigit(input[i]) == 1 && (data->width = 1))
			while (input[i] != '.' && ft_table(input[i]) == 0)
				data->twidth[n++] = input[i++];
		n = 0;
		if (input[i] == '.' && (data->point = 1))
			while (ft_table(input[++i]) == 0)
				data->precision[n++] = input[i];
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
		i++;
		i = i + ft_take_args(data, input + i);
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
	ft_bzero((void *)data->precision, 12);
	ft_bzero((void *)data->twidth, 12);
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
	printf("%50s", "Tests INT\n\n");

	ft_printf("Test 1: %15.9d\n", 1111);  //passe
	printf("Test 1: %15.9d\n", 1111);

	ft_printf("Test 2: -10.9d %-10.9d|\n", 2222);
	printf("Test 2: -10.9d %-10.9d|\n", 2222);

	ft_printf("Test 2 bis: %10.9d PLOP\n", 2222);
	printf("Test 2 bis: %10.9d PLOP\n", 2222);

	ft_printf("Test 3: %3.2d\n", 3333);
	printf("Test 3: %3.2d\n", 3333);

	ft_printf("Test 4: %00.9d\n", -4444);
	printf("Test 4: %00.9d\n", -4444);

	ft_printf("Test 5: %4.8d\n", 55555555);
	printf("Test 5: %4.8d\n", 55555555);

	ft_printf("Test 6 (no width) -16d: %-16d <-\n", 55555555);
	printf("Test 6 (no width) -16d: %-16d <-\n", 55555555);

	ft_printf("Test 6 bis 16d: %16d <-\n", 55555555);
	printf("Test 6 bis 16d: %16d <-\n", 55555555);

	ft_printf("Test 7: %-0.0d <-\n", -55);
	printf("Test 7: %-0.0d <-\n", -55);

	ft_printf("Test 8: .6d nb neg %.6d lol %.6d\n", -425, 1234);
	printf("Test 8: .6d nb neg %.6d lol %.6d\n", -425, 1234);

	ft_printf("Test 9: %13.2d| he %s\n", 1234, "tatidoum");
	printf("Test 9: %13.2d| he %s\n", 1234, "tatidoum");



	printf("%50s", "Tests STR\n\n");

	char str[4] = "tata";
	int i = 8;
	ft_printf("Addresse : %-18p oo\n", &i);
	printf("Addresse : %18p oo\n\n", &i);

	ft_printf("%-10.2s|\n", "tati");
	printf("%-10.2s|\n\n", "tati");
	printf("EUH\n");

	ft_printf("%-10d| he %s\n", -1234, "tati");
	printf("%-10d| he %s\n", -1234, "tati");
	ft_printf("mine=%-10d| he %s\n", 1234, "tati");
	printf("real=%-10d| he %s\n", 1234, "tati");

	ft_printf("mine=%13.2d| he %s\n", 1234, "tatidoum");
	printf("real=%13.2d| he %s\n", 1234, "tatidoum");

	printf("%50s", "Tests 0 values\n\n");

	ft_printf("%02d lol %-19d he %s\n", 0, -1234, "tati");
	printf("%02d lol %-19d he %s\n", 0, -1234, "tati");

	ft_printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati");
	printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati");



	// ft_printf("yo %s lol la vie est %s\n", "hello", "belle");
	// ft_printf("je suis un char %c kiki\n", 'p');

//	printf("PRINTF : je suis prems la chaine %09d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %0000000000000000000023d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %.9d lol %d\n", 456745, 1234);
//	printf("PRINTF : je suis la chaine %.9d lol %d\n", 456745, 1234);
//	printf("coucou", "ca va", "YO", "j'ai froid");
}
