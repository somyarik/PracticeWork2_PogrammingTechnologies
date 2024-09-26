#pragma once
#include <iostream>
void ThrowError(std::string ErrorName) {
    std::cout << "ERROR: " << ErrorName << std::endl;
}