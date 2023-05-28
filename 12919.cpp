#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

//int abGame(string s, string t);
void abGame(string s, string t);

int main() {
	string S;
	cin >> S;
	string T;
	cin >> T;

	abGame(S, T);
	cout << 0 << endl;

	return 0;
}

string temp = "";

void abGame(string s, string t) {
	if (s == t) {
		cout << 1 << endl;
		exit(0);
	}
	if (s.size() >= t.size())
		return;

	if (t[t.size() - 1] == 'A') {
		temp = t;
		temp.erase(temp.size() - 1);
		abGame(s, temp);
	}
	if (t[0] == 'B') {
		temp = t;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		abGame(s, temp);
	}
}

//int abGame(string s, string t) {
//	if (s == t) {
//		return 1;
//	}
//	if (s.size() >= t.size())
//		return 0;
//
//	if (t[t.size() - 1] == 'A') {
//		temp = t;
//		temp.erase(temp.size() - 1);
//		return abGame(s, temp);
//	}
//	if (t[0] == 'B') {
//		temp = t;
//		temp.erase(temp.begin());
//		reverse(temp.begin(), temp.end());
//		return abGame(s, temp);
//	}
//}