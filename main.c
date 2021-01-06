#include "ft_printf.h"

void ft_test_char()
{

	int ret1;
	int ret2;



	printf("\n\n");
	printf("%50s", GREEN "[[		_________		]]\n" NONE);
	printf("%50s", GREEN "[[		Tests CHAR		]]\n" NONE);
	printf("%50s", GREEN "[[		_________		]]\n" NONE);
	printf("\n\n");

//	ret1 = ft_printf("yo %s lol la vie est %s\n", "hello", "belle");

	//ret1 = ft_printf("Test 1 : %c kiki\n", 'p');
	//ret2 = printf("Test 1 : %c kiki\n", 'p');
	//printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	//ret1 = ft_printf("Test 2 : %25c kiki\n", 'p');
	//ret2 = printf("Test 2 : %25c kiki\n", 'p');
	//printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	ret2 = printf("Test 1 : 42%-4c42 kiki\n", 'p');
	ret1 = ft_printf("Test 1 : 42%-4c42 kiki\n", 'p');
	ret2 = printf("Test 1 : 42%-4c42 kiki\n", 'p');
	//printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	ret1 = ft_printf("Test 1 : 42%-4.3c42 kiki\n", 'p');
	ret2 = printf("Test 1 : 42%-4.3c42 kiki\n", 'p');
	printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);
}

void ft_test_str()
{
	printf("\n\n");
	printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	printf("%50s", FCYAN "[[		Tests STR		]]\n" NONE);
	printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	printf("\n\n");

	ft_printf("%-20.2s|\n", "tati");
	printf("%-20.2s|\n\n", "tati");
	printf("EUH\n");

	ft_printf("%-10d| he %s\n", -1234, "tati");
	printf("%-10d| he %s\n", -1234, "tati");
	ft_printf("mine=%-10d| he %s\n", 1234, "tati");
	printf("real=%-10d| he %s\n", 1234, "tati");

	ft_printf("mine=%13.2d| he %s\n", 1234, "tatidoum");
	printf("real=%13.2d| he %s\n", 1234, "tatidoum");

	printf("\n\n");
}

