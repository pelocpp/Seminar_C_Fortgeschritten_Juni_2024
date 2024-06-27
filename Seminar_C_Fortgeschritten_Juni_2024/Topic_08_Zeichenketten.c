// Zeichenketten

// #define _CRT_SECURE_NO_WARNINGS

#define Max   123.456   // Zeichenkette

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Workarounds

void test_input()
{
	//// Scanf
	//int n;

	//scanf_s("%d", &n, sizeof(n));
	//printf("n=%d\n", n);

	//scanf_s("%d", &n, sizeof(n));
	//printf("n=%d\n", n);
}

void test_input_02()
{
	//// Scanf
	//char buffer[6];

	//printf("6 Zeichen:\n");

	//scanf("%6s", buffer);
	//printf("s=%s\n", buffer);

	//scanf("%6s", buffer);
	//printf("s=%s\n", buffer);
}

void test_input_03()
{
	//// Scanf
	//int n;

	//char* response = NULL;
	//size_t len;

	//size_t numReadChars;

	//// nicht Visual C
	//// numReadChars = getline(&response, &len, stdin);

	//char* fgets(
	//	char* str,
	//	int numChars,
	//	FILE * stream
	//);
}

// -1, if failure
int readSingleNumber()
{
	// eine int-Zahl einlesen

	char buffer[128];

	// Zeile von der Eingabe einlesen
	fgets(buffer, sizeof(buffer), stdin);

	// Länge der Eingabe bestimmen
	size_t nReadChars = strlen(buffer);

	// das '\n' von der Eingabe entfernen
	buffer[nReadChars - 1] = '\0';

	// Länge korrigieren
	nReadChars--;

	// verify input
	for (int i = 0; i < nReadChars; i++) {

		if (!isdigit(buffer[i])) {
			printf("Falsche Eingabe!");
			return -1;
		}
	}

	// Eingabe nach int umwandeln
	int n;

	n = atoi(buffer);

	return n;
}

// success == 0 ==> FEHLER
int readSingleNumberEx(int* success)
{
	*success = 0;  // wir gehen von einer falschen Eingabe aus

	// eine int-Zahl einlesen
	char buffer[128];

	// Zeile von der Eingabe einlesen
	fgets(buffer, sizeof(buffer), stdin);

	// Länge der Eingabe bestimmen
	size_t nReadChars = strlen(buffer);

	// das '\n' von der Eingabe entfernen
	buffer[nReadChars - 1] = '\0';

	// Länge korrigieren
	nReadChars--;

	int start = 0;

	if (buffer[0] == '-') {
		start = 1;
	}

	// verify input
	for (int i = start; i < nReadChars; i++) {

		if (!isdigit(buffer[i])) {
			printf("Falsche Eingabe!");
			return -1;
		}
	}

	// Eingabe nach int umwandeln
	int n;

	n = atoi(buffer);

	*success = 1;

	return n;
}


void test_input_04()
{
	int n;

	int success = 0;

	n = readSingleNumberEx(&success);

	if (success != 0) {
		printf("n = %d\n", n);
	}
	else
	{
		printf("Fehler in der Eingabe\n");
	}
}

void test_input_05()
{
	// eine int-Zahl einlesen
	char buffer[128];

	// Zeile von der Eingabe einlesen
	fgets(buffer, sizeof(buffer), stdin);

	// Länge der Eingabe bestimmen
	size_t nReadChars = strlen(buffer);

	// das '\n' von der Eingabe entfernen
	buffer[nReadChars - 1] = '\0';

	// Eingabe nach int umwandeln
	int n = 0;

	n = atoi(buffer);

	printf("n = %d\n", n);
}

void test_input_06()
{
	// strcpy 
	// 
	// char* strcpy(char* destination, const char* source);

	const char* src = "Source";

	// Literal == Konstante

	double d = Max * 2.0;

	char* dst = "Destination";   // String Literal ==> "Read-Only" Bereich 
	// versus
	char dst2 [100] = "Destination";
	
	char* dst3 = malloc(100 * sizeof (char));

	// strcpy_s(dst2, sizeof (dst2), src);  korrekt
	strcpy_s(dst3, 100 * sizeof(char), src);

	printf("Ende: %s\n", dst3);

	free(dst3);
}

void test_input_07()
{
	int n = 123;

	int* ip;
	int** ipp;
	int*** ippp;
	int**** ipppp;
	int***** ippppp;

	ip = &n;
	ipp = &ip;
	ippp = &ipp;
	ipppp = &ippp;
	ippppp = &ipppp;

	*ip = 456;

	*****ippppp = 789;
}


void test_strings()
{
	test_input_07();
}

