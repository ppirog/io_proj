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
    SystemTest() {
        logowanie_i_wylogowanie();
    }
    static void logowanie_i_wylogowanie() {
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

        assert(system->czyJestStudentem("user","user"));
        assert(system->zaloguj("user","user"));
        assert(!system->czyJestStudentem("admin","admin"));
        assert(system->zaloguj("admin","admin"));
        assert(!system->czyJestStudentem("admin2","admin2"));
        assert(system->zaloguj("admin2","admin2"));


        assert(!system->zaloguj("user2","admin2"));
        assert(!system->zaloguj("admin3","admin2"));
        assert(!system->zaloguj("admin4","admin2"));
        assert(!system->zaloguj("admin5","admin2"));

        assert(system->wyloguj("user","user"));
        assert(system->wyloguj("admin","admin"));
        assert(system->wyloguj("admin2","admin2"));

        assert(!system->wyloguj("user3","user"));
        assert(!system->wyloguj("admin3","admin2"));
        assert(!system->wyloguj("admin4","admin2"));
        assert(!system->wyloguj("admin5","admin2"));
    }


};


#endif //IO_PROJ_SYSTEMTEST_H
