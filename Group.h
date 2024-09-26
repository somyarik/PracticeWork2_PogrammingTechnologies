#pragma once

#include <iostream>
#include "TakeInputDate.h"
#include "TakeInputSession.h"
#include "TakeInputName.h"

struct Group {
	std::string name = "Default name";
	std::string date = "00.00.0000";
	int ses[3] = {0, 0, 0};
	void FillGroup();
	void OutputGroup();
};

void Group::FillGroup(){
	name = TakeInputName();
	date = TakeInputDate();
	for (int i = 0; i < 3; i++) {
		ses[i] = TakeInputSession(std::to_string(i + 1));
	}
}

void Group::OutputGroup() {
	std::cout << " | " << "Name: " << name;
	for (int i = 0; i < 50 - name.length(); i++) {
		std::cout << ' ';
	}
	std::cout << " | " << "Date: " << date << " | " << "Grades: " << ses[0] << ", " << ses[1] << ", " << ses[2] << " | " << std::endl;
}