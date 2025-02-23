#include "classes.h"

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include  <string>
#include <locale>
using namespace std;


void options_handler(int option, Book& my_book)
{
    string text;
    int n = 0;
    switch (option)
    {
    case 1:
        cout << "Введите номер страницы: " << endl;
        cin >> n;
        my_book.print_page(n);
        break;

    case 2:
        my_book.print_random_page();
        break;

    case 3:
        
        cout << "Введите номер страницы: " << endl;
        cin >> n;
        my_book.snatch_page(n);
        break;

    case 4:
        cout << "Введите номер страницы: " << endl;
        cin >> n;
        cout << "Введите текст страницы: " << endl;
        cin >> text;
        my_book.paste_page(n, text);
        break;

    case 5:
        my_book.comb_temp();
        break;

    default:
        cout << "Такой опции нет!";
        break;
    }
    


        
}


int main()
{
    setlocale(LC_ALL, "rus");
    int choise = 0;
    int page_count;
    string tmp;
    string name;
    string author;

    cout << "Создание новой книги:" << endl;
    cout << "|__ Введите название книги: ";
    cin >> name;
    cout<< "|____ Введите автора книги: ";
    cin >> author;
    cout<< "|______ Введите количество страниц в книге: ";
    cin >> tmp;
    page_count = stoi(tmp);
    
    Book my_book(page_count, author, name);
    cout << endl << "Книга  " << name << " успешно создана!" << endl << endl;
    while (choise != 6)
    {
        cout << "Выберите опцию: " << endl << "1 - Вывести страницу по номеру" << endl << "2 - Вывести случайную страницу" << endl << 
            "3 - Вырвать страницу" << endl << "4 - Вклеить новую страницу" << endl << "5 - Узнать температуру горения бумаги" << endl << "6 - Выйти" << endl << endl;
        cin >> choise;
        options_handler(choise, my_book);
    }
    
}
