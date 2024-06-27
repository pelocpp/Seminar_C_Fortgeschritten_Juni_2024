// Verkettete Liste // Linked List

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "LinkedList.h"

// functions prototypes
void test_linked_list_01();
void test_linked_list_02();
void test_linked_list_03();
void test_linked_list_04();

// implementation
void test_linked_list_01()
{
	ListAnchor anchor = { NULL, 0 };

	// 1. Item
	ListItem* item1 = malloc( sizeof(ListItem) );
	item1->data = 123;
	item1->next = NULL;

	anchor.root = item1;
	anchor.count++;

	// 2. Item
	ListItem* item2 = malloc(sizeof(ListItem));
	item2->data = 456;
	item2->next = NULL;
	item1->next = item2;
	anchor.count++;

	// 3. Item
	ListItem* item3 = malloc(sizeof(ListItem));
	item3->data = 789;
	item3->next = NULL;
	item2->next = item3;
	anchor.count++;
}

void test_linked_list_02()
{
	ListAnchor anchor = { NULL, 0 };

	// 1. Item
	ListItem* item1 = malloc(sizeof(ListItem));
	item1->data = 123;
	item1->next = NULL;

	anchor.root = item1;
	anchor.count++;

	// 2. Item
	ListItem* item2 = malloc(sizeof(ListItem));
	item2->data = 456;
	item2->next = NULL;
	item1->next = item2;
	anchor.count++;

	// 3. Item
	ListItem* item3 = malloc(sizeof(ListItem));
	item3->data = 789;
	item3->next = NULL;
	item2->next = item3;
	anchor.count++;

	// =======================================

	// Liste durchlaufen

	ListItem* ptr = anchor.root;

	printf("Ausgabe: \n");

	while (ptr != NULL) {

		int n = ptr->data;
		printf("Date: %d\n", n);

		ptr = ptr->next;
	}

	printf("Ende: \n");
}

// ===========================================================

// Konzeption:

// Der Anker liegt am Stack

// insertItem 
// printList
// releaseList    // free


int contains(ListAnchor* anchor, int value)
{
	ListItem* ptr = anchor->root;

	while (ptr != NULL)
	{
		if (ptr->data == value) {
			return 1;  // 1 == true
		}

		ptr = ptr->next;
	}

	return 0;  // 0 == false
}

int count(ListAnchor* anchor)
{
	return anchor->count;
}

void insertItemAtBegin(ListAnchor* anchor, int d)
{
	// erzeuge neues Item
	ListItem* item = malloc(sizeof(ListItem));
	item->data = d;
	item->next = NULL;

	if (anchor->root == NULL) {

		// Liste ist leer
		anchor->root = item;
		anchor->count = 1;
	}
	else {

		item->next = anchor->root;
		anchor->root = item;
		anchor->count++;
	}
}

void insertItemAtBeginEx(ListAnchor* anchor, int d)
{
	// erzeuge neues Item
	ListItem* item = malloc(sizeof(ListItem));
	item->data = d;
	item->next = anchor->root;

	// update anchor
	anchor->root = item;
	anchor->count++;
}

void printList(ListAnchor* anchor)
{
	ListItem* ptr = anchor->root;

	printf("Ausgabe: \n");

	while (ptr != NULL) {

		int n = ptr->data;
		printf("Date: %d\n", n);

		ptr = ptr->next;
	}

	printf("Ende: \n");
}

void releaseList(ListAnchor* anchor)
{
	ListItem* item = anchor->root;
	ListItem* tmp;

	while (item != NULL) {

		tmp = item;

		item = tmp->next;

		free(tmp);
	}
}


void test_linked_list_03()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ListAnchor anchor = { NULL, 0 };

	insertItemAtBegin(&anchor, 1);
	insertItemAtBegin(&anchor, 2);
	insertItemAtBegin(&anchor, 3);
	insertItemAtBegin(&anchor, 4);
	insertItemAtBegin(&anchor, 5);
	insertItemAtBegin(&anchor, 6);

	printList(&anchor);

	releaseList(&anchor);
}

void test_linked_list_04()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ListAnchor anchor = { NULL, 0 };

	insertItemAtBegin(&anchor, 1);
	insertItemAtBegin(&anchor, 2);
	insertItemAtBegin(&anchor, 3);
	insertItemAtBegin(&anchor, 4);
	insertItemAtBegin(&anchor, 5);
	insertItemAtBegin(&anchor, 6);

	printList(&anchor);

	int exists = contains(&anchor, 3);
	printf("3 found: %d\n", exists);

	exists = contains(&anchor, 30);
	printf("30 found: %d\n", exists);

	releaseList(&anchor);
}

void test_linked_list()
{
	test_linked_list_04();
}
