//
// Created by pawel on 17.05.2024.
//
#include <string>
#include <vector>
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


int main() {
    System *system = new System("System");
    Wydzial *wydzial = new Wydzial("Wydzial");


    Student *student = new Student("Jan", "Nowak", "user", "user");
    student->setIndeks(123456);
    system->dodajStudenta(student);
    system->dodajDoZalogowanych("user", "user");

    Nauczyciel *nauczyciel = new Nauczyciel("Jan", "Nowak", "admin", "admin");
    system->dodajDoZalogowanych("admin", "admin");
    wydzial->dodajNauczyciela(nauczyciel);
    Kurs *kurs = new Kurs("Kurs", wydzial);
    kurs->dodajNauczyciel(nauczyciel);

    wydzial->dodajKurs(kurs);
    system->dodajWydzial(wydzial);

    while (true) {

        cout << "1. Zaloguj" << endl;
        cout << "2. Wyloguj" << endl;

        int wybor;
        cin >> wybor;

        if (wybor == 1) {
            string login;
            string haslo;
            cout << "Podaj login: ";
            cin >> login;
            cout << "Podaj haslo: ";
            cin >> haslo;
            if (system->zaloguj(login, haslo)) {
                if (system->czyJestStudentem(login, haslo)) {
                    cout << "Zalogowano jako student" << endl;
                    while (true) {
                        cout << "1. Wyswietl kursy" << endl;
                        cout << "2. Dolacz do kursu" << endl;
                        cout << "3. Wyjdz z kursu" << endl;
                        cout << "4. Wyloguj" << endl;
                        int wybor;
                        cin >> wybor;

                        if (wybor == 4) {
                            system->wyloguj(login, haslo);
                            break;
                        }
                    }
                } else {
                    cout << "Zalogowano jako nauczyciel" << endl;
                    while (true) {
                        cout << "1. Wyswietl kursy" << endl;
                        cout << "2. Dodaj kurs" << endl;
                        cout << "3. Usun kurs" << endl;
                        cout << "4. Wyloguj" << endl;
                        int wybor;
                        cin >> wybor;

                    }
                }
            } else {
                cout << "Niepoprawne dane" << endl;
            }

        }


    }


    return 0;
}
