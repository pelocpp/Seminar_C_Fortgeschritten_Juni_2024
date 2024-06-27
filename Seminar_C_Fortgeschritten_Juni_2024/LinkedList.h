// Linked List

#pragma once

// =========================================
// defines

// =========================================
// types (structs)

// Rekursive Definition
struct list_item
{
	int               data;   // Daten eines Knotens
	struct list_item* next;   // Zeiger auf das nächste List Item
};

typedef struct list_item ListItem;

// Anker // Erstes Element // Root // Wurzel
struct list_anchor
{
	ListItem* root;
	int       count;
};

typedef struct list_anchor ListAnchor;


// =========================================
// functions (methods)

void insertItemAtBegin   (ListAnchor* anchor, int data);
void insertItemAtBeginEx (ListAnchor* anchor, int data);
void printList           (ListAnchor* anchor);
void releaseList         (ListAnchor* anchor);
int contains             (ListAnchor* anchor, int value);
int count                (ListAnchor* anchor);
