#include <iostream>

using namespace std;

int main() {
	int totalScore = 0;

	for (int i = 0; i < 5; i++) {
		int score;
		cin >> score;
		totalScore += score;
	}
	cout << totalScore;

	return 0;
}