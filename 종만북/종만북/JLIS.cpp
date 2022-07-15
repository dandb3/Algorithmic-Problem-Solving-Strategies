#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int n, m;
int seqA[101], seqB[101], dp[101][101][2];

int jlis(int idxA, int idxB, int num);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> seqA[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> seqB[i];
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			result = max(result, jlis(i, 0, 0));
		}
		for (int i = 0; i < m; i++) {
			result = max(result, jlis(0, i, 1));
		}
		cout << result << '\n';
	}

	return 0;
}

int jlis(int idxA, int idxB, int num) {
	if (idxA == 0 && idxB == 0) {
		return max(jlis(1, 0, 0), jlis(0, 1, 1));
	}
	int& ret = dp[idxA][idxB][num];
	if (ret != -1) {
		return ret;
	}
	int cmp;
	if (!num)
		cmp = seqA[idxA - 1];
	else
		cmp = seqB[idxB - 1];
	int result = 0;
	for (int i = idxA; i < n; i++) {
		if (seqA[i] > cmp)
			result = max(result, jlis(i + 1, idxB, 0));
	}
	for (int i = idxB; i < m; i++) {
		if (seqB[i] > cmp)
			result = max(result, jlis(idxA, i + 1, 1));
	}
	return ret = result + 1;
}