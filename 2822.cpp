#include <iostream>

using namespace std;

int main() {
	int scores[8][3];
	for (int i = 0; i < 8; i++) {
		scores[i][0] = i + 1;
		scores[i][2] = 1;
		cin >> scores[i][1];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (scores[i][1] < scores[j][1]) {
				scores[i][2]++;
			}
		}
	}

	int total = 0;

	for (int i = 0; i < 8; i++) {
		if (scores[i][2] < 6)
			total += scores[i][1];
	}
	cout << total << "\n";
	for (int i = 0; i < 8; i++) {
		if (scores[i][2] < 6)
			cout << scores[i][0] << " ";
	}

	return 0;
}