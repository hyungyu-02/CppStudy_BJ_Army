#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec(0);

	while (N >= 1) {
		vec.push_back(N % 10);
		N = N / 10;
	}
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i] < vec[j]) {
				int tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
			}
		}
	}
	//int num = 0;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}

	return 0;
}