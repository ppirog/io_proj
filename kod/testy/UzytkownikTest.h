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


#endif //IO_PROJ_UZYTKOWNIKTEST_H
