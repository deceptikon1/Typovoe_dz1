// Copyright 2015 <Sergey Fedotov>
#pragma warning(disable:4996)
#include "./all.h"


int main() {
    try {
        setlocale(LC_ALL, "rus");

        company one("FSO", true);
        cout << "Company:" << endl << endl;
        one.addworker(Worker("Susan", 19, 30000, 1, true));
        one.addworker(Worker("Samuel", 27, 6700, 5, true));
        one.addworker(Worker("Ivan", 30, 6300, 10, true));
         // one.addworker(Worker("Samuel", 27, 6700, 5, true));
        // - try exeption if you want

        one.delworkernum(2);
         // one.delworkernum(10);// - try exeption if you want

        cout << one;

        one.delworker(Worker("Samuel", 27, 6700, 5, true));
         // one.delworker(Worker("Jorge", 27, 6700, 5, true));
        // - try exeption if you want
        one.setcompany("KGB", false);

        cout << endl << one;

        cout << "Workers number - "<< one.getworkersnum();
         cout << endl << endl;

        cout << Worker("John", 123, 321, 555, true) +
            Worker("Sam", 50, 100, 222, false) +
            Worker("Greg", 50, 100, 222, false);
        _getch();
    }

    catch (const exception & msg) {
        cerr << msg.what();
    }
    catch (...) {
        cout << "Unknown excpetion";
    }
    _getch();
}
