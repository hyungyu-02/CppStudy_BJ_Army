#include<iostream>
#define MAXINT 1000000
#define MININT -1000000

using namespace std;

int main() {
	int N;
	int min = MAXINT;
	int max = MININT;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a > max) {
			max = a;
		}
		if (a < min) {
			min = a;
		}
	}
	cout << min * max;

	return 0;
}