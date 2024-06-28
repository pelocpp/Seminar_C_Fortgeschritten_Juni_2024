#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strlen
#include <ctype.h>   // isupper

// Bitfeld

struct Status1
{
    unsigned int widthValidated;
    unsigned int heightValidated;
    unsigned int positionValidated;
};

// Struktur mit Bitfeld  // Bit  Field
struct Status2
{
    unsigned int widthValidated    : 1;
    unsigned int heightValidated   : 4;
    unsigned int positionValidated : 1;
};

struct Flags
{
    unsigned char flag_01 : 1;
    unsigned char flag_02 : 1;
    unsigned char flag_03 : 1;
    unsigned char flag_04 : 1;
    unsigned char flag_05 : 1;
    unsigned char flag_06 : 1;
    unsigned char flag_07 : 1;
    unsigned char flag_08 : 1;
};

struct FlagsOhne
{
    unsigned char flag_01;
    unsigned char flag_02;
    unsigned char flag_03;
    unsigned char flag_04;
    unsigned char flag_05;
    unsigned char flag_06;
    unsigned char flag_07;
    unsigned char flag_08;
};

void bitfields()
 {
    printf("Memory size occupied by status1 : %zu\n", sizeof(struct Status1));
    printf("Memory size occupied by status2 : %zu\n", sizeof(struct Status2));

    struct Status1 s1 = { 0, 0, 0 };
    s1.positionValidated = 1;

    struct Status2 s2 = { 0, 0, 0 };
    s2.positionValidated = 0;
    s2.heightValidated = 7;   // keine Fehlermeldung
}

// ==================================

union UnionExample
{
    int   member1;
    char  member2;
    float member3;
};

union UnionExampleEx
{
    unsigned char value_bytes[4];
    int           value;
};

void unions()
 {
    // defining a union variable
    union UnionExampleEx var = { 0 };

    var.value = 0x11AA2233;

    unsigned char byte1 = var.value_bytes[0];
    unsigned char byte2 = var.value_bytes[1];
    unsigned char byte3 = var.value_bytes[2];
    unsigned char byte4 = var.value_bytes[3];
}

// =============

enum Level {
  LOW,
  MEDIUM,
  HIGH
};

enum AnotherLevel {
    Low,
    Medium
    // HIGH      // nope
};

static void enums()
{
    enum Level myVar = MEDIUM;

    switch (myVar)
    {
    case LOW:
        printf("Low Level\n");
    break;
    case MEDIUM:
        printf("Medium Level\n");
    break;
    case HIGH:
        printf("High Level\n");
    break;
    }

    printf("myVar: %d\n", myVar);
}