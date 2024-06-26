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
