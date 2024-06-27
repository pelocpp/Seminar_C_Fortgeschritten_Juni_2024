
==================================================

Peter Loos

2. Tag: Donnerstag

==================================================

Donnerstag:

== Mehrdimensionale Arrays

== Beispiel: “Jagged” Arrays

== C und objekt-orientiertes Programmieren
   Beispiel: Dynamisch langes Feld

Datenstrukturen und Algorithmen
== Verkettete Liste

==================================================

Grammatik:

KEINE Mehr-Dim. Felder

Array of Array

Beschreibung:

https://github.com/pelocpp/c_introduction/blob/master/C_Introduction/Tutorial/MultidimensionalArrays/MultidimensionalArrays.md

==================================================


Pascal'sches Dreieck:

A) Ein Unterprogramm Pascal

    int pascal[10][10] =  { 0 };

B) computePascal (pascal); 

C) printPascal (pascal);


==================================================

Verkettete Listen:

https://github.com/pelocpp/c_introduction/blob/master/C_Introduction/Exercises/VerketteteListe/Exercises_VerketteteListe.md

==================================================

Memory Leaks:   Fehlende free's !!!

https://github.com/pelocpp/c_introduction/blob/master/C_Introduction/Markdown/MemoryLeaksDetection.md

Siehe hier - geht aber nur für Visual C / C++

Detected memory leaks!
Dumping objects ->
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_06_LinkedList.c(118) : {85} normal block at 0x000002B3F1CDD290, 16 bytes long.
 Data: <                > 06 00 00 00 CD CD CD CD F0 D1 CD F1 B3 02 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_06_LinkedList.c(118) : {84} normal block at 0x000002B3F1CDD1F0, 16 bytes long.
 Data: <        p       > 05 00 00 00 CD CD CD CD 70 D4 CD F1 B3 02 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_06_LinkedList.c(118) : {83} normal block at 0x000002B3F1CDD470, 16 bytes long.
 Data: <        P       > 04 00 00 00 CD CD CD CD 50 D6 CD F1 B3 02 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_06_LinkedList.c(118) : {82} normal block at 0x000002B3F1CDD650, 16 bytes long.
 Data: <        `       > 03 00 00 00 CD CD CD CD 60 D5 CD F1 B3 02 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_06_LinkedList.c(118) : {81} normal block at 0x000002B3F1CDD560, 16 bytes long.
 Data: <                > 02 00 00 00 CD CD CD CD B0 D5 CD F1 B3 02 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_06_LinkedList.c(118) : {80} normal block at 0x000002B3F1CDD5B0, 16 bytes long.
 Data: <                > 01 00 00 00 CD CD CD CD 00 00 00 00 00 00 00 00 
Object dump complete.


==================================================

warning C4715: "contains": Nicht alle Codepfade geben einen Wert zurück.

==================================================

Emfehlung // Hinweis: 

Keine C / C++ Installation

Online C / C++ Compiler

Beispiel:

https://wandbox.org/

====================================================

C und objekt-orientiertes Programmieren

Objekt-Orientierung:

==> Klassen:  Daten und Methoden (Funktionen)

C:  Keine Klassen, aber Strukturen

==> Möglichkeit:

    In C mit einem objekt-orientierten "Touch" programmieren.

==> Strukturierung eines C-Programms

Strukturen --> DATEN

Funktionen: Auf der anderen Seite, die mit den / der Struktur zusammenarbeiten !!!

Strukturen und Funktionen, die auf dieser Struktur arbeiten:

Funktionen haben einen Parameter dieser "Struktur"

Wo: Header-File

// =============================================================

Felder , bei denen die einzelnen Zeilen (Rows) unterschiedlich lang sind.

Zackiges / Gezacktes Feld.

"Jagged Array"

Beispiel:  Graphentheorie // Anzahl / Beschreibung der Nachbarknoten

AChtung:

Detected memory leaks!
Dumping objects ->
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {90} normal block at 0x00000194047DDB90, 40 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {89} normal block at 0x00000194047DFE90, 36 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {88} normal block at 0x00000194047DC8D0, 32 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {87} normal block at 0x00000194047DC870, 28 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {86} normal block at 0x00000194047DCC30, 24 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {85} normal block at 0x00000194047DD3F0, 20 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {84} normal block at 0x00000194047DD670, 16 bytes long.
 Data: <                > 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {83} normal block at 0x00000194047DD3A0, 12 bytes long.
 Data: <            > 01 00 00 00 02 00 00 00 03 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {82} normal block at 0x00000194047DD710, 8 bytes long.
 Data: <        > 01 00 00 00 02 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(75) : {81} normal block at 0x00000194047D51F0, 4 bytes long.
 Data: <    > 01 00 00 00 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_07_JaggedArray.c(70) : {80} normal block at 0x00000194047D5160, 80 bytes long.
 Data: < Q}       }     > F0 51 7D 04 94 01 00 00 10 D7 7D 04 94 01 00 00 
Object dump complete.


Frage:

Wie weiß ich bei einem "Jagged Array", wie lange die
einzelnen Zeilen sind ?

Ich weiß es nicht !

Lösung:

Eigentlich hilft da nur ein ZWEITES Array,
in dem die Längen pro Zeile drin steht.

===========================================

# Hashtag  // Kanalgitter

Zeilen, die mit # anfangen:

C Compiler NICHT ZU SEHEN:

==>  Präprozessor:   Textersetzung

