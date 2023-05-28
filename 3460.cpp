#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	string str = "";

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int count = 0;
		while (x > 0) {
			int k = x % 2;
			if (k == 1)
				str += to_string(count) + " ";
			count++;
			x /= 2;
		}
		str += "\n";
	}

	cout << str;

	return 0;
}