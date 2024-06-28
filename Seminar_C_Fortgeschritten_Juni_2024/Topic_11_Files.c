#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strlen
#include <ctype.h>   // isupper

// Schreiben
void test_files_01()
{
	FILE* fp;

	fp = fopen("NameDerDatei.txt", "w");

	if (fp != NULL) {

		char* s = "Erste Zeile\n";

		fwrite(s, 1, strlen(s), fp);
		fwrite(s, 1, strlen(s), fp);
		fwrite(s, 1, strlen(s), fp);

		fclose(fp);
	}
	else
	{
		printf("Fehler\n");
	}

	printf("Fertig.");
}

// Lesen
void test_files_02()
{
	FILE* fp;

	fp = fopen("Topic_01_Pointer.c", "r");

	if (fp != NULL) {

		int lineNumber = 1;

		while (!feof(fp))
		{
			char buffer[1024] = { '\0' };

			fgets(buffer, 1024, fp);  // liest nur 1 Zeile
			// fread(...);

			// habe ich etwas gelesen ???
			if (buffer[0] == '\0') {
				break;
			}

			printf("%03d: %s", lineNumber, buffer);
			lineNumber++;
		}

		fclose(fp);
	}
	else
	{
		printf("Fehler\n");
	}

	printf("Fertig.");
}

// =========================================================

// Statistik:

// Häufigkeit der Buchstabe in einer Quelldatei:

// a..z oder A..Z

void test_files()
{
	int haeufigkeit[26] = { 0 };

	FILE* fp;

	fp = fopen("Topic_01_Pointer.c", "r");

	if (fp != NULL) {

		int lineNumber = 1;

		while (!feof(fp))
		{
			char buffer[1024] = { '\0' };

			fgets(buffer, 1024, fp);  // liest nur 1 Zeile
			// fread(...);

			// habe ich etwas gelesen ???
			if (buffer[0] == '\0') {
				break;
			}

			// '\0' ==> 0
			// 0    ==> 0
			// '0'  ==> 48

			// Buchstaben zählen
			int pos = 0;
			while (buffer[pos] != '\0') {

				char ch = buffer[pos];

				if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
				{
					// ch ==> Index für Tabelle haeufigkeit
					if (isupper(ch)) {

						int index = ch - 'A'; // B: 66 - 65 = 1
						haeufigkeit[index]++;
					}
					else  {

						int index = ch - 'a';
						haeufigkeit[index]++;
					}
				}

				++pos;
			}

			printf("%03d: %s", lineNumber, buffer);
			lineNumber++;
		}

		fclose(fp);
	}
	else
	{
		printf("Fehler\n");
	}

	printf("Fertig Lesen.\n\n");

	printf("Haefigkeiten:\n\n");

	for (int i = 0; i < 26; i++) {

		printf("%c: %3d\n", 'a' + i, haeufigkeit[i]);
	}
}