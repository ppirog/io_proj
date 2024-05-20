//
// Created by ola on 19.05.2024.
//

#include "KursTest.h"
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

void KursTest::runTests() {
    testDodajNauczyciel();
    testDodajMaterialy();
    testDodajStudenta();
    testUsunMaterial();
    testSetIGetNazwa();
    testGetNauczyciele();
    testGetStudenci();
}


void KursTest::testDodajNauczyciel() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    kurs.dodajNauczyciel(&nauczyciel);
    assert(kurs.getNauczyciele().size() == 1);
    assert(kurs.getNauczyciele()[0] == &nauczyciel);
}

void KursTest::testDodajMaterialy() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    kurs.dodajMaterialy("Wstep", "Podstawy programowania");
    assert(kurs.getMaterialy().size() == 1);
    assert(kurs.getMaterialy().count("Wstep") == 1);
    assert(kurs.getMaterialy()["Wstep"] == "Podstawy programowania");
}

void KursTest::testDodajStudenta() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Student student("Adam", "Nowak", "anowak", "haslo123", 12345);
    kurs.dodajStudenta(&student);
    assert(kurs.getStudenci().size() == 1);
    assert(kurs.getStudenci()[0] == &student);
}


void KursTest::testUsunMaterial() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    kurs.dodajMaterialy("Wstep", "Podstawy programowania");
    kurs.usunMaterial("Wstep");
    assert(kurs.getMaterialy().size() == 0);
    assert(!kurs.getMaterialy().size() == 5);
}


void KursTest::testSetIGetNazwa() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    kurs.setNazwa("Zaawansowane Programowanie");
    assert(kurs.getNazwa() == "Zaawansowane Programowanie");
    assert(!kurs.getNazwa() == "Zaawansowane");
}


void KursTest::testGetNauczyciele() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Nauczyciel nauczyciel("Jan", "Kowalski", "jkowalski", "haslo123");
    kurs.dodajNauczyciel(&nauczyciel);
    assert(kurs.getNauczyciele().size() == 1);
    assert(kurs.getNauczyciele()[0] == &nauczyciel);
}

void KursTest::testGetStudenci() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Student student("Adam", "Nowak", "anowak", "haslo123", 12345);
    kurs.dodajStudenta(&student);
    assert(kurs.getStudenci().size() == 1);
    assert(kurs.getStudenci()[0] == &student);
}


int main() {
    KursTest tests;
    tests.runTests();
    return 0;
}