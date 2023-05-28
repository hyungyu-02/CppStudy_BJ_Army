#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int N;
	cin >> N;

	int a, b;
	int count = 0;
	
	vector<pair<int, int>> v;
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
	/*printf("정렬전 : \n");
	for (int i = 0; i < N; i++) {
		printf("%d : %d\n", v[i].first, v[i].second);
	}*/
	sort(v.begin(), v.end(), compare);
	/*printf("정렬후 : \n");
	for (int i = 0; i < N; i++) {
		printf("%d : %d\n", v[i].first, v[i].second);
	}*/
	int y = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first >= y) {
			y = v[i].second;
			count++;
		}
		else if (v[i].second < y) {
			y = v[i].second;
		}
	}

	cout << count << endl;

	return 0;
}