Peter Loos

30+ Jahre

C/C++  Java C# Mobile Progr.

Back to the Roots: C/C++

a) Visual Studio 

b) Github

==================================================

a) Was sind meine Erwartungen

b) Was MUSS drin sein

c) Was muss NICHT drin sein

d) Mehrdimensionales Array

e) Eindimensionales Array

To be Done:

== const

== String-Literal versus Array.

==================================================

	n = 456;
00007FF6629F2B4D  mov         dword ptr [n],1C8h  

	// vs.

	*ip = 456;    // indirekter Variablen-Zugriff
00007FF6629F2B54  mov         rax,qword ptr [ip]  
00007FF6629F2B58  mov         dword ptr [rax],1C8h  
	              // dereferenzieren

==================================================

Parameter-Übergabe:

Wie werden Parameter übergeben ???

https://github.com/pelocpp/cpp_introduction/blob/master/Cpp_Introduction/Markdown/ParameterPassingTechniques.md

==================================================

Dennis Ritchie: C

"A programmer knows what he does"

// Robuster Programmikerung
// Sicherer Programmierung (scanf)

BEISPIEL:

"Funktion": Anzahl der Dereferenzierungen bei "int *" und "int" unterschiedlich


================================================

size_t:  Größe entspricht dem Akku

================================================

C: "In C gibt es keine Felder"

Feld: 

// Größe bestimmen:  sizeof

// Anfangsadresse ermitteln: 

   Der Name eines Felds IST DIE Anfangsadresse

Beispiel:

Zeigerarithmetik  // Pointer Arithmetic

numbers:        1024

numbers + 1:    1028   // weil int !!! ==> 4 Bytes 

numbers + 2:    102C

numbers + 3:    1030

// =============================================

VORSICHT:

Adresse einer lokalen Variablen oder eines temporären Werts ":
werte" wird zurückgegeben.

FEHLER // ERROR

Arrays übergeben und zurückgeben:

A) Arrays übergeben:  GEHT - mit der Anfangsadresse

B) Arrays zurückgeben: GEHT NICHT !!!!!!!!!!!!!!!!

// =============================================

Es ginge ÄHNLICH, aber eben anders:

i)  Dyn. Speicherverwaltung

ii) Mit Übergabe eines "leeren" Arrays, das im Unterprogramm gefüllt wird.

// =============================================

Struktur:

Zusammenfassung mehrerer Daten (unterschiedlichen Datentyps)
zu einer Einheit / zu einem "Ganzen"


Operator-Vorrang:  operator precedence

"Punkt-vor-Strich"   :)

// =====================================================

Vergleich Strukturen und Felder
===============================

Es gibt hier Asymmetrien // Ungleichheiten

Strukturen: Wertzuweisung geht

Felder:     Wertzuweisung geht nicht

// Arrays in Strukturen: Gehen, es gibt hier keine Ausnahme.

=====================================================

sizeof: Geht für Variablen und für Typen

=====================================================

memcpy:  Kopiert Speicherbereiche 

=====================================================

Systemfunktion:

Speicher anfordern: malloc  // memory allocate

Speicher freigeben: free    // memory release

C  Bibliothek:  CRT  // C-Runtime Library

Was liefert malloc zurück:

void *   Zeiger auf Nichts :-)

Antwort: void* ist ein TYPLOSER Zeiger.

VORSICHT: 


		*(feld + i) = 2 * i;
mov         eax,dword ptr [rbp+44h]  
shl         eax,1  
movsxd      rcx,dword ptr [rbp+44h]  
mov         rdx,qword ptr [feld]  
mov         dword ptr [rdx+rcx*4],eax  

		// besser:
		feld[i] = 2 * i;
mov         eax,dword ptr [rbp+44h]  
shl         eax,1  
movsxd      rcx,dword ptr [rbp+44h]  
mov         rdx,qword ptr [feld]  
mov         dword ptr [rdx+rcx*4],eax  

======================================================

Frage:

	int* feld = malloc( length * sizeof (int) );  // 5 * 4 = 20
	if (feld == NULL) {

	    printf("Habe keinen Speicher erhalten");
	}

Sollte ich bei malloc immer auf Ungleich NULL überprüfen ????

Hmmmm ....

IMHO:  

int* feld = malloc( 100000 * sizeof (int) );  // 100000 int's

Dann bitte auf NULL abfragen ...

calloc vs malloc:  calloc schreibt 0 in den Speicher.

// ==================================================

Stack vs Heap:

Stack:   Lokalen Variablen  <=== in einer Funktion vereinbart

Heap:    Für große Daten    <=== mit malloc !!!


// C++:        new // delete

// Java / C#:  new // Garbage Collector


Siehe auch

https://github.com/pelocpp/cpp_introduction/blob/master/Cpp_Introduction/Markdown/DynamicMemory.md

=========================================================

Wer gibt frei ??????????????????

NEVER:   "double free"

Beobachtung:

malloc liefert einen Pointer auf einen Speicherbereich am Heap zurück:

===>  Ownership // Besitzer:


=========================================================

Donnerstag:

== Mehrdimensionale Arrays

== Beispiel: “Jagged” Arrays

== C und objekt-orientiertes Programmieren
   Beispiel: Dynamisch langes Feld

Datenstrukturen und Algorithmen
== Verkettete Liste






