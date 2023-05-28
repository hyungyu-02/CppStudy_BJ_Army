#include <iostream>
#include <cmath>
#define MAXINT 200

using namespace std;

int main() {
	int N;
	cin >> N;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	if ((abs(r1 - r2) % 2) != 0) {
		cout << "-1" << endl;
		return 0;
	}
	else {
		if ((abs(r1 - r2) % 4) == 0) {
			if ((abs(c1 - c2) % 2) != 0) {
				cout << "-1" << endl;
				return 0;
			}
		}
		else if ((abs(r1 - r2) % 4) == 2) {
			if ((abs(c1 - c2) % 2) != 1) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	int count = 0;
	int dist[6] = { MAXINT };
	int X[6];
	int Y[6];

	while (!((r1 == r2) && (c1 == c2))) {
		X[0] = r1; Y[0] = c1+2;
		X[1] = r1+2; Y[1] = c1+1;
		X[2] = r1+2; Y[2] = c1-1;
		X[3] = r1; Y[3] = c1-2;
		X[4] = r1-2; Y[4] = c1-1;
		X[5] = r1-2; Y[5] = c1+1;
		for (int i = 0; i < 6; i++) {
			dist[i] = (pow(X[i]-r2, 2)) + (pow(Y[i]-c2, 2));
		}
		int minIdx = 0;
		for (int i = 1; i < 6; i++) {
			if (dist[i] < dist[minIdx])
				minIdx = i;
		}
		r1 = X[minIdx]; c1 = Y[minIdx];
		count++;
	}

	cout << count << endl;

	return 0;
}