#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

using namespace std;
using ll = long long;

int n;
int dp[101];

int tile(int len);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		cout << tile(n) << '\n';
	}

	return 0;
}

int tile(int len) {
	int& ret = dp[len];
	if (len < 0)
		return 0;
	if (len == 0)
		return 1;

	if (ret != -1)
		return ret;
	return ret = (tile(len - 1) + tile(len - 2)) % MOD;
}