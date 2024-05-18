//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Kurs.h
//  @ Date : 17.05.2024
//  @ Author : 
//
//


#if !defined(_KURS_H)
#define _KURS_H

#include "Uzytkownik.h"
#include "Wydzial.h"
#include "Nauczyciel.h"
#include "Student.h"
#include "System.h"
#include "Kurs.h"


using namespace std;

class Wydzial;

class Kurs;
class System;
class Uzytkownik;

class Nauczyciel;
class Student;

class Kurs {
public:
	Kurs(string nazwa, Wydzial* wydzial);
	void dodajNauczyciel(Nauczyciel * nauczyciel);
	void dodajMaterialy(string tytul, string zawartosc);
	void dodajStudenta(Student* student);
	void wyswietlMaterialy();
	void usunMaterial(string tytul);
	void ocenStudentow();
	void setNazwa(string nazwa);
	string getNazwa();
    vector<Nauczyciel*> getNauczyciele();
    vector<Student*> getStudenci();
    void wyswietlOcenyStudentow();
    void wyswietlOcene(Student* student);
private:
	string nazwa;
	Wydzial* wydzial;
	vector<Nauczyciel*> nauczyciele;
	vector<Student*> studenci;
	map<Student*, int> oceny;
	map<string,string> materialy;
};

#endif  //_KURS_H
