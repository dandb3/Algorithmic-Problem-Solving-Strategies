#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int n;
int triangle[101][101];
pair<int, int> dp[101][101]; //dp[i][j].first : i, j부터 끝까지의 최댓값, dp[i][j].second : i, j부터 끝까지 최댓값을 갖는 경로의 수

pair<int, int> pathCnt(int i, int j);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				dp[i][j] = { -1, -1 };
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}

		cout << pathCnt(0, 0).second << '\n';
	}

	return 0;
}

pair<int, int> pathCnt(int i, int j) {
	pair<int, int>& ret = dp[i][j];
	if (ret != make_pair(-1, -1))
		return ret;
	if (i == n - 1)
		return ret = make_pair(triangle[i][j], 1);
	pair<int, int> tmp1, tmp2;
	tmp1 = pathCnt(i + 1, j);
	tmp2 = pathCnt(i + 1, j + 1);
	if (tmp1.first > tmp2.first) {
		return ret = make_pair(triangle[i][j] + tmp1.first, tmp1.second);
	}
	if (tmp1.first < tmp2.first) {
		return ret = make_pair(triangle[i][j] + tmp2.first, tmp2.second);
	}
	return ret = make_pair(triangle[i][j] + tmp2.first, tmp1.second + tmp2.second);
}