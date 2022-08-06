#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		string str;
		cin >> str;

		bool good = true;
		stack<char> sta;
		for (char ch : str) {
			switch (ch) {
			case '(':
			case '{':
			case '[':
				sta.push(ch);
				break;
			case ')':
				if (sta.empty()) {
					good = false;
				}
				else {
					if (sta.top() + 1 == ch) {
						sta.pop();
					}
					else {
						good = false;
					}
				}
				break;
			default:
				if (sta.empty()) {
					good = false;
				}
				else {
					if (sta.top() + 2 == ch) {
						sta.pop();
					}
					else {
						good = false;
					}
				}
				break;
			}
			if (!good)
				break;
		}

		if (good && sta.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}