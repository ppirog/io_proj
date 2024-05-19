//
// Created by ola on 19.05.2024.
//

#include "testy/WydzialTest.h"
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


void WydzialTest::runTests() {
    testDodajNauczyciela();
    testUsunNauczyciela();
    testDodajKurs();
    testUsunKurs();
    testGetNazwa();
}

void WydzialTest::testDodajNauczyciela() {
    Wydzial wydzial("Informatyka");
    Nauczyciel nauczyciel1("Jan", "Kowalski");
    wydzial.dodajNauczyciela(&nauczyciel1);
    assert(wydzial.getNauczyciele().size() == 1);
    assert(wydzial.getNauczyciele()[0] == &nauczyciel1);
}

void WydzialTest::testUsunNauczyciela() {
    Wydzial wydzial("Informatyka");
    Nauczyciel nauczyciel1("Jan", "Kowalski");
    wydzial.dodajNauczyciela(&nauczyciel1);
    wydzial.usunNauczyciela(&nauczyciel1);
    assert(wydzial.getNauczyciele().size() == 0);
}

void WydzialTest::testDodajKurs() {
    Wydzial wydzial("Informatyka");
    Kurs kurs1("Programowanie");
    wydzial.dodajKurs(&kurs1);
    assert(wydzial.getKursy().size() == 1);
    assert(wydzial.getKursy()[0] == &kurs1);
}

void WydzialTest::testUsunKurs() {
    Wydzial wydzial("Informatyka");
    Kurs kurs1("Programowanie");
    wydzial.dodajKurs(&kurs1);
    wydzial.usunKurs(&kurs1);
    assert(wydzial.getKursy().size() == 0);
}

void WydzialTest::testGetNazwa() {
    Wydzial wydzial("Informatyka");
    assert(wydzial.getNazwa() == "Informatyka");
}


int main() {
    WydzialTest tests;
    tests.runTests();
    return 0;
}
