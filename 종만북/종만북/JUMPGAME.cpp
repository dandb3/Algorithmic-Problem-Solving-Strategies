#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int board[101][101], DP[101][101];

int jump(int row, int col, int n);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		memset(DP, -1, sizeof(DP));
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> board[i][j];
			}
		}

		if (jump(1, 1, n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

int jump(int row, int col, int n) {
	if (row > n || col > n)
		return 0;
	if (row == n && col == n)
		return 1;
	if (DP[row][col] == 1)
		return 1;
	if (DP[row][col] == 0)
		return 0;

	return DP[row][col] = jump(row + board[row][col], col, n) | jump(row, col + board[row][col], n);
}