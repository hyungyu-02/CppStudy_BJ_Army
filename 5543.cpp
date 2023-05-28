#include <iostream>
#define MAXINT 2000

using namespace std;

int main() {
	int b = MAXINT;
	int d = MAXINT;

	for (int i = 0; i < 3; i++) {
		int burger;
		cin >> burger;
		if (burger < b)
			b = burger;
	}
	for (int i = 0; i < 2; i++) {
		int drink;
		cin >> drink;
		if (drink < d)
			d = drink;
	}

	cout << (b + d - 50);
	return 0;
}