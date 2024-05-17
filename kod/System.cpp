//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : System.cpp
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#include <iostream>
#include "System.h"

System::System(string nazwa) {
    this->nazwa = nazwa;
}

bool System::zaloguj(string login, string haslo) {
    for(auto &i: this->studenci) {
        if(i->getLogin() == login && i->getHaslo() == haslo) {
            this->zalogowani[login] = haslo;
            return true;
        }
    }

    for(auto &i: this->wydzialy) {
        for(auto &j: i->getNauczyciele()) {
            if(j->getLogin() == login && j->getHaslo() == haslo) {
                this->zalogowani[login] = haslo;
                return true;
            }
        }
    }

    return false;
}

void System::dodajWydzial(Wydzial *wydzial) {
    this->wydzialy.push_back(wydzial);
}

void System::wyswietlWydzialy() {

    for (int i = 0; i < this->wydzialy.size(); i++) {
        cout << this->wydzialy[i]->getNazwa() << endl;
    }
}

void System::usunWydzial(string nazwa) {
    for (int i = 0; i < this->wydzialy.size(); i++) {
        if (this->wydzialy[i]->getNazwa() == nazwa) {
            this->wydzialy.erase(this->wydzialy.begin() + i);
        }
    }
}

void System::dodajStudenta(Student *student) {
    this->studenci.push_back(student);
}

void System::wyswietlStudentow() {
    for (int i = 0; i < this->studenci.size(); i++) {
        cout << this->studenci[i]->getImie() << " " << this->studenci[i]->getNazwisko() << endl;
    }
}

void System::usunStudenta(Student *student) {
    for (int i = 0; i < this->studenci.size(); i++) {
        if (this->studenci[i] == student) {
            this->studenci.erase(this->studenci.begin() + i);
        }
    }
}

bool System::wyloguj(string login, string haslo) {

    if (this->zalogowani[login] == haslo) {
        this->zalogowani.erase(login);
        return true;
    }
    return false;
}

bool System::dodajDoZalogowanych(string login, string haslo) {
    this->zalogowani[login] = haslo;
    return true;
}

bool System::czyJestStudentem(string login, string haslo) {
    for (auto &i: this->studenci) {
        if (i->getLogin() == login && i->getHaslo() == haslo) {
            return true;
        }
    }
    return false;
}



