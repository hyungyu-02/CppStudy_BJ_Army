#include <iostream>
#include <vector>

using namespace std;

int main() {
	//array<int, 9> arr;
	vector<int> arr(9);
	int total = 0;
	int over;

	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
		total += arr[i];
	}
	over = total - 100;

	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] + arr[j] == over) {
				arr.erase(arr.begin() + i);
				arr.erase(arr.begin() + j - 1);
				for (int i = 0; i < arr.size(); i++) {
					cout << arr[i] << endl;
				}
				return 0;
			}
		}
	}


	return 0;
}