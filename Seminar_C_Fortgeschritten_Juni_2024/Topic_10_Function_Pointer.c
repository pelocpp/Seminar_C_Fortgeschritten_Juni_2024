
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 

// A normal function with an int parameter 
// and void return type 

void function(int a)
{
	printf("Value of a is %d\n", a);
}

// Prototyp:
void function(int a);

void test_function_pointer_01 ()
{
	// Zeiger einer Funktion // Adresse einer Funktion
	void (*fp)(int a);
	fp = function;

	// oder
	void (*fp1)(int a) = function;

	(*fp1)(123);

	// fun_ptr is a pointer to function fun() 
	void (*fun_ptr) (int) = &function;

	// Invoking fun() using fun_ptr 
	(*fun_ptr)(10);
}

// ===========================================================

void add(int a, int b)
{
	printf("Addition is %d\n", a + b);
}

void sub(int a, int b)
{
	printf("Subtraction is %d\n", a - b);
}

void mul(int a, int b)
{
	printf("Multiplication is %d\n", a * b);
}

void div (int a, int b)
{
	printf("Division is %d\n", a / b);
}

void test_function_pointer_02()
{
	void (*fp)(int);

	// fun_ptr_arr is an array of function pointers 

	// Jump Table

	void (* (fun_ptr_arr[])) (int, int) = 
	{
		add, sub, mul, div 
	};

	(*fun_ptr_arr[0])(13, 11);
}

void test_function_pointer()
{
	test_function_pointer_01();
	test_function_pointer_02();
}
