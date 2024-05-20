//
// Created by pawel on 19.05.2024.
//

#ifndef IO_PROJ_SYSTEMTEST_H
#define IO_PROJ_SYSTEMTEST_H

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

class SystemTest {
public:
    void runTests();
private:
    void testZalogujIWyloguj();
    void testDodajWydzial();
    void testUsunWydzial();
    void testDodajStudenta();
    void testUsunStudenta();
    void testCzyJestStudentem();
    void testGetWydzialy();
    void testGetStudenci();
};

#endif //IO_PROJ_SYSTEMTEST_H
