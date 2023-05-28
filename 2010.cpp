#include <iostream>

using namespace std;

int main() {
	int concents;
	int total = 0;
	cin >> concents;
	for (int i = 0; i < concents; i++) {
		int a;
		cin >> a;
		total += a;
	}
	total = total - concents + 1;
	cout << total;

	return 0;
}