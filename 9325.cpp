#include <iostream>
#include <string>

using namespace std;

int main() {
	int testNum;
	int carPrice, opNum;
	int opPrice = 0;
	string tmp = "";

	cin >> testNum;
	for (int i = 0; i < testNum; i++) {
		cin >> carPrice;
		cin >> opNum;
		for (int j = 0; j < opNum; j++) {
			int a, b;
			cin >> a >> b;
			opPrice += a * b;
		}
		carPrice += opPrice;
		opPrice = 0;
		tmp += to_string(carPrice) + "\n";
	}
	cout << tmp;
}