void ft_test_int()
{

	printf("\n\n");
	printf("%50s", YELLOW "[[		_________		]]\n" NONE);
	printf("%50s", YELLOW "[[		Tests INT		]]\n" NONE);
	printf("%50s", YELLOW "[[		_________		]]\n" NONE);
	printf("\n\n");

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;

//	printf("Test 0 :\n");



	// 	while (a < 5) //T34-69
	// {
	// 	printf ("A = %d\n", a);
	// 	printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);

	// 	// a = -2, i = 8
	// 	printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);

	// 	printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);

	// 	printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	// 	a++;
	// }

		a = 2;
	//while(a < 5) //T70-177
//	{
		b = -2;
		// printf("POURC D TEST A = 2 B = 1 |%2.1d|REAL\n", 8);
		// ft_printf("POURC D TEST A = 2 B = 1 |%2.1d|MINE\n", 8);
		// printf("POURC I TEST A = 2 B = 1 |%3.1i|REAL\n", 16);
		// ft_printf("POURC I TEST A = 2 B = 1 |%3.1i|MINE\n", 16);

		// printf("POURC D TEST A = 2 B = 1 |%*.*d|REAL\n", 2, 1, 8);
		// ft_printf("POURC D TEST A = 2 B = 1 |%*.*d|MINE\n", 2, 1, 8);
		// printf("POURC I TEST A = 2 B = 1 |%*.*i|REAL\n", 2, 1, 8);
		// ft_printf("POURC I TEST A = 2 B = 1 |%*.*i|MINE\n", 2, 1, 8);


		while (b < 5)
		{
			printf ("\n\nA = %d\n", a);
			printf ("B = %d\n\n", b);
			//printf(" R-- Return : %d\n", printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			//printf(" M-- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			//printf(" R-- Return : %d\n", printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			//printf(" M-- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			printf(" R-- Return : %d\n", printf("%0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			printf(" M-- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			// derniere ligne ne marche jamais refaire parser
			b++;
		}
		//a++;
	//}

	ft_printf("___ Quick Test Unsigned:_____\n");
	ft_printf(" --- Return : %d\n", ft_printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	printf(" --- Return : %d\n", printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	ft_printf(" --- Return : %d\n", ft_printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T16
	printf(" --- Return : %d\n", printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T16

	printf("%u\n", 65535); // OK
	ft_printf("%u\n", 65535); //OK
	printf("%u\n", -8);
	ft_printf("%u\n", -8);


	ft_printf("Test 1: %15.9d\n", 1111); //passe
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

	ft_printf("Test 7: %-.0d <-\n", -55);
	printf("Test 7: %-.0d <-\n", -55);

	ft_printf("Test 8: .6d nb neg %.6d lol %.6d\n", -425, 1234);
	printf("Test 8: .6d nb neg %.6d lol %.6d\n", -425, 1234);

	ft_printf("Test 9: %13.2d| he %-18s|\n", 1234, "tatidoum");
	printf("Test 9: %13.2d| he %-18s|\n", 1234, "tatidoum");
}

void ft_test_hex()
{

	printf("\n\n");
	printf("%50s", MAGENTA "[[		_________		]]\n" NONE);
	printf("%50s", MAGENTA "[[		Tests HEX		]]\n" NONE);
	printf("%50s", MAGENTA "[[		_________		]]\n" NONE);
	printf("\n\n");

	char str[4] = "tata";
	int a = 8;
	ft_printf("Addresse : %-18p oo\n", &a);
	printf("Addresse : %-18p oo\n\n", &a);

	int e = 0;
	printf("TEST %d:\n", e++);
	ft_printf("Addresse : %-18p oo\n", &a);
	printf("Addresse : %-18p oo\n\n", &a);

	printf("TEST %d:\n", e++);
	ft_printf("FT = %x\n", 323);
	printf("PT = %x\n", 323);

	printf("TEST %d:\n", e++);
	ft_printf("FT = %.8x\n", 19997856);
	printf("PT = %.8x\n", 19997856);

	printf("TEST %d:\n", e++);
	ft_printf("FT = %.8x\n", 0012);
	printf("PT = %.8x\n", 0012);

	printf("TEST %d:\n", e++);
	ft_printf("FT = %*.*x\n", 8, 9, 0012);
	printf("PT = %*.*x\n", 8, 9, 0012);

	printf("TEST FAIL %d:\n", e++);
	printf("THEIR %10.2x\n", -20);
	ft_printf("MINE %10.2x\n", -20);

	printf("THEIR %10.2x\n", -38);
	ft_printf("MINE %10.2x\n", -38);

	printf("TEST %d:\n", e++);
	printf("%-10x\n", 50);
	ft_printf("%-10x\n", 50);

	printf("TEST %d:\n", e++);
	printf("%-15x\n", 0);
	ft_printf("%-15x\n", 0);

	printf("TEST %d:\n", e++);
	printf("%.1x\n", 500);
	ft_printf("%.1x\n", 500);

	printf("TEST %d:\n", e++);
	printf("%*.*x\n", 50, 10, 2);
	ft_printf("%*.*x\n", 50, 10, 2);
}

// void ft_test_address()
// {

// }

void ft_test_zero_null_values()
{
	int ret1;
	int ret2;

	printf("%50s", BLUE "[[		_________		]]\n" NONE);
	printf("%50s", BLUE "[[		Tests NULL/0		]]\n" NONE);
	printf("%50s", BLUE "[[		____etc__		]]\n" NONE);
	printf("\n\n");

	ft_printf("%02d lol %-19d he %s\n", 0, -1234, "tati");
	printf("%02d lol %-19d he %s\n", 0, -1234, "tati");

	ft_printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati");
	printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati");

	ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 9, NULL);
	ret2 = printf("Test 2 : %*.*s kiki\n", 30, 9, NULL);
	printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 2, NULL);
	ret2 = printf("Test 2 : %*.*s kiki\n", 30, 2, NULL);
	printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	printf("%.5d\n", -2372);

	ret1 = ft_printf("%p\n", NULL);
	ret2 = printf("%p\n", NULL);
	printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	ret1 = ft_printf("%15p\n", NULL);
	ret2 = printf("%15p\n", NULL);
	printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	ret1 = ft_printf("%-15p\n", NULL);
	ret2 = printf("%-15p\n", NULL);
	printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	ret1 = ft_printf("1 %.0x|\n", 0); // should ret 5 not 6
	ret2 = printf("1 %.0x|\n", 0);	  //ret 5, no display
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("2 %.0x|\n", 42);
	ret2 = printf("2 %.0x|\n", 42);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("3 %.0d|\n", 0); // same bc if nb = 0 && prec = 0
	ret2 = printf("3 %.0d|\n", 0);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("4 %15.0d|\n", 0);
	ret2 = printf("4 %15.0d|\n", 0);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("5 %2.0d|\n", 0);
	ret2 = printf("5 %2.0d|\n", 0);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("6 %.0x\n", 100);
	ret2 = printf("6 %.0x\n", 100);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("%p|\n", NULL);
	ret2 = printf("%p|\n", NULL);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("%15p\n", NULL);
	ret2 = printf("%15p\n", NULL);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	ret1 = ft_printf("%-15p\n", NULL);
	ret2 = printf("%-15p\n", NULL);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);

	char *str = "test \0\0\0 post backslash";
	ret1 = ft_printf("%10.3s|\n", str);
	ret2 = printf("%10.3s|\n", str);
	printf("\nMY RET = %d\n VS REAL RET = %d\n\n", ret1, ret2);
}

void ft_test_wildcard()
{

	printf("\n\n");
	printf("%50s", RED "[[		_________		]]\n" NONE);
	printf("%50s", RED "[[		Tests  *		]]\n" NONE);
	printf("%50s", RED "[[		_________		]]\n" NONE);
	printf("\n\n");

	int ret1;
	int ret2;

	// ret1 = ft_printf("Test 1 : %*c kiki\n", 7, 'p');
	// ret2 = printf("Test 1 : %*c kiki\n", 7, 'p');
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);
	// ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 9, "YES");
	// ret2 = printf("Test 2 : %*.*s kiki\n", 30, 9, "YES");
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 9, "ANTICONSTITUTIONNELLEMENT");
	// ret2 = printf("Test 2 : %*.*s kiki\n", 30, 9, "ANTICONSTITUTIONNELLEMENT");
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// ret1 = ft_printf("Test 3 : %*.*s kiki\n", 0, 1, "YES");
	// ret2 = printf("Test 3 : %*.*s kiki\n", 0, 1, "YES");
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// ret1 = ft_printf("Test 4 : %*.*s kiki\n", 00004, 0, "YES");
	// ret2 = printf("Test 4 : %*.*s kiki\n", 00004, 0, "YES");
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 9, "ANTICONSTITUTIONNELLEMENT");
	// ret2 = printf("Test 2 : %*.*s kiki\n", 30, 9, "ANTICONSTITUTIONNELLEMENT");
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// printf("\n NO *\n");
	// ret1 = ft_printf("Test 2 : %30.9s kiki\n", "YES");
	// ret2 = printf("Test 2 : %30.9s kiki\n", "YES");
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	int i;
	i = 1;

	// printf("\n\n");
	// printf("%50s", RED "[[		_________		]]\n" NONE);
	// printf("%50s", RED "[[		Tests  *INT		]]\n" NONE);
	// printf("%50s", RED "[[		_________		]]\n" NONE);
	// printf("\n\n");

	// ret1 = ft_printf("neg1 %*d|\n", -9, 150);
	// ret2 = printf("neg1 %*d|\n", -9, 150);
	// printf("\nTest %d: MY RET = %d|\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// printf("\n\n");
	// ret1 = ft_printf("neg2 %*.*d|\n", -9, 4, 1555);
	// ret2 = printf("neg2 %*.*d|\n", -9, 4, 1555);
	// printf("\nTest %d: MY RET = %d|\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// printf("\n\n");

	// ret1 = ft_printf("neg3 %*d|\n", -9, -255);
	// ret2 = printf("neg3 %*d|\n", -9, -255);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// printf("\n\n");
	// ret1 = ft_printf("neg4 %*.*d|\n", 0, 0, -30);
	// ret2 = printf("neg4 %*.*d|\n", 0, 0, -30);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// printf("\n\n");
	// ret1 = ft_printf("neg5 %*d|\n", -100, -589);
	// ret2 = printf("neg5 %*d|\n", -100, -589);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// printf("\n\n");
	// ret1 = ft_printf("neg6 %*d|\n", -156, 15555);
	// ret2 = printf("neg6 %*d|\n", -156, 15555);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// printf("\n\n");
	// ret1 = ft_printf("neg7 %*.*d|\n", -1586, 15, 0);
	// ret2 = printf("neg7 %*.*d|\n", -1586, 15, 0);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// ret1 = ft_printf("neg8 %*.*d|\n", -1586, 15, 300);
	// ret2 = printf("neg8 %*.*d|\n", -1586, 15, 300);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);

	// ret1 = printf("neg9 %*.*d\n", 15856, 155, -3000);
	// ret2 = ft_printf("neg9 %*.*d\n", 15856, 155, -3000);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// ret1 = printf("neg10 %*.*d\n", -15586, 15, 150);
	// ret2 = ft_printf("neg10 %*.*d\n", -15586, 15, 150);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);
	// ret1 = printf("neg11 %*.*d\n", -15586, 15, 0);
	// ret2 = ft_printf("neg11 %*.*d\n", -15586, 15, 0);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n\n", i++, ret1, ret2);

	ft_printf("FT1 :: %010%\n");
	printf("PF1 :: %010%\n"); //??? au'en faire ?
	ft_printf("FT2 :: %010as%\n");
	printf("ICI :: %010as%\n"); //??? au'en faire ?
	ft_printf("MINE %%\n");
	printf("REAL %%\n"); //??? au'en faire ?
	ft_printf("%d\n", 2147483647);
	ft_printf("%x\n", 2147483647);
	printf("%x\n", 2147483647);
	ft_printf("%X\n", 2147483647);
	printf("%X\n", 2147483647);
}

