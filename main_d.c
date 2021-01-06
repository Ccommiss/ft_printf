#include "ft_printf.h"

int main()
{


	printf ("Tests:\n");

	printf("R-- Return : %d\n", printf("%12.9d", 8));
		printf("R-- Return : %d\n", printf("%9d", 8));
	printf("R-- Return : %d\n", printf("%-8.17d", 8));
	printf("R-- Return : %d\n", printf("%0.*d", 2, 8));


	// printf ("Precision apres point positive :\n");
	// printf ("Wildcards :\n");
	// printf("R-- Return : %d\n", printf("%0*.*d ", 0, 2, 8));
	// ft_printf("M-- Return : %d\n", ft_printf("%0*.*d ", 0, 2, 8));

	// printf ("Sans wildcards :\n");
	// printf("R-- Return : %d\n", printf("%00.2d ", 8));
	// ft_printf("M-- Return : %d\n", ft_printf("%00.2d ", 8));


	// printf ("Precision apres point negative : pas le droit\n");
	// printf ("Wildcards :\n");
	// printf("R-- Return : %d\n", printf("%0*.*d ", 9, -7, 8));
	// ft_printf("M-- Return : %d\n", ft_printf("%0*.*d ", 9, -7, 8));

// 	printf ("Sans Wildcards :\n");
// 	printf("R-- Return : %d\n", printf("%00.-9d|", 8)); //pas le droit comme ca
// 	// cas au dessus : precision negative, interpretee comme precision du coup 9 espaces
// 	ft_printf("M-- Return : %d\n", ft_printf("%-9d|", 8));

// 	printf ("La:\n");

// 	printf("R-- Return : %d\n", printf("%09.-1d ", 8));
// 	ft_printf("M-- Return : %d\n", ft_printf("%09.-1d ", 8));


// //	ft_printf("M-- Return : %d\n", ft_printf("%00.-9d|", 8)); // affiche '9d'


// //	printf("R-- Return : %d\n", printf("%00.9d|", 8));
// 	//ft_printf("M-- Return : %d\n", ft_printf("%00.9d|", 8));

// 	printf ("Sans Wildcards :\n");
// 	printf("R-- Return : %d\n", printf("%08.-9d|", 8)); //pas le droit comme ca
// 	// cas au dessus : precision negative, interpretee comme precision du coup 9 espaces
// 	ft_printf("M-- Return : %d\n", ft_printf("%08.-9d|", 8));
}
