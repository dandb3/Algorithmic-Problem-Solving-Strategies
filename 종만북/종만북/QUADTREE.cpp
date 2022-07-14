#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int order[4] = { 2, 3, 0, 1 };

void append(vector<vector<int>>& child, int& idx, int node, string& str);
void findResult(vector<vector<int>>& child, string& result, int idx, string& str);

int main() {
	FASTIO;

	int C;
	cin >> C;
	while (C--) {
		string str;
		cin >> str;
		if (str.size() == 1) {
			cout << str << '\n';
			continue;
		}
		vector<vector<int>> child(str.size());

		int idx = 0;
		append(child, idx, 0, str);
		string result = "x";
		findResult(child, result, 0, str);
		cout << result << '\n';
	}

	return 0;
}

void append(vector<vector<int>>& child, int& idx, int node, string& str) {
	for (int j = 1; j <= 4; j++) {
		idx++;
		child[node].push_back(idx);
		if (str[idx] == 'x') {
			append(child, idx, idx, str);
		}
	}
}

void findResult(vector<vector<int>>& child, string& result, int idx, string& str) {
	for (int i = 0; i < 4; i++) {
		result += str[child[idx][order[i]]];
		if (str[child[idx][order[i]]] == 'x') {
			findResult(child, result, child[idx][order[i]], str);
		}
	}
}