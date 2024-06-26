#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Length  10

void dynamic_memory_01()
{
	//// Array in C: FIXED SIZE !!!!
	//int numbers [5];

	//// C99  // C++ <== Standard C / NICHT C99
 //   int n = 10;  // scanf
	//int anotherNumbers[n];  // <== geht schon, aber anders
}

void dynamic_memory_02()
{
	// int vielSpeicher[100000];

    // array of variable length

	int length = 5;  // scanf

	int* feld = malloc( length * sizeof (int) );  // 5 * 4 = 20
	if (feld != NULL) {

		for (int i = 0; i < length; i++) {

			*(feld + i) = 2 * i;
			// besser:
			feld[i] = 2 * i;
		}
	}
	else {
		// KEIN Speicher verfügbar
	}

	//void* ptr;
	//ptr = ptr + 1;  // Zeigerarithmetik geht NICHT !!!

}

void dynamic_memory_03()
{
	int length = 5;  // scanf

	int* feld = malloc(length * sizeof(int));  // 5 * 4 = 20

	// .... mit dem Pointer // Speicher arbeiten

	getchar();

	free(feld);
}

// ============================================================

void tueWasMitDynamischAllokSpeicher(int* ptr, int count)
{
	for (int i = 0; i < count; i++) {
		ptr[i] =  2 * i + 1;
	}

	// free(ptr);
}

void dynamic_memory_04()
{
	int length = 50000;  // scanf

	int* feld = malloc(length * sizeof(int));  // 5 * 4 = 20

	tueWasMitDynamischAllokSpeicher(feld, length);

	free(feld);

	feld = NULL;  // best-practice, um korrekten Zugriff zu gewährleisten

	// .....

	if (feld != NULL) {
		tueWasMitDynamischAllokSpeicher(feld, length);
	}

}


void dynamic_memory()
{
	dynamic_memory_04();
}