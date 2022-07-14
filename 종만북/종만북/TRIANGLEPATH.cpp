#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int triangle[101][101];
int DP[101][101];
int n;

int path(int row, int column);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		memset(DP, 0, sizeof(DP));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}

		cout << path(1, 1) << '\n';
	}


	return 0;
}

int path(int row, int column) {
	if (DP[row][column])
		return DP[row][column];
	if (row == n)
		return DP[row][column] = triangle[row][column];
	return DP[row][column] = triangle[row][column] + max(path(row + 1, column), path(row + 1, column + 1));
}