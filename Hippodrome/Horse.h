#pragma once

class Hippodrome {
private:
    char  Horse_name[15];
    char Horse_breed[15];
    char  Horse_birth_day[15];
    unsigned short Wins_number;
    unsigned short Number;
public:

    Hippodrome(const char* Horse_name = "unknown", const char* Horse_breed = "unknown", const char* Horse_birth_day = "unknown", unsigned short Wins_number = 0, unsigned short Number = 0);
    Hippodrome(char*, char*, char*, unsigned short, unsigned short);
    const char* get_name();
    const char* get_breed();
    const char* get_birthday();
    unsigned short get_wins_number();
    unsigned short get_number();
    void increase();
    void show();
};
#pragma once
