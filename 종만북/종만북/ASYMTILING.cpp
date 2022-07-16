#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

using namespace std;
using ll = long long;

int n;
int tiling[101], symTiling[101];

int symmetricTile(int len);
int tile(int len);

int main() {
	FASTIO;

	int test;
	cin >> test;
	memset(symTiling, -1, sizeof(symTiling));
	memset(tiling, -1, sizeof(tiling));
	while (test--) {
		cin >> n;
		int result = tile(n) - symmetricTile(n);
		if (result < 0)
			result += MOD;
		cout << result << '\n';
	}

	return 0;
}

int symmetricTile(int len) {
	if (len == 0 || len == 1 || len == 3)
		return 1;
	if (len == 2)
		return 2;
	int& ret = symTiling[len];
	if (ret != -1)
		return ret;
	return ret = (symmetricTile(len - 2) + symmetricTile(len - 4)) % MOD;
}

int tile(int len) {
	if (len <= 1)
		return 1;
	int& ret = tiling[len];
	if (ret != -1)
		return ret;
	return ret = (tile(len - 1) + tile(len - 2)) % MOD;
}