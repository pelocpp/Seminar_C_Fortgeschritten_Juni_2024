// ===========================================================================
// MultidimensionalArrays.c // Multidimensional Arrays
// ===========================================================================

#include <stdio.h>     // printf
#include <stdlib.h>    // malloc, free

#define  M        2
#define  N        3
#define  O        4

static void multidimensional_arrays_01()
{
    // Different ways to initialize two-dimensional array

    int numbers1[M][N] =  // 2, 3
    {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    int numbers2[][N] =
    {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    int numbers3[M][N] = { 1, 2, 3, 4, 5, 6 };  // 2, 3

    // traversing array using bracket notation
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("[%d][%d]: %2d   ", i, j, numbers1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // traversing array without using bracket notation (!)
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("[%d][%d]: %2d   ", i, j, *(*(numbers1 + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

static void multidimensional_arrays_02()
{
    int numbers1[M][N][O] =
    {
        {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 }
        },
        {
            { 13, 14, 15, 16 },
            { 17, 18, 19, 20 },
            { 21, 22, 23, 24 }
        }
    };

    int numbers2[M][N][4] =
    {
        1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12 , 13, 14, 15, 16 , 17, 18, 19, 20, 21, 22, 23, 24
    };

    // traversing array using bracket notation
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < O; ++k)
            {
                printf("[%d][%d][%d]: %2d   ", i, j, k, numbers1[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");

    // traversing array without using bracket notation (!)
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < O; ++k)
            {
                printf("[%d][%d][%d]: %2d   ", i, j, k, *(*(*(numbers1 + i) + j) + k));
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

// ===========================================================================

// 1) When both dimensions are available globally

static void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

static void multidimensional_arrays_03()
{
    int numbers[N][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

    print(numbers);
}

// ===========================================================================

// 2) When only the second dimension is available globally

static void printEx(int arr[][N], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

static void multidimensional_arrays_04()
{
    int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };

    printEx(numbers, 6);
}

// ===========================================================================

// 3) Using a single pointer 

static void printExEx(int* arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value = *((arr + i * n) + j);

            printf("%2d ", value);
        }
        printf("\n");
    }
}

static void multidimensional_arrays_05()
{
    int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };

    int m = 4;

    printExEx(& numbers[0][0], m, N);

    // oder 

    printExEx((int*) numbers, m, N);
}

// ===========================================================================

// 3a) Once again using a single pointer 

static void doSomething(int* arr)
{
    int value = *arr;
    printf("Value: %d\n", value);

    arr++;

    value = *arr;
    printf("Value: %d\n", value);

    arr++;

    value = *arr;
    printf("Value: %d\n", value);
}

static void multidimensional_arrays_06()
{
    int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };

    doSomething(& numbers[0][0]);

    // oder 

    doSomething((int*)numbers);
}

// ===========================================================================

// 4) Using the concept of a pointer to an array

static void printExExEx( int(*arr)[N] )
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

static void multidimensional_arrays_07()
{
    int numbers[3][N] =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    printExExEx(numbers);
}

// ===========================================================================

// 4a) Once again the concept of a pointer to an array

static void printExExExEx(int(*arr)[N], int length)
{
    for (int(*ap)[N] = arr; ap < &arr[length]; ap++)
    {
        for (int* ip = *ap; ip < &(*ap)[N]; ip++)
        {
            printf("%d ", *ip);
        }
        printf("\n");
    }
}

static void multidimensional_arrays_08()
{
    int numbers[][N] =
    {
        {  1,  2,  3 },
        {  4,  5,  6 },
        {  7,  8,  9 },
        { 10, 11, 12 },
    };

    printExExExEx(numbers, 4);
}

// ===========================================================================

// 4b) Another example using the concept of a pointer to an array

static void doSomethingExEx( int(*arr) [N] )
{
    int value = *arr[0];
    printf("Value: %d\n", value);

    arr++;

    // 2. Element in der 2. Zeile
    int* tmp = arr[0];  // *(arr + 0) == *arr
    int* tmp1 = *arr;

    tmp++;
    tmp++;
    tmp++;
    tmp++;
    value = *tmp;

    value = *arr[0];
    printf("Value: %d\n", value);

    arr++;

    value = *arr[0];
    printf("Value: %d\n", value);
}

static void multidimensional_arrays_09()
{
    int numbers[][N] =
    { 
        { 1, 2, 3 }, 
        { 4, 5, 6 },
        { 7, 8, 9 } 
    };

    doSomethingExEx(numbers);
}


// ================================================================

void mainMultidimensionalArrays()
{
    //multidimensional_arrays_01();
    //multidimensional_arrays_02();
    //multidimensional_arrays_03();
    //multidimensional_arrays_04();
    // multidimensional_arrays_05();
    //multidimensional_arrays_06();
    //multidimensional_arrays_07();
    //multidimensional_arrays_08();
    multidimensional_arrays_09();
}

// ===========================================================================
// End-of-File
// ===========================================================================