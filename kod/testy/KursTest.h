//
// Created by ola on 19.05.2024.
//

#ifndef IO_PROJ_KURSTEST_H
#define IO_PROJ_KURSTEST_H

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


#endif //IO_PROJ_KURSTEST_H
