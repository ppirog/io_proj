//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : System.h
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#if !defined(_SYSTEM_H)
#define _SYSTEM_H

#include <string>
#include <vector>
#include <map>
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

class System {
public:
	System(string nazwa);
	bool zaloguj(string login, string haslo);
	void dodajWydzial(Wydzial* wydzial);
	void wyswietlWydzialy();
	void usunWydzial(string nazwa);
	void dodajStudenta(Student* student);
	void wyswietlStudentow();
	void usunStudenta(Student* student);
	bool wyloguj(string login, string haslo);
    bool dodajDoZalogowanych(string login, string haslo);
    bool czyJestStudentem(string login, string haslo);
private:
	vector<Wydzial*> wydzialy;
	map<string,string> zalogowani;
	string nazwa;
	vector<Student*> studenci;

};

#endif  //_SYSTEM_H