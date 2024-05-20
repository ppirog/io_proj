cmake_minimum_required(VERSION 3.28)
project(io_proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(kod)

add_executable(io_proj
        kod/main.cpp
        kod/Kurs.cpp
        kod/Nauczyciel.cpp
        kod/Student.cpp
        kod/System.cpp
        kod/Uzytkownik.cpp
        kod/Wydzial.cpp
        kod/Uzytkownik.h
        kod/Wydzial.h
        kod/System.h
        kod/Student.h
        kod/Nauczyciel.h
        kod/Kurs.h
        kod/Student.cpp
        kod/Student.h
        kod/testy/SystemTest.h
        kod/testy/SystemTest.cpp
)
