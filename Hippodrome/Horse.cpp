#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include "Horse.h"


Hippodrome::Hippodrome(const char* Horse_name_, const char* Horse_breed_, const char* Horse_birth_day_, unsigned short Wins_number_, unsigned short Number_) {
    strcpy(Horse_name, Horse_name_);
    strcpy(Horse_breed, Horse_breed_);
    strcpy(Horse_birth_day, Horse_birth_day_);
    Wins_number = Wins_number_;
    Number = Number_;
}

const char* Hippodrome::get_name() { return Horse_name; }    //метод, отдающий имя
const char* Hippodrome::get_breed() { return Horse_breed; }    //метод, отдающий возраст
const char* Hippodrome::get_birthday() { return Horse_birth_day; }    //метод, отдающий имя
unsigned short   Hippodrome::get_wins_number() { return Wins_number; }    //метод, отдающий возраст
unsigned short Hippodrome::get_number() { return Number; }    //метод, отдающий имя

void Hippodrome::increase()
{
    Wins_number++;
}

void Hippodrome::show()
{
    std::cout << Horse_name << "  ";
    std::cout << Horse_breed << "  ";
    std::cout << Horse_birth_day << "  ";
    std::cout << Wins_number << "  ";
    std::cout << Number << "  ";
    std::cout << "\n";
}