void ft_test_ret()
{

	printf("\n\n");
	printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	printf("%50s", FCYAN "[[		Valeurs retours		]]\n" NONE);
	printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	printf("\n\n");
	printf("RETOUR PRINTF %d\n", printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati"));
	ft_printf("RETOUR FT_Printf %d\n", ft_printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati"));

	printf("RETOUR PRINTF %d\n", printf("%29c", (char)-36));
	ft_printf("RETOUR FT_Printf %d\n", ft_printf("%29c", (char)-36));
	printf("RETOUR PRINTF %d\n", printf("%29c", (char)2));
	ft_printf("RETOUR FT_Printf %d\n", ft_printf("%29c", (char)2));

	char *n = "abcdefghijklmnop";
	char *o = "-a";
	char *p = "-12";
	char *q = "0";
	char *r = "%%";
	printf("real--- Return : %d\n", printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r));
	ft_printf("mine--- Return : %d\n", ft_printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r));

	printf("pp %.50d\n", 10000);
	ft_printf("pp %.50d\n", 10000);
	printf("p1 %.4s\n", "cccc");
	ft_printf("p1 %.4s\n", "cccc");
	printf("p2 %.10s\n", "cccc");
	ft_printf("p2 %.10s\n", "cccc");
	printf("p3 %.4s\n", NULL);
	ft_printf("p3 %.4s\n", NULL);
	printf("p4 %.5s\n", "aaaaa");
	ft_printf("p4 %.5s\n", "aaaaa");
	printf("p5 %.3d\n", 100);
	ft_printf("p5 %.3d\n", 100);
	printf("p6 %.0d\n", 100);
	ft_printf("p6 %.0d\n", 100);
	printf("p7 %.4d\n", 100);
	ft_printf("p7 %.4d\n", 100);
	printf("p8 %.10d\n", 100);
	ft_printf("p8 %.10d\n", 100);
	printf("p9 %.50d\n", 100);
	ft_printf("p9 %.50d\n", 100);
	printf("p10 %.1d\n", 100);
	ft_printf("p10 %.1d\n", 100);
	printf("p11 %.3d\n", 100);
	ft_printf("p11 %.3d\n", 100);
	printf("p12 %.0d\n", 0);
	ft_printf("p12 %.0d\n", 0);

	printf("ret = %d\n", printf("5chiffre 1 %0d chiffre 2 %0d|\n", 42, -42));
	ft_printf("ret = %d\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d|\n", 42, -42));
	printf("ret = %d\n", printf("6chiffre 1 %012d chiffre 2 %012d|\n", 42, -42));
	ft_printf("ret = %d\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d|\n", 42, -42));
	printf("ret = %d\n", printf("8chiffre 1 %*d chiffre 2 %*d|\n", 42, 6, 6, 6));
	ft_printf("ret = %d\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d|\n", 42, 6, 6, 6));
	printf("ret = %d\n", printf("15chiffre 1 %.d chiffre 2 %.d|\n", 42, -42));
	ft_printf("ret = %d\n", ft_printf("15chiffre 1 %.d chiffre 2 %.d|\n", 42, -42));
}

