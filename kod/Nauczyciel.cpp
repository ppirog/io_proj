//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Nauczyciel.cpp
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#include "Nauczyciel.h"

Nauczyciel::Nauczyciel(string imie, string nazwisko, string login, string haslo)
        : Uzytkownik(imie, nazwisko, login, haslo) {

}

void Nauczyciel::dodajKurs(Kurs *kurs) {

    for(int i = 0; i < this->prowadzoneKursy.size(); i++) {
        if(this->prowadzoneKursy[i]->getNazwa() == kurs->getNazwa()) {
            return;
        }
    }

    this->prowadzoneKursy.push_back(kurs);
}

void Nauczyciel::usunKurs(Kurs *kurs) {
    for(int i = 0; i < this->prowadzoneKursy.size(); i++) {
        if(this->prowadzoneKursy[i] == kurs) {
            this->prowadzoneKursy.erase(this->prowadzoneKursy.begin() + i);
        }
    }

}

void Nauczyciel::dodajWydzial(Wydzial *wydzial) {
    this->wydzialy.push_back(wydzial);

}

void Nauczyciel::usunWydzial(Wydzial *wydzial) {


    for(int i = 0; i < this->wydzialy.size(); i++) {
        if(this->wydzialy[i] == wydzial) {
            this->wydzialy.erase(this->wydzialy.begin() + i);
        }
    }

}

vector<Wydzial *> Nauczyciel::getWydzialy() {
    return this->wydzialy;
}

vector<Kurs *> Nauczyciel::getProwadzoneKursy() {
    return this->prowadzoneKursy;
}

