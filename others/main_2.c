#include "ft_printf.h"

int main()
{
	int a;
	printf("Hello %n c moi\n", &a);
	printf ("%d\n", a);

	int c;
	ft_printf("Hello %n c moi\n", &c);
	ft_printf("%d\n", c);

	printf("%d\n", ft_printf("RET = %1d %d %d %d %d\n", 3, 8, 5));
	printf("%d\n", printf("RET = %1d %d %d %d %d\n", 3, 8, 5));

}
