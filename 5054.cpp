#include <iostream>
#include <string>

#define MAXINT 99
#define MININT 0

using namespace std;

int main() {
	int N;
	int min = MAXINT;
	int max = MININT;

	string str = "";

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int x;
			cin >> x;
			if (x > max) {
				max = x;
			}
			if (x < min) {
				min = x;
			}
		}
		str += to_string(2 * (max - min)) + "\n";
		min = MAXINT;
		max = MININT;
	}
	cout << str;
	return 0;
}