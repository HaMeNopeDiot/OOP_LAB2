#include <iostream>
#include "OOP_L2.h"
#include <Windows.h>
#include <fstream>

void menu();
Fractional inputNum();

int main()
{
    SetConsoleOutputCP(1251);
    int choise;
    std::cout << "Введите 1 число:"; //0.0001        *10000 ->round
    Fractional First = inputNum();
    std::cout << "Введите 2 число:";
    Fractional Second = inputNum();
    Fractional Result;
    do
    {
        std::cout << "-----------------------" << '\n';
        First.output();
        Second.output();
        Result.output();
        std::cout << "-----------------------" << '\n';
        menu();
        std::cin >> choise;
        switch (choise)
        {
        case 1:
        {
            Result = First + Second;
            //a+b
        }break;
        case 2:
        {
            //a-b
            Result = First - Second;
        }break;
        case 3:
        {
            //a*b
            Result = First * Second;
        }break;
        case 4:
        {
            //a/b
            Result = First / Second;
        }break;
        case 5:
        {
            //a==b
            if (First == Second)
                std::cout << "A equal B" <<'\n';
            else
                std::cout << "A not equal B" << '\n';
        }break;
        case 6:
        {
            if (First < Second)
                std::cout << "Yes" << '\n';
            else
                std::cout << "No" << '\n';
        }break;
        case 7:
        {
            if (First > Second)
                std::cout << "Yes" << '\n';
            else
                std::cout << "No" << '\n';
        }break;
        case 8:
        {
            Result += First;
        }break;
        case 9:
        {
            Result -= First;
        }break;
        case 10:
        {
            Result *= First;
        }break;
        case 11:
        {
            Result /= First;
        }break;
        case 12:
        {
            Result = First;
        }break;
        case 13:
        {
            Result = Second;
        }break;
        case 14:
        {
            std::cout << "Завершение работы" << '\n';
        }break;
        default:
        {
            std::cout << "Некорректный ввод!"<<'\n';
        }break;
        }

    } while (choise != 14);
    return 0;
}

Fractional inputNum()
{
    float realNum; //2.53 -> 2 53 //0.0001        *10000 ->round
    std::cin >> realNum;
    float accurNum = round(realNum * 10000)*1.0 / 10000;
    Fractional* S = new Fractional;
    return S->getRealNumberReverse(realNum);
}

void menu()
{
    std::cout << "Меню" << '\n';
    std::cout << "1." << "A+B" << '\n';
    std::cout << "2." << "A-B" << '\n';
    std::cout << "3." << "A*B" << '\n';
    std::cout << "4." << "A/B" << '\n';
    std::cout << "5." << "A==B" << '\n';
    std::cout << "6." << "A<B" << '\n';
    std::cout << "7." << "A>B" << '\n';
    std::cout << "8." << "C+=A" << '\n';
    std::cout << "9." << "C-=A" << '\n';
    std::cout << "10." << "C*=A" << '\n';
    std::cout << "11." << "C/=A" << '\n';
    std::cout << "12." << "C=A" << '\n';
    std::cout << "13." << "C=B" << '\n';
    std::cout << "14." << "Выход" << '\n';
}

//47 26cтр Лаптев