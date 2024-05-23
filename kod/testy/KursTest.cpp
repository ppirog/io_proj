//
// Created by ola on 19.05.2024.
//

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

class KursTest {
public:
    void runTests();
    KursTest();
private:
    void testDodajNauczyciel();
    void testDodajStudenta();
    void testSetIGetNazwa();
    void testGetNauczyciele();
    void testGetStudenci();
};

void KursTest::runTests() {
    testDodajNauczyciel();
    testDodajStudenta();
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

void KursTest::testDodajStudenta() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Student student("Adam", "Nowak", "anowak", "haslo123");
    kurs.dodajStudenta(&student);
    assert(kurs.getStudenci().size() == 1);
    assert(kurs.getStudenci()[0] == &student);
}

void KursTest::testSetIGetNazwa() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    kurs.setNazwa("Zaawansowane Programowanie");
    assert(kurs.getNazwa() == "Zaawansowane Programowanie");
    assert(kurs.getNazwa() != "Zaawansowane");
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
    Student student("Adam", "Nowak", "anowak", "haslo123");
    kurs.dodajStudenta(&student);
    assert(kurs.getStudenci().size() == 1);
    assert(kurs.getStudenci()[0] == &student);
}

KursTest::KursTest() {
    runTests();
    cout << "Kurs tests passed" << endl;
}




