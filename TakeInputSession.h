#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include "ThrowError.h"

bool CheckIfValidSession(std::string session) {
	if (session != "1" && session != "2" && session != "3" && session != "4" && session != "5") {
		ThrowError("Invalid Input!");
		return false;
	}
	return true;
}

int TakeInputSession(std::string num) {
    std::string input;
    do {
        std::cout << "Input the grade " << num << ": ";
        std::cin >> input;
    } while (!CheckIfValidSession(input));
    return stoi(input);
}