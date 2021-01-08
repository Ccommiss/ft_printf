#include "ft_printf.h"

int main()
{
	int a;
	printf("Hello %n c moi\n", &a);
	printf ("%d\n", a);

	int c;
	ft_printf("Hello %n c moi\n", &c);
	ft_printf("%d\n", c);

	//ft_printf("%111111111111111111111111d\n", 3);

}
