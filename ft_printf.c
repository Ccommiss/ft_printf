#include <stdio.h>
#include <stdarg.h>

void print_ints(int num, ...)
{
	va_list args;
	int i = 0;

	va_start(args, num);
	printf("Num vaut %d\n", num); //num va definir le nb de int qu on a vrm envoye

	while (i < num)
	{
		int value = va_arg(args, int);
		printf("Value : %d _ i : %d\n", value, i);
		i++;
	}
	va_end(args);
}

int main()
{

	print_ints(3, 24, 39, 90923);
	print_ints(8, 12, 1996, 3630);

}
