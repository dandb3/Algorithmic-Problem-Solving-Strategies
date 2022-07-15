#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int arr[101];

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		int N, S;
		cin >> N >> S;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + N);

	}

	return 0;
}