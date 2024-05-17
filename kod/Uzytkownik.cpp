//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Uzytkownik.cpp
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#include <iostream>
#include "Uzytkownik.h"

Uzytkownik::Uzytkownik(string imie, string nazwisko, string login, string haslo) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->login = login;
    this->haslo = haslo;
}

Uzytkownik::Uzytkownik(string login, string haslo) {
    this->login = login;
    this->haslo = haslo;
}

string Uzytkownik::getImie() {

    return this->imie;
}

string Uzytkownik::getNazwisko() {
    return this->nazwisko;
}

string Uzytkownik::getLogin() {
    return this->login;
}

string Uzytkownik::getHaslo() {
    return this->haslo;
}

bool Uzytkownik::sprawdzHaslo(string haslo) {
    return this->haslo == haslo;
}

void Uzytkownik::setImie(string imie) {
    this->imie = imie;
}

void Uzytkownik::setNazwisko(string nazwisko) {
    this->nazwisko = nazwisko;
}

void Uzytkownik::setLogin(string login) {
    this->login = login;
}

void Uzytkownik::setHaslo(string haslo) {
    this->haslo = haslo;
}

void Uzytkownik::wyswietlUzytkownika() {
    cout << "Imie: " << this->imie << endl;
    cout << "Nazwisko: " << this->nazwisko << endl;
    cout << "Login: " << this->login << endl;
    cout << "Haslo: " << this->haslo << endl;
}

