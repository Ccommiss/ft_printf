#include "libft/libft.h"
#include <stdarg.h>


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define FCYAN       "\x1b[36m"
#define TEST1       "\x1b[37m"
#define NONE        "\033[0m"

enum fnames { //pour gerer les conversions apres et les casts

    fint = 1, fchar, fstr, fadd, fhex, fhexU, fpercent, wrong
}	my_enum;



typedef void (*func)(void *, ...);

typedef struct s_data {

	char buff[2048];
	int len; //sera equivalent a strlen de la string // la chaine de carac de l'elem

	char precision[12]; //pour le flag . -> max 11 chiffres apres le point
	char twidth[12]; // pour gerer la width (avant le point)
	int point;
	int zero; // mettre a 0 par defaut, 1 s'il y a un zero
	int minus; // met a gauche
	int wildcard; // a remplacer
	int width; //chiffre sans autre truc
	func f[10];
	int ret;
	struct data *next; // pt sur le prochain

}				t_data;



void ft_reset_flags(t_data *data);

/*
**  <CONVERSIONS> :  functions related to conversions
*/

void ft_convertadd(t_data *data, va_list *args);
void ft_convertchar(t_data *data, va_list *args);
void ft_convertints(t_data *data, va_list *args);
void ft_convertstr(t_data *data, va_list *args);
void ft_converthex(t_data *data, va_list *args);
void ft_converthexU(t_data *data, va_list *args);
void ft_convertadd(t_data *data, va_list *args);
void ft_percent(t_data *data, va_list *args);

/*
**  <UTILS> :  architecture of printf
*/


void ft_wrong(t_data *data, va_list *args);

void str_treat(t_data *data, char *str);
void ft_handle_spaces(t_data *data, char *str);


/*
**  < UTILS.C > :  architecture of printf
*/

void	write_buff(t_data *data, char c);
void	init_printf(t_data *data);
void	ft_reset_flags(t_data *data);
int		ft_table(char type);
int		ft_analyse(t_data *data, char flag);

int  ft_printf(const char *input, ...);
