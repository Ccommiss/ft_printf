#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

void print_ints(int num, ...) ///... = ellipse
{
	va_list args;
	int i = 0;

	va_start(args, num); //tu vas commencer la liste juste apres cette variable num, dans la liste d'args
	printf("Num vaut %d\n", num); //num va definir le nb de args int qu on a vrm envoye

	int value = num;
	while (value != 0)
	{
		printf("Value : %d _ i : %d\n", value, i);
		value = va_arg(args, int);
		i++;
	}
	va_end(args);
}


void print_chars(int num, ...) ///... = ellipse
{
	va_list args;
	int i = 0;

	va_start(args, num); //tu vas commencer la liste juste apres cette variable num, dans la liste d'args
	printf("Num vaut %d\n", num); //num va definir le nb de args int qu on a vrm envoye
	int value = 1;
	while (value)
	{
		int value = va_arg(args, int);
		printf("Value : %c _ i : %d\n", value, i);
		i++;
	}
	va_end(args);
}


// void print_chars(int num, ...) ///... = ellipse
// {
// 	va_list args;
// 	int i = 0;

// 	va_start(args, num); //tu vas commencer la liste juste apres cette variable num, dans la liste d'args
// 	printf("Num vaut %d\n", num); //num va definir le nb de args int qu on a vrm envoye

// 	while (num != 0)
// 	{
// 		char *value = va_arg(args, int);
// 		printf("Value : %s _ i : %d\n", value, i);
// 		i++;
// 	}
// 	va_end(args);
// }

int main()
{
	print_ints(3, 24, 39, 9092, 0, 89);
	//print_chars(4, 'a', 'b', 'c', 'd');
	//print_strings(4, "TATA");
}
