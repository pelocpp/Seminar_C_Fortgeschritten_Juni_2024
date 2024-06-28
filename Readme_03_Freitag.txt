==================================================

Peter Loos

3. Tag: Freitag

==================================================

Hash-Tabelle

Dateien und Ein-/Ausgabe:
    OBJ-File Viewer

Funktionszeiger

Sonstiges (Bitfield, Union)

Beispiel: Dynamisch langes Feld

==> 15, 15.15

==> Nach / ab 15, 15.15.

===========================================

Array

Verkettete Liste

Hash-Tabelle

===========================================

Hash-Tabelle

== Verwaltet Elemente

== Wie:  Array, ist zunächst nicht wirklich relevant

== Suchen oder Einfügen:  Wo - Position

   IDEE:  Position: Berechnen :)

   Hash-Funktion: Wie geht das ???

https://github.com/pelocpp/c_introduction/blob/master/C_Introduction/Exercises/HashTabelle/Exercises_HashTable.md

== Schlüssel und Werten:

A) Wörterbuch:  Englisch <==> Italienisch

               Schlüssel: "Good Morning"  // Key
               Wert:      "Buongiorno"    // Value

B) Telefonbuch:

               Schlüssel: "Hans"       // Key
               Wert:      345563545    // Value

C) EMail-Dictionary:

               Schlüssel: "Susi"                 // Key
               Wert:      "susi.meier@gmx.de"    // Value


D) Für eine erste Realisierung:  // Abholstation 

               Schlüssel: 12                 // Key -Brief
               Wert:      99                 // Value: Postfach

Möglichkeit zur Umsetzung einer Hashtabelle:

2 Arrays, die nebeneinander liegen

Wie sieht in der Regel eine Hash-Funktion aus ????

A) Tabelle (Array) hat eine Länge: 

    Hier verwendet man in der Regel eine Primzahl

B)  Hash-Funktion:   Key (beliebig) ===> 0 ... Länge -1

    Länge: 7   (0, 1, ... 6)

    key ==> key % Länge

    9   => 2
    40  => 5
    7   => 0

    "Susi"  => (83 + 85 + 83 + 73) % 7

    Neues Beispiel

13 => 6
19 => 5
34 => 6
43 => 1    "Susi" => 1
92 => 1    "Hans" => 1

Detected memory leaks!
Dumping objects ->
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_09_Hashtabelle.c(67) : {84} normal block at 0x000001279441DAB0, 40 bytes long.
 Data: <Franz           > 46 72 61 6E 7A 00 FE FE FE FE FE FE FE FE FE FE 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_09_Hashtabelle.c(67) : {83} normal block at 0x000001279441DCE0, 40 bytes long.
 Data: <Anton           > 41 6E 74 6F 6E 00 FE FE FE FE FE FE FE FE FE FE 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_09_Hashtabelle.c(67) : {82} normal block at 0x000001279441DEA0, 40 bytes long.
 Data: <Sepp            > 53 65 70 70 00 FE FE FE FE FE FE FE FE FE FE FE 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_09_Hashtabelle.c(67) : {81} normal block at 0x000001279441DF10, 40 bytes long.
 Data: <Hans            > 48 61 6E 73 00 FE FE FE FE FE FE FE FE FE FE FE 
C:\Peter_Loos_C_Seminar\Seminar_C_Fortgeschritten_Juni_2024\Seminar_C_Fortgeschritten_Juni_2024\Topic_09_Hashtabelle.c(67) : {80} normal block at 0x000001279441DE30, 40 bytes long.
 Data: <Susi            > 53 75 73 69 00 FE FE FE FE FE FE FE FE FE FE FE 
Object dump complete.