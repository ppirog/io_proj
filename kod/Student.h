//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Student.h
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#if !defined(_STUDENT_H)
#define _STUDENT_H

#include <string>
#include <vector>
#include <map>

#include "Wydzial.h"
#include "System.h"
#include "Kurs.h"
#include "Uzytkownik.h"
using namespace std;

class Wydzial;
class Nauczyciel;

class Kurs;
class System;

class Student : public Uzytkownik {
public:
	Student(string imie, string nazwisko, string login, string haslo);
	void dodajKurs(Kurs* kurs);
	void wyjdzZKursu(Kurs* kurs);
	void wyswietlKursy();
	int getIndeks();
	void setIndeks(int indeks);

    vector<Kurs *> getDolaczoneKursy();

private:
	vector<Kurs*> dolaczoneKursy;
	int indeks;
};

#endif  //_STUDENT_H
