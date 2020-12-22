#include "libft/libft.h"
#include <stdarg.h>


enum fnames { //pour gerer les conversions apres et les casts

    fint = 1, fchar, fstr, fadd
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
	struct data *next; // pt sur le prochain

}				t_data;


void ft_reset_flags(t_data *data);
void ft_convertadd(t_data *data, va_list *args);
void ft_convertchar(t_data *data, va_list *args);
void ft_handle_spaces(t_data *data, char *str);
void ft_convertints(t_data *data, va_list *args);
void ft_convertstr(t_data *data, va_list *args);
void ft_converthex(t_data *data, uintptr_t input);
int		ft_table(char type);
