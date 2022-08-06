#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

vector<vector<int>> graph(51);
int cell;
double dp[51][101];

double probability(int town, int day);

int main() {
	FASTIO;

	int test;
	cin >> test;
	cout << fixed;
	cout.precision(9);
	while (test--) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 101; j++) {
				dp[i][j] = -1;
			}
		}
		graph = vector<vector<int>>(51);
		int n, day, t, q, edge;
		cin >> n >> day >> cell;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> edge;
				if (edge) {
					graph[i].push_back(j);
				}
			}
		}
		cin >> t;
		for (int i = 0; i < t; i++) {
			cin >> q;
			cout << probability(q, day);
			if (i < t)
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}

double probability(int town, int day) {
	if (day == 0) {
		if (town == cell)
			return 1;
		else
			return 0;
	}
	double& ret = dp[town][day];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int near : graph[town]) {
		ret += probability(near, day - 1) / graph[near].size();
	}
	return ret;
}