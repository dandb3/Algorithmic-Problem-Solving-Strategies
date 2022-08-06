#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int height[20001];
int _left[20001], _right[20001];

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		int N;
		cin >> N;

		int i = 0;
		for (; i < N; i++) {
			cin >> height[i];
		}
		height[i] = 0;

		stack<int> sta;
		sta.push(0);
		for (int i = 1; i <= N; i++) {
			while (!sta.empty()) {
				if (height[sta.top()] >= height[i]) {
					int prevNode = sta.top();
					sta.pop();
					_right[prevNode] = i;
					if (sta.empty()) {
						_left[prevNode] = -1;
					}
					else {
						_left[prevNode] = sta.top();
					}
				}
				else
					break;
			}
			sta.push(i);
		}
		int result = 0;
		for (int i = 0; i < N; i++) {
			result = max(result, (_right[i] - _left[i] - 1) * height[i]);
		}
		cout << result << '\n';
	}


	return 0;
}