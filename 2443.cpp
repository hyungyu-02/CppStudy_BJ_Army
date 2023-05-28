#include <iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int I = 0; I < i; I++) {
			cout << " ";
		}
		for (int j = 0; j < (2 * N) - (i * 2 + 1); j++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}