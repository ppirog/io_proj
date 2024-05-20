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
private:
    void testDodajKurs();
    void testUsunKurs();
    void testDodajWydzial();
    void testUsunWydzial();
    void testGetWydzialy();
    void testGetProwadzoneKursy();
};


#endif //IO_PROJ_NAUCZYCIELTEST_H