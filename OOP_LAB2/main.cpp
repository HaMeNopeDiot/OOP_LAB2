#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Calculator.h"

void menu();
Fractional inputNum();

int main()
{
    SetConsoleOutputCP(1251);
    int choise;
    Calculator mainObj;
    std::cout << "Введите 2 числа:"<<'\n';
    std::cin >> mainObj;
    Fractional Answer;
    do
    {
        menu();
        std::cin >> choise;
        switch (choise)
        {
        case 1:
        {
            std::cout << mainObj;
        }break;
        case 2:
        {
            std::cin >> mainObj;
        }break;
        case 3:
        {
            Answer = mainObj.plusNum();
            std::cout << "First+Second=" << Answer << '\n';
        }break;
        case 4:
        {
            Answer = mainObj.minusNum();
            std::cout << "First-Second=" << Answer << '\n';
        }break;
        case 5:
        {
            Answer = mainObj.multiplyNum();
            std::cout << "First*Second=" << Answer << '\n';
        }break;
        case 6:
        {
            Answer = mainObj.divideNum();
            std::cout << "First/Second=" << Answer << '\n';
        }break;
        case 7:
        {
            int situation = mainObj.compareNum();
            if (situation == 2)
                std::cout << "First>Second\n";
            if (situation == 1)
                std::cout << "First=Second\n";
            if (situation == 0)
                std::cout << "First<Second\n";
        }break;
        default:
        {
            if(choise!=0)
                std::cout << "Некорректный ввод!\n";
        }break;
        }
    } while (choise);
}



void menu()
{
    std::cout << "\nМеню" << '\n';
    std::cout << "1." << "Напечатать все:" << '\n';
    std::cout << "2." << "Обновить данные" << '\n';
    std::cout << "3." << "Сложение" << '\n';
    std::cout << "4." << "Вычитание" << '\n';
    std::cout << "5." << "Умножение" << '\n';
    std::cout << "6." << "Деление" << '\n';
    std::cout << "7." << "Сравнение" << '\n';
    std::cout << "0." << "Выход" << '\n';
}

//47 26cтр Лаптев

//14 62стр Лаптев 4 лаба