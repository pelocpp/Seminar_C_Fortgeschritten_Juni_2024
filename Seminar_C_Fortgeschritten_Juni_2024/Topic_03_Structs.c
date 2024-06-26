#include <stdio.h>
#include <string.h>

struct student
{
	char firstname[32];
	char lastname[32];
	int age;
};

struct time
{
	int hours;
	int minutes;
	int seconds;
};

typedef struct time Time;

void printTime(Time* t)
{
	printf("Uhrzeit: %02d:%02d:%02d\n",
		t->hours, t->minutes, t->seconds);
}

void printTimeRevised(const Time * const t)  // lesenden Zugriff
{
	// t->seconds = 999;  // falsch
	// t = t + 1;   // komplett falsch

	printf("Uhrzeit: %02d:%02d:%02d\n",
		t->hours, t->minutes, t->seconds);
}

void printTimeEx(Time* t, int index)
{
	printf("Uhrzeit: %02d:%02d:%02d\n",
		t[index].hours, t[index].minutes, t[index].seconds);
}

void resetTime(Time* t)
{
	//t.hours = 0;
	//t.minutes = 0;
	//t.seconds = 0;

	(*t).hours = 0;
	(*t).minutes = 0;
	(*t).seconds = 0;

	// ist identisch zu 

	t->hours = 0;
	t->minutes = 0;
	t->seconds = 0;
}

Time mittagspause()
{
	Time mittags = { 12, 0, 0 };

	//struct time mittags = { 0, 0, 0 };
	//mittags.hours = 12;
	//mittags.minutes = 15;
	//mittags.seconds = 15;

	return mittags;
}

void test_structs_01()
{
	Time now = { 13, 37, 0 };
	printTime(&now);

	resetTime(&now);
	printTime(&now);
}

void test_structs_02()
{
	Time now = { 13, 37, 0 };
	Time than = { 15, 15, 0 };

	Time uhrzeiten1[2] = { now, than };
	// ebenso:
	Time uhrzeiten2[2] = { { 13, 37, 0 },  { 15, 15, 0 } };

	for (int i = 0; i < 2; i++) {

		int hours = uhrzeiten1[i].hours;
		// uhrzeiten1[i].hours = 14;
	}

	for (int i = 0; i < 2; i++) {
		printTime(&uhrzeiten1[i]);
	}

	int groesseStruktur = sizeof(Time);

	printTimeEx(uhrzeiten1, 0);
	printTimeEx(uhrzeiten1, 1);
	printTimeEx(uhrzeiten1, 2000);
}

// ==============================================================

struct zahlen
{
	int numbers[5];
};

typedef struct zahlen Zahlen;

void test_structs_03()
{
	// Ein Vergleich

	Time now = { 13, 37, 0 };
	Time copy = { 0, 0, 0};

	copy = now;  // Wertzuweisung

	// ------------------------

	int numbers[5] = { 1, 2, 3, 4, 5 };
	int copyArray[5] = { 0 };

	// copyArray = numbers;    // Wertzuweisung: NEIN

	//for (int i = 0; i < 5; i++) {
	//	copyArray[i] = numbers[i];
	//}

	// ODER
	// void * memcpy (void * bis , const void * von , size_t numBytes );

	memcpy(copyArray, numbers, sizeof (numbers));

	// ------------------------

	Zahlen zahlen = { { 1, 2, 3, 4, 5 } };
	Zahlen zahlenCopy = { { 0 } };

	// zahlenCopy = zahlen;
	// oder memcpy
	memcpy(&zahlenCopy, &zahlen, sizeof(Zahlen));

	// ---------------------------------

	int wert = 123;

	int kopie = 0;

	// kopie = wert;

	memcpy(&kopie, &wert, sizeof(int));
}


void test_structs_04()
{
	Time wannIstMittag = { 0, 0, 0 };

	wannIstMittag = mittagspause();

	printTime(&wannIstMittag);
}

void test_structs()
{
	Time now = { 15, 21, 0 };

	printTimeRevised(&now);
}

