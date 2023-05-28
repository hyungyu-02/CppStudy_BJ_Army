#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	bool* ineq = new bool[N];
	char ineqsign;

	for (int i = 0; i < N; i++) {
		cin >> ineqsign;
		if (ineqsign == '<')
			ineq[i] = true;
		else
			ineq[i] = false;
	}

	int* low = new int[N + 1];
	int* high = new int[N + 1];

	for (int i = 0; i < N + 1; i++) {
		low[i] = i;
		high[i] = 9 - i;
	}
	/*cout << "high : ";
	for (int i = 0; i < N + 1; i++) {
		cout << high[i] << " ";
	}
	cout << endl;
	cout << "low : ";
	for (int i = 0; i < N + 1; i++) {
		cout << low[i] << " ";
	}
	cout << endl;*/

	bool clear = true;

	while (clear) {
		clear = false;
		for (int i = N - 1; i >= 0; i--) {
			if (ineq[i]) {
				if (low[i] > low[i + 1]) {
					int temp = low[i];
					low[i] = low[i + 1];
					low[i + 1] = temp;
					clear = true;
				}
				if (high[i] > high[i + 1]) {
					int temp = high[i];
					high[i] = high[i + 1];
					high[i + 1] = temp;
					clear = true;
				}
			}
			else {
				if (low[i] < low[i + 1]) {
					int temp = low[i];
					low[i] = low[i + 1];
					low[i + 1] = temp;
					clear = true;
				}
				if (high[i] < high[i + 1]) {
					int temp = high[i];
					high[i] = high[i + 1];
					high[i + 1] = temp;
					clear = true;
				}
			}
		}
	}

	string str = "";
	for (int i = 0; i < N + 1; i++) {
		str += to_string(high[i]);
	}
	str += "\n";
	for (int i = 0; i < N + 1; i++) {
		str += to_string(low[i]);
	}

	cout << str << endl;

	delete[] ineq;
	delete[] low;
	delete[] high;

	return 0;
}