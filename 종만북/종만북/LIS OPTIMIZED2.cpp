#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int arr[501];

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		vector<int> LIS;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		LIS.push_back(arr[0]);
		for (int i = 1; i < N; i++) {
			auto it = lower_bound(LIS.begin(), LIS.end(), arr[i]);
			if (it == LIS.end())
				LIS.push_back(arr[i]);
			else if (*it > arr[i])
				*it = arr[i];
		}
		cout << LIS.size() << '\n';
	}

	return 0;
}