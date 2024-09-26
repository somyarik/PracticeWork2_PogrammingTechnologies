#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include "ThrowError.h"

bool CheckIfValidName(std::string name) {
    if (name.length() > 50) {
        ThrowError("The name is too long!");
        return false;
    }
    return true;
}

std::string TakeInputName() {
    std::string input;
    do {
        std::cout << "Input the name: ";
        std::cin >> input;
    } while (!CheckIfValidName(input));
    return input;
}
