#include<iostream>
#include<fstream>
#include"string.h"
using namespace std;
class Menu
{
public:
    void Main_menu()
    {
        cout << "########################## Main_Menu ##########################\n" << endl;
        cout << "press 1 to go to student menu\npress 2 to go to book menu";
    }
    void book_menu()
    {
        cout << "########################## Book_Menu ##########################\n" << endl;
        cout << "press 1 to new entry\n press 2 to modify new student \n press 3 to search \n press 4 for delete\n";
        cout << "press 5 for show all detals \n" << endl;
    }
    void student_menu()
    {
        cout << "########################## Student_Menu ##########################\n" << endl;
        cout << "press 1 to new entry\n press 2 to search  \n press 3 to view all \n press 4 for update\n";
        cout << "press 5 for delet" << endl;
    }
};
class stu
{
    char name[60];
    char id[30];
    char address[60];
    char old[30];

public:

    void  insert_stu()
    {
        /*char name[25];
        char id[6];
        char address[25];
        char old[5];*/

        fstream q;
        q.open("student.txt", ios::app);
        cin.ignore();
        cout << " \n name : ";
        cin.getline(name, 60);

        cout << " \n address : ";
        cin.getline(address, 60);

        cout << " \n id : ";
        cin.getline(id, 30);

        cout << " \n old : ";
        cin.getline(old, 30);

        q << name << '|' << address << '|' << id << '|' << old << '\n';
        //cout << "done !";
        q.close();
    }

