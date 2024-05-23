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

class StudentTest {
public:
    void runTests();
    StudentTest();
private:
    void testDodajKurs();
    void testGetISetIndeks();
    void testGetDolaczoneKursy();
};

void StudentTest::runTests() {
    testDodajKurs();
    testGetISetIndeks();
    testGetDolaczoneKursy();
}

void StudentTest::testDodajKurs() {
    Wydzial wydzial("Informatyka");
    Kurs kurs("Programowanie", &wydzial);
    Student student("Anna", "Nowak", "anowak", "haslo123");
    student.dodajKurs(&kurs);
    assert(student.getDolaczoneKursy().size() == 1);
    assert(student.getDolaczoneKursy()[0] == &kurs);
}

void StudentTest::testGetISetIndeks() {
    Student student("Anna", "Nowak", "anowak", "haslo123");
    student.setIndeks(123456);
    assert(student.getIndeks() == 123456);
    assert(student.getIndeks() != 123123);
}


void StudentTest::testGetDolaczoneKursy() {
    Wydzial wydzial("Informatyka");
    Kurs kurs1("Programowanie", &wydzial);
    Kurs kurs2("Algorytmy", &wydzial);
    Student student("Anna", "Nowak", "anowak", "haslo123");
    student.dodajKurs(&kurs1);
    student.dodajKurs(&kurs2);
    assert(student.getDolaczoneKursy().size() == 2);
    assert(student.getDolaczoneKursy()[0] == &kurs1);
    assert(student.getDolaczoneKursy()[1] == &kurs2);
}

StudentTest::StudentTest() {
    runTests();
    cout << "Student tests passed" << endl;
}
