// Jagged Array 
#define _CRTDBG_MAP_ALLOC


#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void print_jagged_array_01(int** ptr, int len)
{
	for (int i = 0; i < len; i++) {

		int* tmp = ptr[i];

		// nur weil Pascal Dreieck : i-te Zeile hat i+1 Elemente 
		for (int k = 0; k <= i; k++) {
			printf("%d   ", tmp[k]);
		}
		printf("\n");
	}
}

void jagged_array_01()
{
	// Simulation: Pascal-Dreieck mit 6 Zeilen

	int* row1 = malloc(sizeof(int) * 1);
	row1[0] = 1;

	int* row2 = malloc(sizeof(int) * 2);
	row2[0] = 1;
	row2[1] = 1;

	int* row3 = malloc(sizeof(int) * 3);
	row3[0] = 1;
	row3[1] = 2;
	row3[2] = 1;

	int* row4 = malloc(sizeof(int) * 4);
	row4[0] = 1;
	row4[1] = 2;
	row4[2] = 2;
	row4[3] = 1;

	int* row5 = malloc(sizeof(int) * 5);
	row5[0] = 1;
	row5[1] = 2;
	row5[2] = 4;
	row5[3] = 2;
	row5[4] = 1;

	int* row6 = malloc(sizeof(int) * 6);
	row6[0] = 1;
	row6[1] = 2;
	row6[2] = 4;
	row6[3] = 4;
	row6[4] = 2;
	row6[5] = 1;

	int* jagged_array[6] = { row1, row2, row3, row4, row5, row6 };

	print_jagged_array_01(jagged_array, 6);
}




int** create_jagged_array(int rows)
{
	int** array = malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {

		// die einzelnen Zeilen allokieren
		int* tmp = malloc((i + 1) * sizeof(int));
		for (int k = 0; k < (i + 1); k++ ) {
			tmp[k] = k + 1;
		}

		array[i] = tmp;
	}

	return array;
}

void print_jagged_array(int** array, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k <= i; k++) {

			// printf("%d   ", array[i][k]);
			// oder
			printf("%d   ", (*(array + i)) [k]);
		}
		printf("\n");
	}
}

void release_jagged_array(int** array, int rows)
{
	// die einzelnen Zeilen freigeben
	for (int i = 0; i < rows; i++)
	{
		free(array[i]);
	}

	// das Feld mit den Zeigern freigeben
	free(array);
}


void jagged_array_02()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int** myArray = create_jagged_array(10);

	print_jagged_array(myArray, 10);

	release_jagged_array(myArray, 10);
}


void was_schmutziges()
{
	int* ptr = malloc(6 * sizeof (int));  // 24

	printf("Anzahl Bytes: %d\n", sizeof (ptr));
	printf("Anzahl Bytes: %d\n", ptr[-1]);
	printf("Anzahl Bytes: %d\n", ptr[-2]);
	printf("Anzahl Bytes: %d\n", ptr[-3]);
	printf("Anzahl Bytes: %d\n", ptr[-4]);
}

void jagged_array()
{
	was_schmutziges();
}