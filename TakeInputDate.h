#include <iostream>
#include <cctype>
#include <string>
#include "ThrowError.h"

bool IsLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
    return false;
}

bool CheckIfValidDate(std::string dat) {
    if (dat.size() != 10) {
        ThrowError("Wrong size!");
        return false;
    }
    if (dat[2] != '.' || dat[5] != '.') {
        ThrowError("Invalid dots position!");
        return false;
    }
    if (!isdigit(dat[0]) || !isdigit(dat[1]) || !isdigit(dat[3]) || !isdigit(dat[4]) || !isdigit(dat[6]) || !isdigit(dat[7]) || !isdigit(dat[8]) || !isdigit(dat[9])) {
        ThrowError("Invalid input!");
        return false;
    }
    return true;
}

bool CheckDat(std::string dat) {
    if (CheckIfValidDate(dat)) {
        int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int intd = stoi(dat.substr(0, 2));
        int intm = stoi(dat.substr(3, 2));
        int inty = stoi(dat.substr(6, 4));

        if (IsLeapYear(inty)) {
            months[1] = 29;
        }
        if (inty < 1900 || inty > 2010) {
            ThrowError("Invalid year!");
            return false;
        }
        if (intm < 1 || intm > 12) {
            ThrowError("Invalid month!");
            return false;
        }
        if (intd > months[intm - 1] || intd < 1) {
            ThrowError("Invalid date!");
            return false;
        }
        return true;
    }
    return false;
}

std::string TakeInputDate() {
    std::string input;
    do {
        std::cout << "Input the date: ";
        std::cin >> input;
    } while (!CheckDat(input));
    return input;
}

//int main() {
//    std::string date = TakeInputDate();
//    std::cout << std::endl << date << std::endl;
//    return 0;
//}