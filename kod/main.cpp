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
    Wydzial *wydzial1 = new Wydzial("Matematyki");
    Wydzial *wydzial2 = new Wydzial("Medyczny");


    Student *student = new Student("Jan", "Nowak", "user", "user");
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

                    Student *student = nullptr;
                    for (int i = 0; i < system->getStudenci().size(); i++) {
                        if (system->getStudenci()[i]->getLogin() == login) {
                            student = system->getStudenci()[i];
                        }
                    }

                    cout << "Zalogowano jako student " << student->getImie() << " " << student->getNazwisko() << endl;

                    while (true) {
                        cout << "1. Wyswietl zapisane kursy" << endl;
                        cout << "2. Wybierz wydzial" << endl;
                        cout << "3. Wyloguj" << endl;

                        int wybor;
                        cin >> wybor;

                        if (wybor == 1) {
                            for (auto &i: student->getDolaczoneKursy()) {
                                cout << i->getNazwa() << endl;
                            }
                        } else if (wybor == 2) {
                            cout << "Wybierz wydzial: " << endl;
                            for (int i = 0; i < system->getWydzialy().size(); i++) {
                                cout << i << ". " << system->getWydzialy()[i]->getNazwa() << endl;
                            }
                            int wybor;
                            cin >> wybor;
                            Wydzial *wydzial = system->getWydzialy()[wybor];

                            if (wydzial != nullptr) {
                                cout << "Wybrano wydzial " << wydzial->getNazwa() << endl;

                                cout << "1. Zapisz sie na kurs" << endl;

                                int wybor;
                                cin >> wybor;
                                if (wybor == 1) {
                                    cout << "Wybierz kurs: Jak nie chcesz zadnego to -1" << endl;
                                    for (int i = 0; i < wydzial->getKursy().size(); i++) {
                                        cout << i << ". " << wydzial->getKursy()[i]->getNazwa() << endl;
                                    }
                                    int wybor;
                                    cin >> wybor;

                                    if(wybor == -1){
                                        continue;
                                    }
                                    Kurs *kurs = wydzial->getKursy()[wybor];
                                    student->dodajKurs(kurs);
                                    kurs->dodajStudenta(student);
                                }

                            } else {
                                cout << "Niepoprawne dane" << endl;
                            }

                        }
                        else if(wybor == 3){
                            break;
                        }


                    }


                } else {
                    Nauczyciel *nauczyciel = nullptr;
                    for (int i = 0; i < system->getWydzialy().size(); i++) {
                        for (int j = 0; j < system->getWydzialy()[i]->getNauczyciele().size(); j++) {
                            if (system->getWydzialy()[i]->getNauczyciele()[j]->getLogin() == login) {
                                nauczyciel = system->getWydzialy()[i]->getNauczyciele()[j];
                            }
                        }
                    }

                    cout << "Zalogowano jako nauczyciel " << nauczyciel->getImie() << " " << nauczyciel->getNazwisko()
                         << endl;

                    while (true) {
                        cout << "1. Wyswietl kursy" << endl;
                        cout << "2. Wybierz przypisany wydzial" << endl;
                        cout << "3. Wyloguj" << endl;

                        int wybor;
                        cin >> wybor;

                        if (wybor == 1) {
                            for (auto &i: nauczyciel->getProwadzoneKursy()) {
                                cout << i->getNazwa() << endl;
                            }
                        } else if (wybor == 2) {
                            cout << "Wybierz wydzial: " << endl;

                            for(int i = 0; i < nauczyciel->getWydzialy().size();i++){
                                cout << nauczyciel->getWydzialy()[i]->getNazwa() << endl;
                            }
                            cout << "Podaj nazwe wydzialu: ";
                            string nazwa;
                            cin >> nazwa;

                            Wydzial *wydzial = nullptr;

                            for(int i = 0; i < nauczyciel->getWydzialy().size();i++){
                                if(nauczyciel->getWydzialy()[i]->getNazwa() == nazwa){
                                    wydzial = nauczyciel->getWydzialy()[i];
                                }
                            }

                            if (wydzial != nullptr) {
                                cout << "Wybrano wydzial " << wydzial->getNazwa() << endl;

                                cout << "1. Dodaj kurs" << endl;

                                int wybor;
                                cin >> wybor;
                                if (wybor == 1) {
                                    cout << "Podaj nazwe kursu: ";
                                    string nazwa;
                                    cin >> nazwa;
                                    Kurs *kurs = new Kurs(nazwa, wydzial);
                                    kurs->dodajNauczyciel(nauczyciel);
                                    nauczyciel->dodajKurs(kurs);
                                    wydzial->dodajKurs(kurs);
                                }

                            } else {
                                cout << "Niepoprawne dane" << endl;
                            }

                        }
                        else if(wybor == 3){
                            break;
                        }
                    }
                }


            } else {
                cout << "Niepoprawne dane" << endl;
            }

        }

    }
    return 0;
}
