#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include  <string>
#include <locale>
using namespace std;


class Book
{
private:
    int     page_count;
    string  author;
    string  name;
    string* str;
public:
    Book()
    {
        page_count = 1;
        str = new string[page_count];
        author = "Unknown";
        name = "No";
        *str = "Без негатива.";

    }
    Book(int page_count, string author, string name)
    {
        this->page_count = page_count;
        str = new string[page_count];
        this->author = author;
        this->name = name;

        for (int i = 0; i < page_count; i++)
        {
            for (int i = 0; i < page_count; i++)
            {
                char temp[10];
                for (int j = 0; j < 10; j++)
                    temp[j] = rand() % 26 + 97;
                *(str + i) = temp;
            }
        }
    }


    Book(const Book& nbook)
    {
        page_count = nbook.page_count;
        author = nbook.author;
        name = nbook.name;
        *str = *nbook.str;
    }


    ~Book()
    {
        cout << "*** Деструктор сработал ***" << endl;
    }


    void set_book_data(int page_count, string author, string name)
    {
        this->page_count = page_count;
        delete str;
        str = new string[page_count];
        this->author = author;
        this->name = name;
    }


    int print_page(int n)
    {
        if (n > page_count)
        {
            cout << "Страницы с номером " << n << " нет в книге!" << endl << endl << endl;
            return 0;
        }

        cout << "Содержимое страницы номер " << n << ":\n" << "========================================" << endl << *(str + n - 1) << endl;
        cout << "========================================" << endl << endl << endl;
        return 0;
    }


    void print_random_page()
    {
        int n = rand() % page_count;
        cout << "Случайная страница номер " << n << ":\n" << "========================================" << endl << *(str + n - 1) << endl;
        cout << "=========================================|" << endl << endl << endl;
    }


    int snatch_page(int n)
    {
        if (n > page_count)
        {
            cout << "Страницы с номером " << n << " нет в книге!" << endl << endl << endl;
            return 0;
        }

        string* temp_str;
        temp_str = new string[page_count - 1];
        int i = 0;
        int j = 0;
        for (i, j; i < n - 1; i++, j++)
            *(temp_str + i) = *(str + j);
        j++;
        for (i, j; i < (page_count - 1); i++, j++)
            *(temp_str + i) = *(str + j);
        str = temp_str;
        page_count -= 1;
        cout << "!!! Страница " << n << " успешно вырвана !!!\n" << endl << endl;
        return 0;
    }


    int paste_page(int n, string text)
    {
        if (n > page_count + 1)
        {
            cout << "Нельзя вклеить станицу в это место!" << endl << endl << endl;
            return 0;
        }

        string* temp_str;
        temp_str = new string[page_count + 1];
        int i = 0;
        int j = 0;
        for (i, j; i < n - 1; i++, j++)
            *(temp_str + i) = *(str + j);
        *(temp_str + n - 1) = text;
        i += 2;
        j++;
        for (i, j; i < (page_count + 1); i++, j++)
            *(temp_str + i) = *(str + j);
        str = temp_str;
        page_count += 1;
        cout << "!!! Страница успешно вклеена на месте станицы " << n << " !!!\n" << endl << endl;
        return 0;
    }


    void comb_temp()
    {
        cout << "Температура горения бумаги составляет 450 °С!" << endl << endl;
    }

};