#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

string items[101];
pair<int, int> info[101];
int dp[101][1001];

int knapsack(int idx, int W);
void itemIn(int idx, int W, vector<int>& itemList);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		vector<int> itemList;
		memset(dp, -1, sizeof(dp));
		int N, W;
		cin >> N >> W;
		for (int i = 0; i < N; i++) {
			cin >> items[i] >> info[i].first >> info[i].second;
		}
		cout << knapsack(N - 1, W) << ' ';
		itemIn(N - 1, W, itemList);
		cout << itemList.size() << '\n';
		for (auto it = itemList.rbegin(); it != itemList.rend(); it++) {
			cout << items[*it] << '\n';
		}
	}

	return 0;
}

int knapsack(int idx, int W) {
	if (idx == 0) {
		if (info[idx].first <= W)
			return info[idx].second;
		else
			return 0;
	}
	if (W == 0)
		return 0;
	int& ret = dp[idx][W];
	if (ret != -1)
		return ret;
	ret = knapsack(idx - 1, W);
	if (info[idx].first <= W) {
		ret = max(ret, info[idx].second + knapsack(idx - 1, W - info[idx].first));
	}
	return ret;
}

void itemIn(int idx, int W, vector<int>& itemList) {
	if (W == 0)
		return;
	if (idx == 0) {
		if (info[idx].first <= W)
			itemList.push_back(idx);
		return;
	}

	if (info[idx].first > W) {
		itemIn(idx - 1, W, itemList);
		return;
	}
	if (dp[idx - 1][W] < dp[idx][W]) {
		itemList.push_back(idx);
		itemIn(idx - 1, W - info[idx].first, itemList);
	}
	else
		itemIn(idx - 1, W, itemList);
}