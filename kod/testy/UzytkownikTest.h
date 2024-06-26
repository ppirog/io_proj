//
// Created by ola on 19.05.2024.
//

#ifndef IO_PROJ_UZYTKOWNIKTEST_H
#define IO_PROJ_UZYTKOWNIKTEST_H

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


class UzytkownikTest {
public:
    void runTests();
    UzytkownikTest();
private:
    void testGetImie();
    void testGetNazwisko();
    void testGetLogin();
    void testGetHaslo();
    void testSprawdzHaslo();
    void testSetImie();
    void testSetNazwisko();
    void testSetLogin();
    void testSetHaslo();
};

void UzytkownikTest::runTests() {
    testGetImie();
    testGetNazwisko();
    testGetLogin();
    testGetHaslo();
    testSprawdzHaslo();
    testSetImie();
    testSetNazwisko();
    testSetLogin();
    testSetHaslo();
}

void UzytkownikTest::testGetImie() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    assert(uzytkownik.getImie() == "Jan");
    assert(uzytkownik.getImie() != "Janina");
}

void UzytkownikTest::testGetNazwisko() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    assert(uzytkownik.getNazwisko() == "Kowalski");
    assert(uzytkownik.getNazwisko() != "Nowak");
}

void UzytkownikTest::testGetLogin() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    assert(uzytkownik.getLogin() == "jkowalski");
}

void UzytkownikTest::testGetHaslo() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    assert(uzytkownik.getHaslo() == "haslo123");
    assert(uzytkownik.getHaslo() != "blabla");
}

void UzytkownikTest::testSprawdzHaslo() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    assert(uzytkownik.sprawdzHaslo("haslo123"));
    assert(!uzytkownik.sprawdzHaslo("blabla"));
}

void UzytkownikTest::testSetImie() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    uzytkownik.setImie("Adam");
    assert(uzytkownik.getImie() == "Adam");
}

void UzytkownikTest::testSetNazwisko() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    uzytkownik.setNazwisko("Nowak");
    assert(uzytkownik.getNazwisko() == "Nowak");
}

void UzytkownikTest::testSetLogin() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    uzytkownik.setLogin("anowak");
    assert(uzytkownik.getLogin() == "anowak");
}

void UzytkownikTest::testSetHaslo() {
    Uzytkownik uzytkownik("Jan", "Kowalski", "jkowalski", "haslo123");
    uzytkownik.setHaslo("nowehaslo");
    assert(uzytkownik.getHaslo() == "nowehaslo");
}

UzytkownikTest::UzytkownikTest() {
    runTests();
    cout << "Uzytkownik tests passed" << endl;

}


#endif //IO_PROJ_UZYTKOWNIKTEST_H
