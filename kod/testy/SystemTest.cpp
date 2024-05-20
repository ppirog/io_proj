//
// Created by pawel on 19.05.2024.
//

#include "SystemTest.h"
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

void SystemTest::runTests() {
    testZalogujIWyloguj();
    testDodajWydzial();
    testUsunWydzial();
    testDodajStudenta();
    testUsunStudenta();
    testCzyJestStudentem();
    testGetWydzialy();
    testGetStudenci();
}


void SystemTest::testZalogujIWyloguj() {
        System *system = new System("System");
        Wydzial *wydzial1 = new Wydzial("Matematyki");
        Wydzial *wydzial2 = new Wydzial("Medyczny");
        Student *student = new Student("Maciek", "Nowak", "user", "user");
        student->setIndeks(123456);
        system->dodajStudenta(student);
        Nauczyciel *nauczyciel1 = new Nauczyciel("Jan", "Nowak", "admin", "admin");
        nauczyciel1->dodajWydzial(wydzial1);
        Nauczyciel *nauczyciel2 = new Nauczyciel("Marek", "Rocki", "admin2", "admin2");
        nauczyciel2->dodajWydzial(wydzial2);
        wydzial1->dodajNauczyciela(nauczyciel1);
        system->dodajWydzial(wydzial1);
        wydzial2->dodajNauczyciela(nauczyciel2);
        system->dodajWydzial(wydzial2);

        assert(system->zaloguj("user","user"));
        assert(!system->zaloguj("admin3","admin2"));

        assert(system->wyloguj("user","user"));
        assert(!system->wyloguj("user3","user"));
}

void SystemTest::testDodajWydzial() {
    System system("Testowy System");
    Wydzial wydzial("Informatyka");
    system.dodajWydzial(&wydzial);
    assert(system.getWydzialy().size() == 1);
    assert(system.getWydzialy()[0]->getNazwa() == "Informatyka");
}


void SystemTest::testUsunWydzial() {
    System system("Testowy System");
    Wydzial wydzial("Informatyka");
    system.dodajWydzial(&wydzial);
    system.usunWydzial("Informatyka");
    assert(system.getWydzialy().empty());
}

void SystemTest::testDodajStudenta() {
    System system("Testowy System");
    Student student("Jan", "Kowalski", "jank", "password");
    system.dodajStudenta(&student);
    assert(system.getStudenci().size() == 1);
    assert(system.getStudenci()[0]->getLogin() == "jank");
}

void SystemTest::testUsunStudenta() {
    System system("Testowy System");
    Student student("Jan", "Kowalski", "jank", "password");
    system.dodajStudenta(&student);
    system.usunStudenta(&student);
    assert(system.getStudenci().empty());
}


void SystemTest::testCzyJestStudentem() {
    System system("Testowy System");
    Student student("Jan", "Kowalski", "jank", "password");
    system.dodajStudenta(&student);
    assert(system.czyJestStudentem("jank", "password"));
    assert(!system.czyJestStudentem("jank", "wrong"));
}

void SystemTest::testGetWydzialy() {
    System system("Testowy System");
    Wydzial wydzial("Informatyka");
    system.dodajWydzial(&wydzial);
    assert(system.getWydzialy().size() == 1);
    assert(system.getWydzialy()[0]->getNazwa() == "Informatyka");
}

void SystemTest::testGetStudenci() {
    System system("Testowy System");
    Student student("Jan", "Kowalski", "jank", "password");
    system.dodajStudenta(&student);
    assert(system.getStudenci().size() == 1);
    assert(system.getStudenci()[0]->getLogin() == "jank");
}

SystemTest::SystemTest() {
    runTests();
    cout << "System tests passed" << endl;

}


