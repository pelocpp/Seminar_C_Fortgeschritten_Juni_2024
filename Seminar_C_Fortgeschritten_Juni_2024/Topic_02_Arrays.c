#include <stdio.h>

void test_arrays_01()
{
	int numbers[10];   // dicht aneinanderliegender Speicherbereich

	size_t anzahlBytes = sizeof(numbers);

	size_t anzahlInts = anzahlBytes / sizeof(int);

	printf("sizeof: %zu Bytes\n", anzahlBytes);
	printf("sizeof: %zu Bytes\n", anzahlInts);
}

void test_arrays_02()
{
	// Initialisierung

	int numbers1[5] = { 1, 2, 3, 4, 5 };

	// ist gleich zu

	int numbers2[] = { 1, 2, 3, 4, 5 };

	int numbers3[5] = { 1, 2, 3 };

	int numbers4[5];

	int numbers5[5] = { 1 };

	int numbers6[5] = { 0 };
}

void test_arrays_03()
{
	int numbers[5] = { 0 };

	// numbers = numbers + 1;   // das geht nicht

	// vorbelegen mit variablen Werten
	for (int i = 0; i < 5; i++) {
		*(numbers + i) = 2 * i;
	}

	// ist identisch zu

	for (int i = 0; i < 5; i++) {
		numbers[i] = 2 * i;
	}
}

void initArray( int* feld, int length )
{
	size_t anzahlBytes = sizeof(feld);
	printf("sizeof: %zu Bytes\n", anzahlBytes);

	size_t anzahlBytes2 = sizeof(*feld);
	printf("sizeof: %zu Bytes\n", anzahlBytes2);

	for (int i = 0; i < length; i++) {
		
		feld[i] = 2 * i;
		// oder
		// *(feld + i) = 2 + i;

	}
}

void test_arrays_04()
{
	int numbers[5] = { 0 };  // Es wird Speicher reserviert (Array)
	                         // Es wird ein Feld angelegt

	size_t anzahlBytes = sizeof(numbers);
	printf("sizeof: %zu Bytes\n", anzahlBytes);

	initArray(numbers, 5);
	// ist identisch zu
	initArray(& numbers[0], 5);

	int anotherNumbers[10] = { 0 };

	initArray(anotherNumbers, sizeof (anotherNumbers) / sizeof(int) );
}


void test_arrays_05()
{
    int numbers[5] = { 0 };  // Es wird Speicher reserviert (Array)
    // Es wird ein Feld angelegt

    size_t anzahlBytes = sizeof(numbers);
    printf("sizeof: %zu Bytes\n", anzahlBytes);

    initArray(numbers, 5);
    // ist identisch zu
    initArray(&numbers[0], 5);

    int anotherNumbers[10] = { 0 };

    initArray(anotherNumbers, sizeof(anotherNumbers) / sizeof(int));
}


// =============================================================================

// ===========================================================================
// DatatypesVariablesConstants.c // Datatypes, Variables and Constants
// ===========================================================================

#include <stdio.h>

void integral_datatypes()
{
    int n = 1;
    long l = -2;
    short s = 3;
    long long ll = -4;

    unsigned int ui = 1;
    unsigned long ul = 2;
    unsigned short us = 3;
    unsigned long long ull = 4;

    size_t x = 0;

    size_t width_int = sizeof(int);              // hängt von dem Zielsystem ab
    size_t width_long = sizeof(long);            // 4 oder 8
    size_t width_short = sizeof(short);          // 2 - per Definition
    size_t width_long_long = sizeof(long long);
    size_t width_size_t = sizeof(size_t);

    printf("sizeof (int):         %zu\n", width_int);
    printf("sizeof (long):        %zu\n", width_long);
    printf("sizeof (short):       %zu\n", width_short);
    printf("sizeof (long long):   %zu\n", width_long_long);
    printf("sizeof (size_t):      %zu\n", width_size_t);
    printf("\n");
}


static void unsignedRangesOfDatatypes()
{
    unsigned char      uchar = -1;
    unsigned short     ushort = -1;
    unsigned int       uint = -1;
    unsigned long      ulong = -1;
    unsigned long long ulonglong = -1;
    size_t             uint64 = -1;

    printf("Maximum Values\n");
    printf("unsigned char:        %u\n", uchar);
    printf("unsigned short:       %u\n", ushort);
    printf("unsigned int:         %u\n", uint);
    printf("unsigned long:        %u\n", ulong);
    printf("unsigned long long:   %llu\n", ulonglong);
    printf("size_t:               %zu\n", uint64);
    printf("\n");
}

static void signedRangesOfDatatypes()
{
    signed char      uchar = 0x7F;
    signed short     ushort = 0x7FFF;
    signed int       uint = 0x7FFFFFFF;
    signed long      ulong = 0x7FFFFFFF;
    signed long long ulonglong = 0x7FFFFFFFFFFFFFFF;

    printf("Maximum Values\n");
    printf("signed char:          %d\n", uchar);
    printf("signed short:         %d\n", ushort);
    printf("signed int:           %d\n", uint);
    printf("signed long:          %ld\n", ulong);
    printf("signed long long:     %lld\n", ulonglong);
    printf("\n");

    uchar = ~0x7F;
    ushort = ~0x7FFF;
    uint = ~0x7FFFFFFF;
    ulong = ~0x7FFFFFFF;
    ulonglong = ~0x7FFFFFFFFFFFFFFF;

    printf("Minumum Values\n");
    printf("signed char:          %d\n", uchar);
    printf("signed short:         %d\n", ushort);
    printf("signed int:           %d\n", uint);
    printf("signed long:          %ld\n", ulong);
    printf("signed long long:     %lld\n", ulonglong);
}

void mainDatatypesVariablesConstants()
{
    integral_datatypes();
    unsignedRangesOfDatatypes();
    signedRangesOfDatatypes();
}
