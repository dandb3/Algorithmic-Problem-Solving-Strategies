#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int N;
int seq[501];
int DP[501];

int LIS(int idx);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		memset(DP, 0, sizeof(DP));
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> seq[i];
		}
		int maxLen = 0;
		for (int i = 0; i < N; i++) {
			maxLen = max(maxLen, LIS(i));
		}
		cout << maxLen << '\n';
	}

	return 0;
}

int LIS(int idx) {
	if (DP[idx]) {
		return DP[idx];
	}
	int result = 0;
	for (int i = idx + 1; i < N; i++) {
		if (seq[i] > seq[idx])
			result = max(result, LIS(i));
	}
	return DP[idx] = 1 + result;
}