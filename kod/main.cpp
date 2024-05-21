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
#include "testy/KursTest.h"
#include "testy/StudentTest.h"
#include "testy/NauczycielTest.h"
#include "testy/WydzialTest.h"
#include "testy/UzytkownikTest.h"




using namespace std;

class Uzytkownik;

class Wydzial;

class Nauczyciel;

class Student;

class Kurs;

class System;


class SystemTest;

class KursTest;

class StudentTest;

class NauczycielTest;

class SystemTest;

class WydzialTest;


int main() {


    System *system = new System("System");
    Wydzial *wydzial1 = new Wydzial("Pielegniarstwa");
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

        cout << "=============== Witaj w systemie ===============" << endl;
        cout << "|                                              |" << endl;
        cout << "|            1. Zaloguj                        |" << endl;
        cout << "|            2. Wyjdz z systemu                |" << endl;
        cout << "|                                              |" << endl;
        cout << "================================================" << endl;

        int wybor;
        cin >> wybor;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            cout << "================= Blad systemu =================" << endl;
            cout << "|                                              |" << endl;
            cout << "|               Niepoprawne dane               |" << endl;
            cout << "|                                              |" << endl;
            cout << "================================================" << endl;
            continue;
        }

        if (wybor == 1) {
            string login;
            string haslo;
            cout << "================== Logowanie ===================\n" << endl;
            cout << "Podaj login: ";
            getline(cin >> ws, login);
            cout << "Podaj haslo: ";
            getline(cin >> ws, haslo);
            cout << "\n================================================" << endl;
            if (system->zaloguj(login, haslo)) {

                if (system->czyJestStudentem(login, haslo)) {

                    Student *student = nullptr;
                    for (int i = 0; i < system->getStudenci().size(); i++) {
                        if (system->getStudenci()[i]->getLogin() == login) {
                            student = system->getStudenci()[i];
                        }
                    }

                    cout << "=============== Panel Studenta =================" << endl;
                    cout << " " << endl;
                    cout << "       " << "Zalogowano jako student " << student->getImie() << " " << student->getNazwisko() << endl;
                    cout << " " << endl;
                    cout << "================================================" << endl;

                    while (true) {
                        cout << "===================== Menu =====================" << endl;
                        cout << "|                                              |" << endl;
                        cout << "|  1. Wyswietl zapisane kursy                  |" << endl;
                        cout << "|  2. Wybierz kurs do ktorego jestes zapisany  |" << endl;
                        cout << "|  3. Wybierz wydzial                          |" << endl;
                        cout << "|  4. Wyloguj                                  |" << endl;
                        cout << "|                                              |" << endl;
                        cout << "================================================" << endl;

                        int wybor;
                        cin >> wybor;

                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            cout << "================= Blad systemu =================" << endl;
                            cout << "|                                              |" << endl;
                            cout << "|               Niepoprawne dane               |" << endl;
                            cout << "|                                              |" << endl;
                            cout << "================================================" << endl;
                            continue;
                        }

                        if (wybor == 1) {

                            if (student->getDolaczoneKursy().size() == 0) {
                                cout << "===================== Blad =====================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|      Nie jestes zapisany na zadne kursy      |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }

                            cout << "============== Lista twoich kursow =============" << endl;
                            cout << " " << endl;
                            for (auto &i: student->getDolaczoneKursy()) {
                                cout << "       " <<  i->getNazwa() << endl;
                            }
                            cout << " " << endl;
                            cout << "================================================" << endl;

                        } else if (wybor == 2) {
                            if (student->getDolaczoneKursy().size() == 0) {
                                cout << "===================== Blad =====================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|      Nie jestes zapisany na zadne kursy      |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }

                            cout << "============== Lista twoich kursow =============" << endl;
                            cout << " " << endl;
                            cout << "    Wybierz kurs: Jak nie chcesz zadnego to -1" << endl;
                            cout << " " << endl;
                            for (int i = 0; i < student->getDolaczoneKursy().size(); i++) {
                                cout << "       "<< i << ". " << student->getDolaczoneKursy()[i]->getNazwa() << endl;
                            }
                            cout << " " << endl;
                            cout << "================================================" << endl;

                            int wybor;

                            cin >> wybor;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }
                            if (wybor == -1) {
                                continue;
                            } else if (wybor >= 0 && wybor < student->getDolaczoneKursy().size()) {

                                Kurs *kurs = student->getDolaczoneKursy()[wybor];

                                cout << "================= Wybrany kurs =================" << endl;
                                cout << " " << endl;
                                cout <<  "       "<< kurs->getNazwa() << endl;
                                cout << " " << endl;
                                cout << "================================================" << endl;

                                while (true) {

                                    cout << "===================== Menu =====================" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "|     1. Wyswietl materialy                    |" << endl;
                                    cout << "|     2. Pobierz material                      |" << endl;
                                    cout << "|     3. Pokaz ocene                           |" << endl;
                                    cout << "|     4. Wyswietl prowadzacych                 |" << endl;
                                    cout << "|     5. Wyjdz z kursu                         |" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "================================================" << endl;

                                    int wybor;
                                    cin >> wybor;
                                    if (std::cin.fail()) {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "================= Blad systemu =================" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "|               Niepoprawne dane               |" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "================================================" << endl;
                                        continue;
                                    }
                                    if (wybor == 1) {
                                        kurs->wyswietlMaterialy();
                                    }else if(wybor == 2){
                                        kurs->pobierzMaterialy();
                                    }else if (wybor == 3) {
                                        kurs->wyswietlOcene(student);
                                    } else if (wybor == 4) {
                                        cout << "================== Prowadzacy ==================" << endl;
                                        cout << " " << endl;
                                        for (auto &i: kurs->getNauczyciele()) {
                                            cout << "       " << i->getImie() << " " << i->getNazwisko() << endl;
                                        }
                                        cout << " " << endl;
                                        cout << "================================================" << endl;
                                    } else {
                                        break;
                                    }

                                }
                            }else{
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }
                        } else if (wybor == 3) {
                            cout << "================ Wybierz wydzial ===============" << endl;
                            cout << " " << endl;
                            for (int i = 0; i < system->getWydzialy().size(); i++) {
                                cout << "       " <<  i << ". " << system->getWydzialy()[i]->getNazwa() << endl;
                            }
                            cout << " " << endl;
                            cout << "================================================" << endl;
                            int wybor;
                            cin >> wybor;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }
                            if (wybor < 0 || wybor >= system->getWydzialy().size()) {
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }

                            Wydzial *wydzial = system->getWydzialy()[wybor];

                            if (wydzial != nullptr) {
                                cout << "================ Wybrano wydzial ===============" << endl;
                                cout << " " << endl;
                                cout << "       " <<  wydzial->getNazwa() << endl;
                                cout << " " << endl;
                                cout << "================================================" << endl;

                                cout << "===================== Menu =====================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|     1. Zapisz sie na kurs                    |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;

                                int wybor;
                                cin >> wybor;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(10000, '\n');
                                    cout << "================= Blad systemu =================" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "|               Niepoprawne dane               |" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "================================================" << endl;
                                    continue;
                                }
                                if (wybor == 1) {
                                    cout << "================= Wybierz Kurs =================" << endl;
                                    cout << " " << endl;
                                    cout << "    Wybierz kurs: Jak nie chcesz zadnego to -1" << endl;
                                    cout << " " << endl;
                                    for (int i = 0; i < wydzial->getKursy().size(); i++) {
                                        cout << "       " << i << ". " << wydzial->getKursy()[i]->getNazwa() << endl;
                                    }
                                    cout << " " << endl;
                                    cout << "================================================" << endl;
                                    int wybor;
                                    cin >> wybor;
                                    if (std::cin.fail()) {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "================= Blad systemu =================" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "|               Niepoprawne dane               |" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "================================================" << endl;
                                        continue;
                                    }
                                    if (wybor == -1) {
                                        continue;
                                    }else if (wybor >= 0 && wybor < wydzial->getKursy().size()){
                                        Kurs *kurs = wydzial->getKursy()[wybor];
                                        student->dodajKurs(kurs);
                                        kurs->dodajStudenta(student);
                                    }else {
                                        cout << "================= Blad systemu =================" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "|               Niepoprawne dane               |" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "================================================" << endl;
                                        continue;
                                    }
                                }

                            } else {
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                            }

                        } else if (wybor == 4) {
                            cout << "================================================" << endl;
                            cout << "|              Poprawnie wylogowano            |" << endl;
                            cout << "================================================" << endl;
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

                    cout << "============== Panel Nauczyciela ===============" << endl;
                    cout << " " << endl;
                    cout << "       " << "Zalogowano jako nauczyciel " << nauczyciel->getImie() << " " << nauczyciel->getNazwisko()<< endl;
                    cout << " " << endl;
                    cout << "================================================" << endl;

                    while (true) {

                        cout << "===================== Menu =====================" << endl;
                        cout << "|                                              |" << endl;
                        cout << "|  1. Wyswietl kursy                           |" << endl;
                        cout << "|  2. Wybierz utworzony kurs                   |" << endl;
                        cout << "|  3. Wybierz przypisany wydzial               |" << endl;
                        cout << "|  4. Wyloguj                                  |" << endl;
                        cout << "|                                              |" << endl;
                        cout << "================================================" << endl;

                        int wybor;
                        cin >> wybor;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            cout << "================= Blad systemu =================" << endl;
                            cout << "|                                              |" << endl;
                            cout << "|               Niepoprawne dane               |" << endl;
                            cout << "|                                              |" << endl;
                            cout << "================================================" << endl;
                            continue;
                        }
                        if (wybor == 1) {

                            if (nauczyciel->getProwadzoneKursy().size() == 0) {

                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|           Nie masz zadnych kursow            |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }

                            cout << "=============== Prowadzone kursy ===============" << endl;
                            cout << " " << endl;
                            for (auto &i: nauczyciel->getProwadzoneKursy()) {
                                cout << "       " << i->getNazwa() << endl;
                            }
                            cout << " " << endl;
                            cout << "================================================" << endl;

                        } else if (wybor == 2) {

                            if (nauczyciel->getProwadzoneKursy().size() == 0) {
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|           Nie masz zadnych kursow            |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }

                            cout << "============== Lista twoich kursow =============" << endl;
                            cout << " " << endl;
                            cout << "    Wybierz kurs: Jak nie chcesz zadnego to -1" << endl;
                            cout << " " << endl;
                            for (int i = 0; i < nauczyciel->getProwadzoneKursy().size(); i++) {
                                cout << "       " << i << ". " << nauczyciel->getProwadzoneKursy()[i]->getNazwa() << endl;
                            }
                            cout << " " << endl;
                            cout << "================================================" << endl;

                            int wybor;

                            cin >> wybor;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }
                            if (wybor == -1) {
                                continue;
                            } else if (wybor >= 0 && wybor < nauczyciel->getProwadzoneKursy().size()){

                                Kurs *kurs = nauczyciel->getProwadzoneKursy()[wybor];


                                cout << "================= Wybrany kurs =================" << endl;
                                cout << " " << endl;
                                cout <<  "       "<< kurs->getNazwa() << endl;
                                cout << " " << endl;
                                cout << "================================================" << endl;

                                while (true) {


                                    cout << "===================== Menu =====================" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "|  1. Dodaj material                           |" << endl;
                                    cout << "|  2. Wyswietl materialy                       |" << endl;
                                    cout << "|  3. Usun material                            |" << endl;
                                    cout << "|  4. Wyswietl studentow                       |" << endl;
                                    cout << "|  5. Ocen studentow                           |" << endl;
                                    cout << "|  6. Wyswietl oceny studentow                 |" << endl;
                                    cout << "|  7. Wyjdz z kursu                            |" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "================================================" << endl;

                                    int wybor;
                                    cin >> wybor;
                                    if (std::cin.fail()) {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "================= Blad systemu =================" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "|               Niepoprawne dane               |" << endl;
                                        cout << "|                                              |" << endl;
                                        cout << "================================================" << endl;
                                        continue;
                                    }
                                    if (wybor == 1) {

                                        cout << "================ Dodaj material ================" << endl;
                                        cout << " " << endl;
                                        cout << "       " << "Podaj tytul: ";
                                        string tytul;
                                        getline(cin >> ws, tytul);
                                        cout << "       " << "Podaj tresc: ";
                                        string tresc;
                                        getline(cin >> ws, tresc);
                                        kurs->dodajMaterialy(tytul, tresc);
                                        cout << " " << endl;
                                        cout << "================================================" << endl;

                                    } else if (wybor == 2) {
                                        kurs->wyswietlMaterialy();
                                    } else if (wybor == 3) {

                                        cout << "================ Usun material =================" << endl;
                                        cout << " " << endl;
                                        cout << "       " << "Podaj tytul: ";
                                        string tytul;
                                        getline(cin >> ws, tytul);
                                        kurs->usunMaterial(tytul);
                                        cout << " " << endl;
                                        cout << "================================================" << endl;
                                    } else if (wybor == 4) {

                                        if (kurs->getStudenci().size() == 0) {

                                            cout << "================= Blad systemu =================" << endl;
                                            cout << " " << endl;
                                            cout << "       " << "Brak studentow na kursie " + kurs->getNazwa() << endl;
                                            cout << " " << endl;
                                            cout << "================================================" << endl;
                                            continue;
                                        }

                                        cout << "=================== Studenci ===================" << endl;
                                        cout << " " << endl;
                                        for (auto &i: kurs->getStudenci()) {
                                            cout << i->getImie() << " " << i->getNazwisko() << endl;
                                        }
                                        cout << " " << endl;
                                        cout << "================================================" << endl;

                                    } else if (wybor == 5) {
                                        kurs->ocenStudentow();
                                    } else if (wybor == 6) {
                                        kurs->wyswietlOcenyStudentow();
                                    } else if (wybor == 7) {
                                        break;
                                    }
                                }
                            }else {
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                                continue;
                            }

                        } else if (wybor == 3) {

                            cout << "================ Wybierz wydzial ===============" << endl;
                            cout << " " << endl;
                            for (int i = 0; i < nauczyciel->getWydzialy().size(); i++) {
                                cout << nauczyciel->getWydzialy()[i]->getNazwa() << endl;
                            }
                            cout << " " << endl;
                            cout << "================================================" << endl;

                            cout << "================================================" << endl;
                            cout << " " << endl;
                            cout << "       " << "Podaj nazwe wydzialu: ";

                            string nazwa;
                            getline(cin >> ws, nazwa);
                            cout << " " << endl;
                            cout << "================================================" << endl;

                            Wydzial *wydzial = nullptr;

                            for (int i = 0; i < nauczyciel->getWydzialy().size(); i++) {
                                if (nauczyciel->getWydzialy()[i]->getNazwa() == nazwa) {
                                    wydzial = nauczyciel->getWydzialy()[i];
                                }
                            }

                            if (wydzial != nullptr) {
                                cout << "================ Wybrano wydzial ===============" << endl;
                                cout << " " << endl;
                                cout << "       " <<  wydzial->getNazwa() << endl;
                                cout << " " << endl;
                                cout << "================================================" << endl;

                                cout << "===================== Menu =====================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|  1. Dodaj kurs                               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;

                                int wybor;
                                cin >> wybor;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(10000, '\n');
                                    cout << "================= Blad systemu =================" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "|               Niepoprawne dane               |" << endl;
                                    cout << "|                                              |" << endl;
                                    cout << "================================================" << endl;
                                    continue;
                                }
                                if (wybor == 1) {

                                    cout << "================ Tworzenie kursu ===============" << endl;
                                    cout << " " << endl;
                                    cout << "       " << "Podaj nazwe kursu: ";
                                    string nazwa;

                                    getline(cin >> ws, nazwa);
                                    cout << " " << endl;
                                    cout << "================================================" << endl;
                                    Kurs *kurs = new Kurs(nazwa, wydzial);
                                    kurs->dodajNauczyciel(nauczyciel);
                                    nauczyciel->dodajKurs(kurs);
                                    wydzial->dodajKurs(kurs);

                                }

                            } else {
                                cout << "================= Blad systemu =================" << endl;
                                cout << "|                                              |" << endl;
                                cout << "|               Niepoprawne dane               |" << endl;
                                cout << "|                                              |" << endl;
                                cout << "================================================" << endl;
                            }

                        } else if (wybor == 4) {
                            cout << "================================================" << endl;
                            cout << "|              Poprawnie wylogowano            |" << endl;
                            cout << "================================================" << endl;
                            break;
                        }
                    }
                }


            } else {
                cout << "================= Blad systemu =================" << endl;
                cout << "|                                              |" << endl;
                cout << "|               Niepoprawne dane               |" << endl;
                cout << "|                                              |" << endl;
                cout << "================================================" << endl;
            }

        }else if (wybor == 2) {
            break;
        }else {
            cout << "================= Blad systemu =================" << endl;
            cout << "|                                              |" << endl;
            cout << "|               Niepoprawne dane               |" << endl;
            cout << "|                                              |" << endl;
            cout << "================================================" << endl;
        }

    }

    return 0;
}
