// Hashtabelle

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // malloc
#include <ctype.h>
#include <crtdbg.h>

#define   TableLength    7

// Name, Telefonnummer  "Susi" ===> 5434543

struct entry
{
	char          name[20];   // Schlüssel // Key // Name
	// vs
	// char*         name2;   // NEIN - siehe Kommentar weiter unten

	size_t        number;     // Value // Wert //   Telefonnummer

	struct entry* next;       // Kollisionsauflösung mit Verkettung
};

typedef struct entry Entry;

// Hash-Tabelle ( globale Variable)
Entry* table[TableLength] = { NULL };

// =====================================================================
// 
// Hash-Funktion
// Beispiel: "Susi"  ==> 0 ... TableLength-1  (0 .. 6)
// size_t hash_function(char name[])
size_t hash_function(char* name)
{
	// Algorithmus: "SUSI"  => (83 + 85 + 83 + 73) % 7

	size_t result = 0;

	while ( *name != '\0') {

		// ASCII Codes aufsummieren
		result = result + *name;

		name++;
	}

	// Summe auf gültigen Tabellenindex abhacken
	result = result % TableLength;

	return result;
}

// =====================================================================
// 
// insert

// Name, Tel.Nummer
void insert(char* name, size_t number)
{
	// A) Index in Tabelle berechnen
	size_t index = hash_function(name);

	// B) Einen Eintrag anlegen - auf dem Heap
	Entry* entry = malloc(sizeof (Entry));

	if (entry != NULL) {

		// C) Eintrag füllen
		//    i) Der Name ist zu kopieren
		//    ii) Wir dürfen den Zeiger 'name' NICHT direkt abspeichern,
		//        weil wir NICHT der Besitzer sind.
		//        Eine andere Funktion stellt ein Literal, einen Puffer, einen malloc-Bereich bereit
		//        Das wissen wir nicht !!!

		// 2. Problem: Was ist, wenn der Name LÄNGER 
		// als 20 Zeichen ist ????????????????
		// i) Muss Länge überprüfen und ABSCHNEIDEN
		// ii) Muss HIER mit malloc einen neuen Speicher dyn. allokieren
		//     (IN DER TABELLE) und wieder den Namen umkopieren.

		// Schlüssel
		strcpy_s(entry->name, sizeof (entry->name), name);

		// Wert
		entry->number = number;

		// Next-Zeiger auf NULL setzen
		entry->next = NULL;

		// Struktur entry in die Tabelle einfügen
		if (table[index] == NULL) {

			table[index] = entry;
		}
		else {
			// Habe Kollision, muss Eintrag am Ende der Liste einfügen

			// A) Suche Ende der Liste
			Entry* tmp = table[index];
			while (tmp->next != NULL) {

				tmp = tmp->next;
			}

			// B) Neuen Eintrag am Ende der Liste einfügen
			tmp->next = entry;
		}
	}
}

// =====================================================================
// 
// search

// 0 == Nicht gefunden
size_t search(char* name)
{
	// A) Bestimme Index
	int index = hash_function(name);

	// B) Suche an dieser Stelle den Eintrag
	Entry* entry = table[index];

	while (entry != NULL) {

		// C) Namen vergleichen
		if (strcmp(name, entry->name) == 0) {

			// D) Eintrag gefunden - liefere Nummer zurück
			return entry->number;
		}
		else {

			// E) Gehe in dieser Liste / Zeile zum nächsten Eintrag
			entry = entry->next;
		}
	}

	// Name wurde nicht gefunden
	return 0;
}

// =====================================================================
// 
// printTable

void printTable()
{
	for (int i = 0; i < TableLength; i++) {

		Entry* entry = table[i];

		while (entry != NULL)
		{
			printf("Index: %2d: Name: %10s: Number: %zu\n", i, entry ->name, entry->number);

			entry = entry->next;
		}
	}
}

void releaseHashTable()
{
	for (int i = 0; i < TableLength; i++)
	{
		Entry* entry = table[i];

		while (entry != NULL) {

			Entry* tmp = entry;

			entry = entry->next;

			free(tmp);
		}
	}
}

// =====================================================================
// Testrahmen

void test_hash_table()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//size_t index;
	//index = hash_function("Susi");
	//printf("Index: %zu\n", index);

	//index = hash_function("Hans");
	//printf("Index: %zu\n", index);

	//index = hash_function("Sepp");
	//printf("Index: %zu\n", index);

	//index = hash_function("Anton");
	//printf("Index: %zu\n", index);

	//index = hash_function("Franz");
	//printf("Index: %zu\n", index);

	insert("Susi", 12345);
	insert("Hans", 54321);
	insert("Sepp", 33333);
	insert("Anton", 44444);
	insert("Franz", 55555);

	printTable();

	size_t number = search("Peter");
	printf("Peter -> %zu\n", number);

	number = search("Sepp");
	printf("Sepp -> %zu\n", number);

	releaseHashTable();
}



void test_hash_table_01()
{
	size_t index = hash_function("SUSI");

	// Welche Möglichkeiten gibt es , insert aufzurufen ???
	insert("Susi", 12345);

	// Namen einlesen
	char buffer[20];
	// fgets();
	insert(buffer, 12345);

	// 2. Namen einlesen
	// fgets();
	insert(buffer, 12345);

	char* buffer2 = malloc(20);
	// buffer2 füllen, das geht auch mit fgets();
	insert(buffer2, 4332);

	free(buffer2);
}