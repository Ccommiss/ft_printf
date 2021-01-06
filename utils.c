#include "ft_printf.h"

/*
**	<UTILS.C> : ft_analyse, ft_table, ft_init, ft_resetflags
*/

/*
**	ft_analyse
**
**  [Usage] : turning 1 to conversions specificators in t_data.
**	[Call] :
**		In ft_take_args when the specificator is encountered.
**	[Arguments] : t_data structure and specificator encountered
**	[Return] : always 1
**	[Nb] : none
*/

void	write_buff(t_data *data, char c)
{
	data->buff[data->len++] = c;
	if (data->len == 2048)
	{
		ft_putstr(data->buff);
		ft_bzero((void *)data->buff, 2048);
		data->ret = data->ret + data->len;
		data->len = 0;
	}
}



int ft_analyse(t_data *data, char flag) //faire une fonction reset pour le prochain arg
{
	if (flag == '0' && data->minus == 0) // si data minus est la pas de 0, test
		data->zero = 1;
	else if (flag == '*')
		data->wildcard = 1;
	else if (flag == '-')
	{
		data->minus = 1;
		data->zero = 0;
	}
	else if (flag == '.')
		data->point = 1;
	else if (flag == 'w')
		data->width = 1;
	return (1);
}

/*
**	ft_table
**
**  [Usage] : determines type of conversion to process.
**	[Call] :
**		In ft_take_args to verify char is not yet a conversion.
**		In ft_parser to call the correct function.
**	[Arguments] : type of conversion
**	[Return] : number of the function in the functions tab func f[10], or 0
**	if none have been found.
**	[Nb] : none
*/

int ft_table(char type)
{
	if (type == 'd' || type == 'i') //u provisoire
		return (fint);
	if (type == 'u')
		return (funsigned);
	if (type == 's')
		return (fstr);
	if (type == 'c')
		return (fchar);
	if (type == 'p')//x provisoire
		return (fadd);
	if (type == 'x')
		return (fhex);
	if (type == 'X')
		return (fhexU);
	if (type == '%')
		return(fpercent);
//	if (ft_isalpha(type)) // peut etre faire fonctions wrong conversions
//		return (wrong); //jsp pk c si jamais on a un truc genre %10as%
	return (0);
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
	data->f[fhex] = (func)&ft_converthex;
	data->f[fhexU] = (func)&ft_converthexU;
	data->f[fpercent] = (func)&ft_percent;
	data->f[funsigned] = (func)&ft_convertunsignedints;
	data->f[wrong] = (func)&ft_wrong;
	data->ret = 0;
	//ft_bzero((void *)data->precision, 12); //idem car dans reset flag
//	ft_bzero((void *)data->twidth, 12);
}
