#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	long long N, M;
	cin >> N >> M;
	long long* tree = new long long[N];

	for (long long i = 0; i < N; i++) {
		cin >> tree[i];
	}
	sort(tree, tree + N, desc);

	long long cut, height;
	long long answer = -1;
	long long low = 0, high = tree[0];

	while (low <= high) {
		cut = (low + high) / 2;
		height = 0;
		for (int i = 0; i < N && tree[i] > cut; i++) {
			height += tree[i] - cut;
		}

		if (height >= M) {
			low = cut + 1;
			//if (cut > answer) 
			answer = cut;
		}
		else {
			high = cut - 1;
		}
	}
	
	
	cout << answer << endl;

	delete[] tree;
	return 0;
}