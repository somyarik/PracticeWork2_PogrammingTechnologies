#include "Group.h"

const int CYCLE = 10;

void BubbleSort(Group* group) {
	for (int i = 0;i < CYCLE - 1;i++) {
		for (int j = 0;j < CYCLE - 1;j++) {
			if (group[j].ses[0] > group[j + 1].ses[0]) {
				std::swap(group[j], group[j + 1]);
			}
			else if (group[j].ses[1] > group[j + 1].ses[1] && group[j].ses[0] == group[j + 1].ses[0]) {
				std::swap(group[j], group[j + 1]);
			}
			else if (group[j].ses[2] > group[j + 1].ses[2] && group[j].ses[0] == group[j + 1].ses[0] && group[j].ses[1] == group[j + 1].ses[1]) {
				std::swap(group[j], group[j + 1]);
			}
		}
	}
}

bool CheckAge(Group group) {
	if (stoi(group.date.substr(6, 4)) >= 1990 || stoi(group.date.substr(6, 4)) >= 1989 && stoi(group.date.substr(3, 2)) == 12 && stoi(group.date.substr(0, 2)) != 1) return true;
	return false;
}

int main() {
	Group som[CYCLE];
	for (int i = 0;i < CYCLE;i++) {
		std::cout << "Group " << i + 1 << ':' << std::endl;
		som[i].FillGroup();
		std::cout << std::endl;
	}

	for (int i = 0;i < CYCLE;i++) {
		som[i].OutputGroup();
	}
	BubbleSort(som);
	std::cout << std::endl;
	for (int i = 0;i < CYCLE;i++) {
		som[i].OutputGroup();
	}

	std::cout << "Students with age less than 21: " << std::endl;
	for (int i = 0;i < CYCLE;i++) {
		if (CheckAge(som[i])) {
			som[i].OutputGroup();
		}
	}
	return 0;
}