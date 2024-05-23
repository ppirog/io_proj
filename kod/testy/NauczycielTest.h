//
// Created by ola on 19.05.2024.
//

#ifndef IO_PROJ_NAUCZYCIELTEST_H
#define IO_PROJ_NAUCZYCIELTEST_H

#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <iostream>
#include "Uzytkownik.h"
#include "Wydzial.h"
#include "Nauczyciel.h"
#include "Student.h"
#include "System.h"
#include "Kurs.h"


using namespace std;

class Uzytkownik;
class Wydzial;
class Nauczyciel;
class Student;
class Kurs;
class System;

class NauczycielTest {
public:
    void runTests();
    NauczycielTest();
private:
    void testDodajKurs();
    void testUsunKurs();
    void testDodajWydzial();
    void testUsunWydzial();
    void testGetWydzialy();
    void testGetProwadzoneKursy();
};

void NauczycielTest::runTests() {
    testDodajKurs();
    testUsunKurs();
    testDodajWydzial();
    testUsunWydzial();
    testGetWydzialy();
    testGetProwadzoneKursy();
}



void NauczycielTest::testDodajKurs() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    nauczyciel.dodajKurs(&kurs);
    assert(nauczyciel.getProwadzoneKursy().size() == 1);
    assert(nauczyciel.getProwadzoneKursy()[0] == &kurs);
}

void NauczycielTest::testUsunKurs() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    nauczyciel.dodajKurs(&kurs);
    nauczyciel.usunKurs(&kurs);
    assert(nauczyciel.getProwadzoneKursy().size() == 0);
    assert(nauczyciel.getProwadzoneKursy().size() != 2);
}

void NauczycielTest::testDodajWydzial() {
    Wydzial wydzial("Informatyka");
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    nauczyciel.dodajWydzial(&wydzial);
    assert(nauczyciel.getWydzialy().size() == 1);
    assert(nauczyciel.getWydzialy()[0] == &wydzial);
}

void NauczycielTest::testUsunWydzial() {
    Wydzial wydzial("Informatyka");
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    nauczyciel.dodajWydzial(&wydzial);
    nauczyciel.usunWydzial(&wydzial);
    assert(nauczyciel.getWydzialy().size() == 0);
}

void NauczycielTest::testGetWydzialy() {
    Wydzial wydzial1("Informatyka");
    Wydzial wydzial2("Matematyka");
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    nauczyciel.dodajWydzial(&wydzial1);
    nauczyciel.dodajWydzial(&wydzial2);
    assert(nauczyciel.getWydzialy().size() == 2);
    assert(nauczyciel.getWydzialy()[0] == &wydzial1);
    assert(nauczyciel.getWydzialy()[1] == &wydzial2);
}

void NauczycielTest::testGetProwadzoneKursy() {
    Wydzial wydzial("Informatyka");
    Kurs kurs1("Programowanie", &wydzial);
    Kurs kurs2("Algorytmy", &wydzial);
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    nauczyciel.dodajKurs(&kurs1);
    nauczyciel.dodajKurs(&kurs2);
    assert(nauczyciel.getProwadzoneKursy().size() == 2);
    assert(nauczyciel.getProwadzoneKursy()[0] == &kurs1);
    assert(nauczyciel.getProwadzoneKursy()[1] == &kurs2);
}

NauczycielTest::NauczycielTest() {
    runTests();
    cout << "Nauczyciel tests passed" << endl;
}



#endif //IO_PROJ_NAUCZYCIELTEST_H
