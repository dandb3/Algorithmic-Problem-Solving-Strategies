#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int n, m;
double dp[1001][1001];

double probability(int height, int day);

int main() {
	FASTIO;

	cout << fixed;
	cout.precision(9);


	int test;
	cin >> test;
	while (test--) {
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = -1;
			}
		}
		cout << probability(n, m) << '\n';
	}

	return 0;
}

double probability(int height, int day) {
	if (height <= 0)
		return 1;
	double& ret = dp[height][day];
	if (ret != -1)
		return ret;
	if (day == 0) {
		return ret = 0;
	}
	return ret = 0.25 * probability(height - 1, day - 1) + 0.75 * probability(height - 2, day - 1);
}