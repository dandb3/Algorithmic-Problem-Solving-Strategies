#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 10000000

using namespace std;
using ll = long long;

int N;
int dp[101][101];

int cnt(int firstLine, int sqNum);

int main() {
	FASTIO;

	int test;
	cin >> test;
	memset(dp, -1, sizeof(dp));
	for (int TT = 1; TT <= test; TT++) {
		cin >> N;
		int result = 0;
		for (int i = 1; i <= N; i++) {
			result += cnt(i, N);
			result %= MOD;
		}
		cout << result << '\n';
	}

	return 0;
}

int cnt(int firstLine, int sqNum) {
	if (sqNum == firstLine)
		return 1;
	int& ret = dp[firstLine][sqNum];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 1; i <= sqNum - firstLine; i++) {
		ret += (firstLine + i - 1) * cnt(i, sqNum - firstLine);
		ret %= MOD;
	}
	return ret;
}