#include "libft/libft.h"
#include <stdarg.h>


enum fnames { //pour gerer les conversions apres et les casts

    fint = 1, fchar, fstr
}	my_enum;



typedef void (*func)(void *, ...);

typedef struct s_data {

	char buff[2048];
	int len; //sera equivalent a strlen de la string // la chaine de carac de l'elem

	char precision[12]; //pour le flag . -> max 11 chiffres apres le point
	int zero; // mettre a 0 par defaut, 1 s'il y a un zero
	int minus; // met a gauche
	int wildcard; // a remplacer
	func f[10];
	struct data *next; // pt sur le prochain

}				t_data;


void ft_reset_flags(t_data *data);
