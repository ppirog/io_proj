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
#include "testy/SystemTest.h"



using namespace std;

class Uzytkownik;

class Wydzial;

class Nauczyciel;

class Student;

class Kurs;

class System;

class SystemTest;



int main() {
    SystemTest *systemTest = new SystemTest();



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


    while (true) {

        cout << "1. Zaloguj" << endl;
        cout << "2. Wyjdz z systemu" << endl;

        int wybor;
        cin >> wybor;

        if (wybor == 1) {
            string login;
            string haslo;
            cout << "Podaj logowanie_i_wylogowanie: ";
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
                        cout << "2. Wybierz kurs do ktorego jestes zapisany" << endl;
                        cout << "3. Wybierz wydzial" << endl;
                        cout << "4. Wyloguj" << endl;

                        int wybor;
                        cin >> wybor;

                        if (wybor == 1) {

                            if (student->getDolaczoneKursy().size() == 0) {
                                cout << "Nie jestes zapisany na zadne kursy" << endl;
                                continue;
                            }

                            for (auto &i: student->getDolaczoneKursy()) {
                                cout << i->getNazwa() << endl;
                            }
                        } else if (wybor == 2) {
                            if (student->getDolaczoneKursy().size() == 0) {
                                cout << "Nie jestes zapisany na zadne kursy" << endl;
                                continue;
                            }

                            cout << "Lista twoich kursow: " << endl;
                            for (int i = 0; i < student->getDolaczoneKursy().size(); i++) {
                                cout << i << ". " << student->getDolaczoneKursy()[i]->getNazwa() << endl;
                            }

                            int wybor;
                            cout << "Wybierz kurs: Jak nie chcesz zadnego to -1" << endl;
                            cin >> wybor;

                            if (wybor == -1) {
                                continue;
                            } else {

                                Kurs *kurs = student->getDolaczoneKursy()[wybor];
                                cout << "Wybrany kurs: " << kurs->getNazwa() << endl;

                                while (true) {

                                    cout << "1. Wyswietl materialy" << endl;
                                    cout << "2. Pobierz material" << endl;
                                    cout << "3. Pokaz ocene" << endl;
                                    cout << "4. Wyswietl prowadzacych" << endl;
                                    cout << "5. Wyjdz z kursu" << endl;

                                    int wybor;
                                    cin >> wybor;

                                    if (wybor == 1) {
                                        kurs->wyswietlMaterialy();
                                    }else if(wybor == 2){
                                        kurs->pobierzMaterialy();
                                    }else if (wybor == 3) {
                                        kurs->wyswietlOcene(student);
                                    } else if (wybor == 4) {
                                        for (auto &i: kurs->getNauczyciele()) {
                                            cout << i->getImie() << " " << i->getNazwisko() << endl;
                                        }
                                    } else {
                                        break;
                                    }

                                }
                            }
                        } else if (wybor == 3) {
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

                                    if (wybor == -1) {
                                        continue;
                                    }
                                    Kurs *kurs = wydzial->getKursy()[wybor];
                                    student->dodajKurs(kurs);
                                    kurs->dodajStudenta(student);
                                }

                            } else {
                                cout << "Niepoprawne dane" << endl;
                            }

                        } else if (wybor == 4) {
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
                        cout << "2. Wybierz utworzony kurs" << endl;
                        cout << "3. Wybierz przypisany wydzial" << endl;
                        cout << "4. Wyloguj" << endl;

                        int wybor;
                        cin >> wybor;

                        if (wybor == 1) {

                            if (nauczyciel->getProwadzoneKursy().size() == 0) {
                                cout << "Nie masz zadnych kursow" << endl;
                                continue;
                            }

                            for (auto &i: nauczyciel->getProwadzoneKursy()) {
                                cout << i->getNazwa() << endl;
                            }
                        } else if (wybor == 2) {

                            if (nauczyciel->getProwadzoneKursy().size() == 0) {
                                cout << "Nie masz zadnych kursow" << endl;
                                continue;
                            }
                            cout << "Lista twoich kursow: " << endl;
                            for (int i = 0; i < nauczyciel->getProwadzoneKursy().size(); i++) {
                                cout << i << ". " << nauczyciel->getProwadzoneKursy()[i]->getNazwa() << endl;
                            }
                            int wybor;
                            cout << "Wybierz kurs: Jak nie chcesz zadnego to -1" << endl;
                            cin >> wybor;

                            if (wybor == -1) {
                                continue;
                            } else {

                                Kurs *kurs = nauczyciel->getProwadzoneKursy()[wybor];
                                cout << "Wybrany kurs: " << kurs->getNazwa() << endl;

                                while (true) {


                                    cout << "1. Dodaj material" << endl;
                                    cout << "2. Wyswietl materialy" << endl;
                                    cout << "3. Usun material" << endl;
                                    cout << "4. Wyswietl studentow" << endl;
                                    cout << "5. Ocen studentow" << endl;
                                    cout << "6. Wyswietl oceny studentow" << endl;
                                    cout << "7. Wyjdz z kursu" << endl;
                                    int wybor;
                                    cin >> wybor;

                                    if (wybor == 1) {
                                        cout << "Podaj tytul: ";
                                        string tytul;
                                        cin >> tytul;
                                        cout << "Podaj tresc: ";
                                        string tresc;
                                        cin >> tresc;
                                        kurs->dodajMaterialy(tytul, tresc);
                                    } else if (wybor == 2) {
                                        kurs->wyswietlMaterialy();
                                    } else if (wybor == 3) {
                                        cout << "Podaj tytul: ";
                                        string tytul;
                                        cin >> tytul;
                                        kurs->usunMaterial(tytul);
                                    } else if (wybor == 4) {
                                        for (auto &i: kurs->getStudenci()) {
                                            cout << i->getImie() << " " << i->getNazwisko() << endl;
                                        }
                                    } else if (wybor == 5) {
                                        kurs->ocenStudentow();
                                    } else if (wybor == 6) {
                                        kurs->wyswietlOcenyStudentow();
                                    } else if (wybor == 7) {
                                        break;
                                    }
                                }
                            }

                        } else if (wybor == 3) {
                            cout << "Wybierz wydzial: " << endl;

                            for (int i = 0; i < nauczyciel->getWydzialy().size(); i++) {
                                cout << nauczyciel->getWydzialy()[i]->getNazwa() << endl;
                            }
                            cout << "Podaj nazwe wydzialu: ";
                            string nazwa;
                            cin >> nazwa;

                            Wydzial *wydzial = nullptr;

                            for (int i = 0; i < nauczyciel->getWydzialy().size(); i++) {
                                if (nauczyciel->getWydzialy()[i]->getNazwa() == nazwa) {
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

                        } else if (wybor == 4) {
                            break;
                        }
                    }
                }


            } else {
                cout << "Niepoprawne dane" << endl;
            }

        }else if (wybor == 2) {
            break;
        }else {
            cout << "Niepoprawny wybor" << endl;
        }

    }
    return 0;
}
