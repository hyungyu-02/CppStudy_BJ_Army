#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 5> arr;
	int s = 0;

	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
		s += arr[i];
	}
	s = s / (arr.size());
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	cout << s << "\n" << arr[arr.size() / 2];

	return 0;
}