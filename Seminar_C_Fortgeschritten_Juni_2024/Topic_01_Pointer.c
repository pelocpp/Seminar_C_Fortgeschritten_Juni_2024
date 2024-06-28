// Pointer

#include <stdio.h>

void test_pointer_01()
{
	int n = 123;

	int* ip = &n; // Adress-Operator
	              // referenzieren

	// n: 456, ohne 'n' zu verwenden
	// n = 456;

	n = 456;

	// vs.

	*ip = 456;    // indirekter Variablen-Zugriff
	              // dereferenzieren
}


void malZwei(int n)
{
	n = 2 * n;
}


void test_pointer_02()
{
	int x = 10;
	printf("x=%d\n", x);

	malZwei(x);
	printf("x=%d\n", x);
}


void malZweiEx(int* n)
{
	int tmp = *n;  // dereferenzieren zum Lesen
	tmp = 2 * tmp;
	*n = tmp;      // dereferenzieren zum Schreiben

	// oder

	*n = *n * 2;
}

void test_pointer()
{
	int x = 10;
	printf("x=%d\n", x);

	malZweiEx(&x);
	printf("x=%d\n", x);
}

// Ende.
