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