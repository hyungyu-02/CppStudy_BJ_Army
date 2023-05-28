#include <iostream>
#include <string>

using namespace std;

int main() {
	int testNum;
	int c, v, d; // c : 사탕의 개수, v : 형제의 수
	string str = "";

	cin >> testNum;

	for (int i = 0; i < testNum; i++) {
		cin >> c >> v;
		d = c % v;
		str += "You get " + to_string(c / v) + " piece(s) and your dad gets " + to_string(d) + " piece(s).\n";
	}
	cout << str;

	return 0;
}