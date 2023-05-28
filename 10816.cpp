#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	//cin >> N;
	scanf("%d", &N);
	int* card = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &card[i]);
	scanf("%d", &M);
	int* find = new int[M];
	for (int i = 0; i < M; i++) scanf("%d", &find[i]);

	sort(card, card + N);

	/*for (int i = 0; i < N; i++) {
		cout << card[i] << " ";
	}
	cout << endl;*/

	int start, end;

	int point;
	int count;
	int lower, upper;
	if (N == 1) {
		for (int i = 0; i < M; i++) {
			count = 0;
			if (card[0] == find[i]) {
				count++;
			}
			cout << count << " ";
		}
	}
	for (int i = 0; i < M; i++) {
		//Lower bound
		start = 0, end = N - 1;
		while (start < end) {
			point = (start + end) / 2;
			if (card[point] >= find[i]) {
				end = point;
			}
			else {
				start = point + 1;
			}
		}
		lower = end;

		//Upper bound
		start = 0, end = N - 1;
		while (start < end) {
			point = (start + end) / 2;
			if (card[point] > find[i]) {
				end = point;
			}
			else {
				start = point + 1;
			}
		}
		upper = end;
		if (upper == N - 1 && card[N - 1] == find[i]) upper++;
		//cout << find[i] << ": lower => " << lower << ", upper => " << upper << endl;
		cout << (upper - lower) << " ";
	}
	
	delete[] card;
	delete[] find;

	return 0;
}