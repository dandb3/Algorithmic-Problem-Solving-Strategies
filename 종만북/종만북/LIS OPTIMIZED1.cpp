#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int arr[501], dp[501];

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		dp[0] = 1;
		for (int i = 1; i < N; i++) {
			int maxLen = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i]) {
					maxLen = max(maxLen, dp[j]);
				}
			}
			dp[i] = maxLen + 1;
		}
		int result = 0;
		for (int i = 0; i < N; i++) {
			result = max(result, dp[i]);
		}
		cout << result << '\n';
	}

	return 0;
}

