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

const

==================================================

	n = 456;
00007FF6629F2B4D  mov         dword ptr [n],1C8h  

	// vs.

	*ip = 456;    // indirekter Variablen-Zugriff
00007FF6629F2B54  mov         rax,qword ptr [ip]  
00007FF6629F2B58  mov         dword ptr [rax],1C8h  
	              // dereferenzieren

==================================================

Parameter-�bergabe:

Wie werden Parameter �bergeben ???

https://github.com/pelocpp/cpp_introduction/blob/master/Cpp_Introduction/Markdown/ParameterPassingTechniques.md

==================================================

Dennis Ritchie: C

"A programmer knows what he does"

// Robuster Programmikerung
// Sicherer Programmierung (scanf)

BEISPIEL:

"Funktion": Anzahl der Dereferenzierungen bei "int *" und "int" unterschiedlich


================================================

size_t:  Gr��e entspricht dem Akku

================================================

C: "In C gibt es keine Felder"

Feld: 

// Gr��e bestimmen:  sizeof

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

Adresse einer lokalen Variablen oder eines tempor�ren Werts ":
werte" wird zur�ckgegeben.

FEHLER // ERROR

Arrays �bergeben und zur�ckgeben:

A) Arrays �bergeben:  GEHT - mit der Anfangsadresse

B) Arrays zur�ckgeben: GEHT NICHT !!!!!!!!!!!!!!!!

// =============================================

Es ginge �HNLICH, aber eben anders:

i)  Dyn. Speicherverwaltung

ii) Mit �bergabe eines "leeren" Arrays, das im Unterprogramm gef�llt wird.

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

sizeof: Geht f�r Variablen und f�r Typen

=====================================================

memcpy:  Kopiert Speicherbereiche 