void ft_test_percent()
{
	int i;

	i = 0;

	printf("Test %d :\n", i++);
	printf("%p\n", NULL);
	printf("%p\n", NULL);
	printf("%15p\n", NULL);
	printf("%15p\n", NULL);
	printf("%-15p\n", NULL);
	printf("%-15p\n", NULL);

	printf("Test %d :\n", i++);
    printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%07d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%07d]\n", -8473));
	 printf("ret 7d = %d\n", printf("%%p::[%7d]\n", -8473));
    ft_printf("ret 7d = %d\n", ft_printf("%%p::[%7d]\n", -8473));

	printf("Test %d :\n", i++);
    printf("ret = %d\n", printf("%%p::[%10d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", -8473));

	printf("Test %d :\n", i++); //3
    printf("ret = %d\n", printf("%%p::[%.5d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", -8473));

	printf("Test %d :\n", i++);
    printf("ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
    printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", -8473));

	printf("Test %d :\n", i++);
    printf("ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
    printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", -8473));

	printf("Test %d :\n", i++);
    printf("ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
    printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", -8473));

	printf(" --- Return : %d\n", printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	ft_printf(" --- Return : %d\n", ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347

	// 	ft_printf("pp %.50d\n", 10000);
	// 	printf("pp %.50d\n", 10000);
	// ft_printf("p1 %.4s\n", "cccc");
	// ft_printf("p2 %.10s\n", "cccc");
	// ft_printf("p3 %.4s\n", NULL);
	// ft_printf("p4 %.5s\n", "aaaaa");
	// ft_printf("p5 %.3d\n", 100);
	// ft_printf("p6 %.0d\n", 100);
	// ft_printf("p7 %.4d\n", 100);
	// ft_printf("p8 %.10d\n", 100);
	// ft_printf("p9 %.50d\n", 100);
	// ft_printf("p10 %.1d\n", 100);

}

int main()
{
	int ret1;
	int ret2;



	//ft_test_char();
	ft_test_int();
//	ft_test_str();
	//ft_test_wildcard();
	//ft_test_zero_null_values();
	//ft_test_ret();
	//ft_test_hex();
	//ft_test_percent();
}
