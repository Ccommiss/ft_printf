#include "ft_printf.h"

int main()
{
	int ret1;
	int ret2;

	printf("\n\n");
	printf("%50s", RED "[[		_________		]]\n" NONE);
	printf("%50s", RED "[[		Tests  *		]]\n" NONE);
	printf("%50s", RED "[[		_________		]]\n" NONE);
	printf("\n\n");

	// ret1 = ft_printf("Test 1 : %*c kiki\n", 7, 'p');
	// ret2 = printf("Test 1 : %*c kiki\n", 7, 'p');
	//printf ("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);
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


	printf("\n\n");
	printf("%50s", RED "[[		_________		]]\n" NONE);
	printf("%50s", RED "	[[		Tests  *INT		]]\n" NONE);
	printf("%50s", RED "[[		_________		]]\n" NONE);
	printf("\n\n");

	// ret1 = ft_printf("neg1 %*d|\n", -9, 150);
	// ret2 = printf("neg1 %*d|\n", -9, 150);
	// printf("\nTest %d: MY RET = %d|\n VS REAL RET = %d\n", i++, ret1, ret2);
	// printf("\n\n");
	// ret1 = ft_printf("neg2 %*.*d|\n", -9, 4, 1555);
	// ret2 = printf("neg2 %*.*d|\n", -9, 4, 1555);
	// printf("\nTest %d: MY RET = %d|\n VS REAL RET = %d\n", i++, ret1, ret2);
	// printf("\n\n");

	ret1 = ft_printf("neg3 %*d|\n", -9, -255);
	ret2 = printf("neg3 %*d|\n", -9, -255);
	printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
printf("\n\n");
	ret1 = ft_printf("neg4 %*.*d|\n", 0, 0, -30);
	ret2 = printf("neg4 %*.*d|\n", 0, 0, -30);
	printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	printf("\n\n");
	ret1 = ft_printf("neg5 %*d|\n", -100, -589);
	ret2 = printf("neg5 %*d|\n", -100, -589);
	printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	printf("\n\n");
	ret1 = ft_printf("neg6 %*d|\n", -156, 15555);
	ret2 = printf("neg6 %*d|\n", -156, 15555);
	printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	printf("\n\n");
	ret1 = ft_printf("neg7 %*.*d|\n", -1586, 15, 0);
	ret2 = printf("neg7 %*.*d|\n", -1586, 15, 0);
	printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	ret1 = ft_printf("neg8 %*.*d|\n", -1586, 15, 300);
	ret2 = printf("neg8 %*.*d|\n", -1586, 15, 300);
	printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	// ret1 = printf("neg9 %*.*d\n", 15856, 155, -3000);
	// ret2 = ft_printf("neg9 %*.*d\n", 15856, 155, -3000);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	// ret1 = printf("neg10 %*.*d\n", -15586, 15, 150);
	// ret2 = ft_printf("neg10 %*.*d\n", -15586, 15, 150);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);
	// ret1 = printf("neg11 %*.*d\n", -15586, 15, 0);
	// ret2 = ft_printf("neg11 %*.*d\n", -15586, 15, 0);
	// printf("\nTest %d: MY RET = %d\n VS REAL RET = %d\n", i++, ret1, ret2);

	// printf("\n\n");
	// printf("%50s", YELLOW "[[		_________		]]\n" NONE);
	// printf("%50s", YELLOW "[[		Tests INT		]]\n" NONE);
	// printf("%50s", YELLOW "[[		_________		]]\n" NONE);
	// printf("\n\n");

	// ft_printf("Test 1: %15.9d\n", 1111); //passe
	// printf("Test 1: %15.9d\n", 1111);

	// ft_printf("Test 2: -10.9d %-10.9d|\n", 2222);
	// printf("Test 2: -10.9d %-10.9d|\n", 2222);

	// ft_printf("Test 2 bis: %10.9d PLOP\n", 2222);
	// printf("Test 2 bis: %10.9d PLOP\n", 2222);

	// ft_printf("Test 3: %3.2d\n", 3333);
	// printf("Test 3: %3.2d\n", 3333);

	// ft_printf("Test 4: %00.9d\n", -4444);
	// printf("Test 4: %00.9d\n", -4444);

	// ft_printf("Test 5: %4.8d\n", 55555555);
	// printf("Test 5: %4.8d\n", 55555555);

	// ft_printf("Test 6 (no width) -16d: %-16d <-\n", 55555555);
	// printf("Test 6 (no width) -16d: %-16d <-\n", 55555555);

	// ft_printf("Test 6 bis 16d: %16d <-\n", 55555555);
	// printf("Test 6 bis 16d: %16d <-\n", 55555555);

	// ft_printf("Test 7: %-.0d <-\n", -55);
	// printf("Test 7: %-.0d <-\n", -55);

	// ft_printf("Test 8: .6d nb neg %.6d lol %.6d\n", -425, 1234);
	// printf("Test 8: .6d nb neg %.6d lol %.6d\n", -425, 1234);

	// ft_printf("Test 9: %13.2d| he %-18s|\n", 1234, "tatidoum");
	// printf("Test 9: %13.2d| he %-18s|\n", 1234, "tatidoum");

	// printf("\n\n");
	// printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	// printf("%50s", FCYAN "[[		Tests STR		]]\n" NONE);
	// printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	// printf("\n\n");

	// //char str[4] = "tata";
	// int a = 8;
	// ft_printf("Addresse : %-18p oo\n", &a);
	// printf("Addresse : %-18p oo\n\n", &a);

	// ft_printf("%-20.2s|\n", "tati");
	// printf("%-20.2s|\n\n", "tati");
	// printf("EUH\n");

	// ft_printf("%-10d| he %s\n", -1234, "tati");
	// printf("%-10d| he %s\n", -1234, "tati");
	// ft_printf("mine=%-10d| he %s\n", 1234, "tati");
	// printf("real=%-10d| he %s\n", 1234, "tati");

	// ft_printf("mine=%13.2d| he %s\n", 1234, "tatidoum");
	// printf("real=%13.2d| he %s\n", 1234, "tatidoum");

	// printf("%50s", "Tests 0 values\n\n");

	// ft_printf("%02d lol %-19d he %s\n", 0, -1234, "tati");
	// printf("%02d lol %-19d he %s\n", 0, -1234, "tati");

	// ft_printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati");
	// printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati");

	// ft_printf("yo %s lol la vie est %s\n", "hello", "belle");
	// ft_printf("je suis un char %c kiki\n", 'p');

	// ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 9, NULL);
	// ret2 = printf("Test 2 : %*.*s kiki\n", 30, 9, NULL);
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// ret1 = ft_printf("Test 2 : %*.*s kiki\n", 30, 2, NULL);
	// ret2 = printf("Test 2 : %*.*s kiki\n", 30, 2, NULL);
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// //	printf("coucou", "ca va", "YO", "j'ai froid");

	// printf("\n\n");
	// printf("%50s", GREEN "[[		_________		]]\n" NONE);
	// printf("%50s", GREEN "[[		Tests CHAR		]]\n" NONE);
	// printf("%50s", GREEN "[[		_________		]]\n" NONE);
	// printf("\n\n");

	// ret1 = ft_printf("yo %s lol la vie est %s\n", "hello", "belle");

	// ret1 = ft_printf("Test 1 : %c kiki\n", 'p');
	// ret2 = printf("Test 1 : %c kiki\n", 'p');
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);
	// ret1 = ft_printf("Test 2 : %25c kiki\n", 'p');
	// ret2 = printf("Test 2 : %25c kiki\n", 'p');
	// printf("\n MY RET = %d\n VS REAL RET = %d\n", ret1, ret2);

	// char *n = "abcdefghijklmnop";
	// char *o = "-a";
	// char *p = "-12";
	// char *q = "0";
	// char *r = "%%";
	// printf("real--- Return : %d\n", printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r));
	// ft_printf("mine--- Return : %d\n", ft_printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r));

	// printf("\n\n");
	// printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	// printf("%50s", FCYAN "[[		Valeurs retours		]]\n" NONE);
	// printf("%50s", FCYAN "[[		_________		]]\n" NONE);
	// printf("\n\n");
	// printf("RETOUR PRINTF %d\n", printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati"));
	// ft_printf("RETOUR FT_Printf %d\n", ft_printf("%06.4d lol %-19d he %s\n", -9654321, -1234, "tati"));

	// printf("RETOUR PRINTF %d\n", printf("%29c", (char)-36));
	// ft_printf("RETOUR FT_Printf %d\n", ft_printf("%29c", (char)-36));
	// printf("RETOUR PRINTF %d\n", printf("%29c", (char)2));
	// ft_printf("RETOUR FT_Printf %d\n", ft_printf("%29c", (char)2));
}
