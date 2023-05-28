#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 3> myarr;
	for (int i = 0; i < myarr.size(); i++) {
		cin >> myarr[i];
	}

	//insert sort
	for (int i = 1; i < myarr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (myarr[i] < myarr[j]) {
				int tmp = myarr[i];
				for (int x = i-1; x >= j; x--) {
					myarr[x + 1] = myarr[x];
				}
				myarr[j] = tmp;
				break;
			}
		}
	}

	for (int i = 0; i < myarr.size(); i++) {
		cout << myarr[i] << " ";
	}

	return 0;
}