#pragma warning(disable : 4996)

#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "Horse.h"
#include <string>
#include <fstream>

using namespace std;
using namespace sf;

void try_to_modify(Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
void reading(Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
void running(RenderWindow& window, Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
void writing(Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
Sprite makeSpr(const sf::Texture& tex, int x, int y);
Text settext(string text, int x, int y);
void menu(RenderWindow& window, Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
void scoreboard(RenderWindow& window, Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
int check_array(int arr[5]);

void print_winners(RenderWindow& window, int massiv[5], Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
void print_winners2(RenderWindow& window, int massiv[5], Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth);
void main()
{

    //Hippodrome first{ "Jack", "American ", "05.06.00 " , 0,1 };
    // Hippodrome second{ "Mona", "Barb horse", "06.02.01" , 0,2 };
    // Hippodrome third{ "Lucy", "Calabrese ", "14.07.05" , 0,3 };
    // Hippodrome fourth{ "Bobby", "Colorado ", "27.03.07" , 0,4 };
    // Hippodrome fiveth{ "Harry", "Oldenburger", "30.12.99" , 0,5 };
    Hippodrome first;
    Hippodrome second;
    Hippodrome third;
    Hippodrome fourth;
    Hippodrome fiveth;
    RenderWindow window(VideoMode(1250, 590), "Test!", sf::Style::Close);
    Event event;

    reading(first, second, third, fourth, fiveth);

    //try_to_modify(first, second, third, fourth, fiveth);
   // writing(first, second, third, fourth, fiveth);
   //try_to_modify(first, second, third, fourth, fiveth);

   // reading(first, second, third, fourth, fiveth);

   // try_to_modify(first, second, third, fourth, fiveth);

   // running(first, second, third, fourth, fiveth);


    menu(window, first, second, third, fourth, fiveth);

}

void writing(Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{
    std::ofstream ofs("text.txt", std::ios::binary);
    ofs.write(reinterpret_cast<char*>(&first), sizeof(Hippodrome));
    ofs.write(reinterpret_cast<char*>(&second), sizeof(Hippodrome));
    ofs.write(reinterpret_cast<char*>(&third), sizeof(Hippodrome));
    ofs.write(reinterpret_cast<char*>(&fourth), sizeof(Hippodrome));
    ofs.write(reinterpret_cast<char*>(&fiveth), sizeof(Hippodrome));
    ofs.close();
}

void try_to_modify(Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{


    first.show();

    second.show();

    third.show();

    fourth.show();

    fiveth.show();


    //  writing(first, second, third, fourth, fiveth);

}

void reading(Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{
    std::ifstream ifs("text.txt", std::ios::binary);
    if (!ifs) { std::cerr << "File not found"; }

    ifs.read(reinterpret_cast<char*>(&first), sizeof(Hippodrome));
    ifs.read(reinterpret_cast<char*>(&second), sizeof(Hippodrome));
    ifs.read(reinterpret_cast<char*>(&third), sizeof(Hippodrome));
    ifs.read(reinterpret_cast<char*>(&fourth), sizeof(Hippodrome));
    ifs.read(reinterpret_cast<char*>(&fiveth), sizeof(Hippodrome));

    ifs.close();

}

void running(RenderWindow& window, Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{

    int counter = 1;
    int a[5] = { 0,0,0,0,0 }, i = 0, j = 0, b = 0, c = 0;
    Event event;
    Texture texture, finish;
    Sprite star, fin;
    Text win, text;
    Font font;
    string choice;
    bool flag, flag2 = 0;
    int n = 0;
    flag = 0;
    font.loadFromFile("20011.ttf");
    int counter2 = 0;
    unsigned short horse_choice = 0;
    int score = 5;
    int winners[5] = { 0,0,0,0,0 };
    int index = 0;

    bool flag1[5] = { 0,0,0,0,0 };




    bool isMenu = 1;
    int menuNum = 0;
    Text horse1, horse2, horse3, horse4, horse5;
    const char* names[5] = { first.get_name(),second.get_name(),third.get_name(),fourth.get_name(),fiveth.get_name() };
    Text horses_names[5] = { horse1, horse2, horse3, horse4, horse5 };

    for (i = 0, j = 105; i < 5; i++, j += 70) {

        horses_names[i] = settext(names[i], 910, j);
        horses_names[i].setFont(font);

    }

    while (isMenu)
    {

        for (i = 0; i < 5; i++) {
            horses_names[i].setColor(Color::White);
        }
        menuNum = 0;
        window.clear(Color(23, 114, 69));



        for (i = 0, j = 105; i < 5; i++, j += 70) { if (IntRect(910, j, 300, 50).contains(Mouse::getPosition(window))) { horses_names[i].setColor(Color::Yellow); menuNum = i + 1; } }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            for (i = 0; i < 5; i++) {
                if (menuNum == i + 1) { horse_choice = i; isMenu = false; }// 
            }
        }
        for (i = 0; i < 5; i++) {

            window.draw(horses_names[i]);
        }

        window.display();
    }


    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    finish.loadFromFile("track.png");
    fin.setTexture(finish);
    star.setTexture(finish);




    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }

    for (counter2 = 0; counter2 < 5; counter2++)
    {
        print_winners(window, winners, first, second, third, fourth, fiveth);
        while (!Keyboard::isKeyPressed(Keyboard::Escape));
        for (i = 0; i < 5;i++) {
            a[i] = flag1[i] = 0;
            score = 5;
        }
        while (a[0] < 790 || a[1] < 790 || a[2] < 790 || a[3] < 790 || a[4] < 790 || flag1[0] != 1 || flag1[1] != 1 || flag1[2] != 1 || flag1[3] != 1 || flag1[4] != 1)
        {
            sleep(milliseconds(45));
            for (i = 0, j = 100; i < 5; i++, j += 70) {
                if (a[i] > 790 && flag1[i] == 0)
                {

                    flag1[i] = 1;

                    winners[i] += score;

                    score--;

                }
                else if (a[i] > 790 && flag1[i] == 1)
                {
                    a[i] = a[i];
                }
                else if (a[i] > 790 && flag2 == 0)
                {
                    n = i + 1;
                    flag2 = 1;
                }
                else
                {
                    a[i] += rand() / 500;
                }




            }
            window.clear(Color(23, 114, 69));
            fin.setPosition(800, 120);
            window.draw(fin);

            star.setPosition(100, 120);
            window.draw(star);
            for (i = 0, j = 100; i < 5; i++, j += 70)
            {
                if (a[i] >= 790 && flag == 0)
                {
                    texture.loadFromFile(to_string(counter) + ".png");
                    window.draw(makeSpr(texture, a[i], j));
                    n = i + 1;
                    flag = 1;

                }
                else if (a[i] >= 790 && flag == 1)
                {
                    texture.loadFromFile(to_string(counter) + ".png");
                    window.draw(makeSpr(texture, a[i], j));

                }
                else
                {
                    texture.loadFromFile(to_string(counter) + ".png");
                    window.draw(makeSpr(texture, a[i], j));
                }
                for (b = 0, c = 105; b < 5; b++, c += 70)
                {
                    text = settext(names[b], 910, c);
                    if (b == horse_choice)
                    {
                        text.setColor(Color::Blue);
                    }
                    text.setFont(font);
                    window.draw(text);
                }

            }

            window.display();

            counter == 10 ? counter = 1 : counter++;


        }
    }
    int max = 0;




    check_array(winners) == winners[0] ? first.increase(), max = 100 : max = max;
    check_array(winners) == winners[1] ? second.increase(), max = 170 : max = max;
    check_array(winners) == winners[2] ? third.increase(), max = 250 : max = max;
    check_array(winners) == winners[3] ? fourth.increase(), max = 320 : max = max;
    check_array(winners) == winners[4] ? fiveth.increase(), max = 390 : max = max;

    //  text = settext("Win", 1100, max);
    //  text.setFont(font);
    //  window.draw(text);

      //window.display();
    writing(first, second, third, fourth, fiveth);
    for (i = 0; i < 5; i++)
    {
        cout << "\n" << winners[i];
    }

    if (check_array(winners) == winners[horse_choice])
    {
        text = settext("You Win", 500, 100);
        text.setFont(font);
        window.draw(text);


    }
    else
    {
        text = settext("You lose", 500, 100);
        text.setFont(font);
        window.draw(text);


    }
    print_winners2(window, winners, first, second, third, fourth, fiveth);



    while (!Keyboard::isKeyPressed(Keyboard::Escape));

}

Sprite makeSpr(const Texture& tex, int x, int y) {
    Sprite spr;
    spr.setTexture(tex);

    spr.setPosition(x, y);
    return spr;
}

Text settext(string text, int x, int y) {
    Text text5;


    text5.setString(text);

    text5.setCharacterSize(40);

    text5.setFillColor(sf::Color::Red);

    text5.setStyle(sf::Text::Bold);
    text5.setPosition(x, y);
    return text5;
}


void menu(RenderWindow& window, Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth) {
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
    menuTexture1.loadFromFile("111.png");
    menuTexture2.loadFromFile("222.png");
    menuTexture3.loadFromFile("444.png");
    aboutTexture.loadFromFile("leaderboard.jpg");
    menuBackground.loadFromFile("back.jpg");
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(100, 30);
    menu2.setPosition(100, 90);
    menu3.setPosition(100, 150);

    menuBg.setPosition(0, 0);
    //////////////////////////////МЕНЮ///////////////////
    while (isMenu)
    {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);

        menuNum = 0;
        window.clear(Color(129, 181, 221));
        if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
        if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
        if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1)  running(window, first, second, third, fourth, fiveth);//если нажали первую кнопку, то выходим из меню 
            if (menuNum == 2) { window.draw(about);  scoreboard(window, first, second, third, fourth, fiveth); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
            if (menuNum == 3) { window.close(); isMenu = false; }

        }
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.display();
    }
    ////////////////////////////////////////////////////
}


void scoreboard(RenderWindow& window, Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{
    Font font;
    Text first_text, second_text, third_text, fourth_text, fifth_text;
    font.loadFromFile("20011.ttf");
    const char* names[5] = { first.get_name(),second.get_name(),third.get_name(),fourth.get_name(),fiveth.get_name() };
    const char* breed[5] = { first.get_breed(),second.get_breed(),third.get_breed(),fourth.get_breed(),fiveth.get_breed() };
    const char* birth[5] = { first.get_birthday(),second.get_birthday(),third.get_birthday(),fourth.get_birthday(),fiveth.get_birthday() };
    int wins[5] = { first.get_wins_number(),second.get_wins_number(),third.get_wins_number(),fourth.get_wins_number(),fiveth.get_wins_number() };
    for (int i = 0, j = 130; i < 5; i++, j += 100)
    {
        first_text = settext(names[i], 150, j);
        first_text.setFont(font);
        window.draw(first_text);
        first_text = settext(breed[i], 515, j);
        first_text.setFont(font);
        window.draw(first_text);
        first_text = settext(birth[i], 892, j);
        first_text.setFont(font);
        window.draw(first_text);
        first_text = settext(to_string(wins[i]), 1083, j);
        first_text.setFont(font);
        window.draw(first_text);
    }



}

int check_array(int arr[5])
{
    int max = arr[0];
    for (int i = 0; i < 5; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;

}

void print_winners(RenderWindow& window, int massiv[5], Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{
    Font font;
    Text text;
    int i;
    int j;
    font.loadFromFile("20011.ttf");
    const char* names[5] = { first.get_name(),second.get_name(),third.get_name(),fourth.get_name(),fiveth.get_name() };


    for (i = 0, j = 110; i < 5; i++, j += 70)
    {
        text = settext(to_string(massiv[i]), 1150, j);
        text.setFont(font);
        window.draw(text);

    }

    window.display();

}


void print_winners2(RenderWindow& window, int massiv[5], Hippodrome& first, Hippodrome& second, Hippodrome& third, Hippodrome& fourth, Hippodrome& fiveth)
{
    Font font;
    Text text;
    int i;
    int j;
    int a = 0;
    string path = "";
    font.loadFromFile("20011.ttf");
    const char* names[5] = { first.get_name(),second.get_name(),third.get_name(),fourth.get_name(),fiveth.get_name() };
    path = to_string(a) + ".txt";
    ifstream number("number.txt");
    number >> a;
    number.close();
    path = "results/" + to_string(a) + ".txt";
    std::ofstream out(path, std::ios::app);

    for (i = 0, j = 110; i < 5; i++, j += 70)
    {
        text = settext(to_string(massiv[i]), 1150, j);
        text.setFont(font);
        window.draw(text);
        out << names[i] << " " << massiv[i] << "\n";
    }
    out << "\n";
    window.display();
    a++;
    ofstream number1("number.txt");
    number1 << a;
    number1.close();
    out.close();
}