    void search_stu()
    {
        fstream m;
        m.open("student.txt", ios::in);
        /*char name[25];
        char id[6];
        char address[25];
        char old[5];
        char book_read[25]*/
        char L[30];
        cout << " \n enter the id to search about it : ";

        cin.ignore();
        cin.getline(L, 30);
        int Y = 0;
        cout << " \n\t name \t  address \t id \t old\n";

        while (!m.eof())
        {
            m.getline(name, 60, '|');
            m.getline(address, 60, '|');
            m.getline(id, 30, '|');
            m.getline(old, 30);

            if (strcmp(id, L) == 0)
            {
                cout << "\n \t " << name << "\t" << address << "\t" << id << "\t" << old << '\n';
                Y = 1;
                break;
            }

        }
        if (Y == 0)
        {
            cout << " \n not found !\n";
        }
        m.close();
    }
    void view_all()
    {
        fstream stud;
        stud.open("student.txt", ios::in);

        cout << " \n\t name \taddress \t id \t old\n";
        while (!stud.eof())
        {
            stud.getline(name, 60, '|');
            stud.getline(address, 60, '|');
            stud.getline(id, 30, '|');
            stud.getline(old, 30);
            cout << "\n \t " << name << "\t" << address << "\t" << id << "\t" << old << endl;
        }
    }
    void Delete_stu()
    {
        fstream stud;
        fstream temp;
        stud.open("student.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char h[30];
        cin.ignore();
        cout << "\n \t enter id to delet the record" << endl;
        cin.getline(h, 30);
        while (!stud.eof())
        {
            stud.getline(name, 60, '|');
            stud.getline(address, 60, '|');
            stud.getline(id, 6, '|');
            stud.getline(old, 30);
            if (strcmp(id, h) == 0)
            {
                continue;
            }
            else
            {
                temp << name << '|' << address << '|' << old << '|' << id << endl;
            }

        }
        temp.close();
        stud.close();


        stud.open("student.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(name, 60, '|');
            temp.getline(address, 60, '|');
            temp.getline(id, 30, '|');
            temp.getline(old, 30);
            stud << name << '|' << address << '|' << old << '|' << id << endl;
        }
        temp.close();
        stud.close();
        remove("temp.txt");
        cout << "\ndone " << endl;;
    }
    void update_student()
    {

        fstream stud;
        fstream temp;
        stud.open("student.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char h[30];
        cin.ignore();
        cout << "\n \t enter id to update the record" << endl;
        cin.getline(h, 30);
        while (!stud.eof())
        {
            stud.getline(name, 60, '|');
            stud.getline(address, 60, '|');
            stud.getline(id, 30, '|');
            stud.getline(old, 30);
            if (strcmp(id, h) == 0)
            {
                cout << "enter the new value of record" << endl;
                cout << "\n name";
                cin.getline(name, 60);
                cout << "\n address";
                cin.getline(address, 60);
                cout << "\n id";
                cin.getline(id, 30);
                cout << "\n old";
                cin.getline(old, 30);
                temp << name << '|' << address << '|' << old << '|' << id << endl;
            }
            else
            {
                temp << name << '|' << address << '|' << old << '|' << id << endl;
            }

        }
        temp.close();
        stud.close();


        stud.open("student.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(name, 60, '|');
            temp.getline(address, 60, '|');
            temp.getline(id, 30, '|');
            temp.getline(old, 30);
            stud << name << '|' << address << '|' << old << '|' << id << endl;
        }
        temp.close();
        stud.close();
        remove("temp.txt");
        cout << "\ndone " << endl;;
    }
};
class book {
    char title[40];
    char book_id[6];
    char publisher[40];
    char price[6]; 


public:
    /*void Delete_stu()
    {
        string d;
        cout << "are you sure ?? y or n" << endl;
        cin >> d;
        if (d == "y")
        {

            ofstream m("student.txt");
            system("cls");
            cout << "succed" << endl;
            system("pause");
            m.close();
        }
    }*/
    void delete_book()
    {
        fstream books;
        fstream temp;
        books.open("booksdata.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char h[6];
        cin.ignore();
        cout << "\n \t enter the book_id to delet the record" << endl;
        cin.getline(h, 6);
        while (!books.eof())
        {
            books.getline(title, 40, '|');
            books.getline(publisher, 40, '|');
            books.getline(price, 6, '|');
            books.getline(book_id, 6);
            if (strcmp(book_id, h) == 0)
            {
                continue;
            }
            else
            {
                temp << title << '|' << publisher << '|' << book_id << '|' << price << endl;
            }

        }
        temp.close();
        books.close();


        books.open("bookdata.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(title, 40, '|');
            temp.getline(publisher, 40, '|');
            temp.getline(book_id, 6, '|');
            temp.getline(price, 6);
            books << title << '|' << publisher << '|' << price << '|' << book_id << endl;
        }
        temp.close();
        books.close();
        remove("temp.txt");
        cout << "\ndone " << endl;
    }
    void modify_book()
    {
        fstream books;
        fstream temp;
        books.open("booksdata.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char h[6];
        cin.ignore();
        cout << "\n \t enter the book_id to update the record" << endl;
        cin.getline(h, 6);
        while (!books.eof())
        {
            books.getline(title, 40, '|');
            books.getline(publisher, 40, '|');
            books.getline(price, 6, '|');
            books.getline(book_id, 6);
            if (strcmp(book_id, h) == 0)
            {
                cout << "enter the new value of record" << endl;
                cout << "\n title";
                cin.getline(title, 40);
                cout << "\n publisher";
                cin.getline(publisher, 40);
                cout << "\n book_id";
                cin.getline(book_id, 6);
                cout << "\n price";
                cin.getline(price, 6);
                temp << title << '|' << publisher << '|' << book_id << '|' << price << endl;
            }
            else
            {
                temp << title << '|' << publisher << '|' << book_id << '|' << price << endl;
            }

        }
        temp.close();
        books.close();


        books.open("bookdata.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(title, 40, '|');
            temp.getline(publisher, 40, '|');
            temp.getline(book_id, 6, '|');
            temp.getline(price, 6);
            books << title << '|' << publisher << '|' << price << '|' << book_id << endl;
        }
        temp.close();
        books.close();
        remove("temp.txt");
        cout << "\ndone " << endl;
    }
    void view_all()
    {
        fstream books;
        books.open("booksdata.txt", ios::in);

        cout << " \n\t title\tpublisher\t book_id\t price\n";
        while (!books.eof())
        {
            books.getline(title, 40, '|');

            books.getline(publisher, 40, '|');
            books.getline(book_id, 6, '|');
            books.getline(price, 6);
            cout << "\n \t " << title << "\t" << publisher << "\t" << book_id << "\t" << price << endl;

        }
    }
    void search_book()
    {
        fstream books;
        books.open("booksdata.txt", ios::in);
        /*char title[40];
       char book_id[6];
       char publisher[40];
       char price[6];
       int status;     //to know about  the status of book
       int issu_roll;  //to know about the roll of issu
       */
        char a[6];
        cout << " \n enter the book_id to search about it : ";
        cin.ignore();
        cin.getline(a, 6);
        int x = 0;
        cout << " \n\t title\t publisher\t book_id \t price \n";
        while (!books.eof())
        {
            books.getline(title, 40, '|');
            books.getline(publisher, 40, '|');
            books.getline(book_id, 6, '|');
            books.getline(price, 40);
            if (strcmp(book_id, a) == 0)
            {
                cout << "\n \t " << title << "\t" << publisher << "\t" << book_id << "\t" << price << endl;
                x = 1;
                break;
            }

        }
        if (x == 0)
        {
            cout << " \n not found !!!!\n";
        }
        books.close();
    }
    void  enter_book()
    {
        /*char title[40];
        char book_id[6];
        char publisher[40];
        char price[6];
        int status;     //to know about  the status of book
        int issu_roll;  //to know about the roll of issu
        */

        fstream q;
        q.open("booksdata.txt", ios::app);
        cin.ignore();
        cout << " \n title : ";
        cin.getline(title, 40);


        cout << " \n publisher : ";
        cin.getline(publisher, 40);


        cout << " \n book_id : ";
        cin.getline(book_id, 6);

        cout << " \n price : ";
        cin.getline(price, 6);

        q << title << '|' << publisher << '|' << book_id << '|' << price << '\n';
        //cout << "done !";
        q.close();
    }
};


int main()
{
    Menu m;
    bool cond = true;
    while (cond)
    {
        m.Main_menu();
        cout << "\n";
        cout << " student : 1 \n book : 2 \n ";
        int y;
        cin >> y;
        if (y == 1)
        {
            m.student_menu();
            cout << " insert : 1 \n search : 2 \n view_all : 3 \n update : 4 \n delete :  5 \n choose a num : ";
        }
        else
        {
            m.book_menu();
            cout << " insert : 1 \n search : 2 \n view_all : 3 \n update : 4 \n delete :  5 \n choose a num : ";
        }
        int c;
        cin >> c;

        stu a;
        book b;
        switch (c)
        {
        case 1:
            if (y == 1)
            {
                a.insert_stu();
                break;
            }
            else
            {
                b.enter_book();
                break;
            }

        case 2:
            if (y == 1)
            {
                a.search_stu();
                break;
            }
            else if (y == 2)
            {
                b.search_book();
                break;
            }

        case 3:
            if (y == 1)
            {
                a.view_all();
                break;
            }
            else
            {
                b.view_all();
                break;
            }
        case 4:
            if (y == 1)
            {
                a.update_student();
                break;
            }
            else
            {
                b.modify_book();
                break;
            }
        case 5:
            if (y == 1)
            {
                a.Delete_stu();
                break;
            }
            else
            {
                b.delete_book();
                break;
            }
        default:
            cout << " \n Wrong num \n";
        }
        cout << " if you want to continue to use program press ' y ' \n ";
        char z;
        cin >> z;
        if (z != 'y')
        {
            cond = false;
        }
    }
    return 0;
}