//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Wydzial.cpp
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#include <iostream>
#include "Wydzial.h"

Wydzial::Wydzial(string nazwa) {
    this->nazwa = nazwa;
}

string Wydzial::getNazwa() {
    return this->nazwa;
}

void Wydzial::dodajNauczyciela(Nauczyciel* nauczyciel) {
    this->nauczyciele.push_back(nauczyciel);
}

void Wydzial::wyswietlNauczycieli() {
    for (int i = 0; i < this->nauczyciele.size(); i++) {
        cout << this->nauczyciele[i]->getImie() << " " << this->nauczyciele[i]->getNazwisko() << endl;
    }
}

void Wydzial::usunNauczyciela(Nauczyciel* nauczyciel) {
    for (int i = 0; i < this->nauczyciele.size(); i++) {
        if (this->nauczyciele[i] == nauczyciel) {
            this->nauczyciele.erase(this->nauczyciele.begin() + i);
        }
    }
}

void Wydzial::dodajKurs(Kurs* kurs) {

    for(auto &i: this->kursy) {
        if(i->getNazwa() == kurs->getNazwa()) {
            cout << "Kurs o podanej nazwie juz istnieje" << endl;
            return;
        }
    }
    cout << "Dodano kurs " + kurs->getNazwa() << endl;
    this->kursy.push_back(kurs);
}

void Wydzial::wyswietlKursy() {
    cout << "Kursy na wydziale " + this->nazwa << endl;
    for (int i = 0; i < this->kursy.size(); i++) {
        cout << this->kursy[i]->getNazwa() << endl;
    }
}

void Wydzial::usunKurs(Kurs* kurs) {
    for (int i = 0; i < this->kursy.size(); i++) {
        if (this->kursy[i] == kurs) {
            this->kursy.erase(this->kursy.begin() + i);
        }
    }
}

vector<Nauczyciel*> Wydzial::getNauczyciele() {
    return nauczyciele;
}

vector<Kurs *> Wydzial::getKursy() {
    return kursy;
}



