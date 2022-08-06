#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 4294967296

using namespace std;
using ll = long long;

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {

		int K, N;
		cin >> K >> N;

		deque<int> deq;
		int sum = 0, cnt = 0;
		ll realSig = 1983;
		int sig;

		for (int idx = 1; idx <= N; idx++) {
			sig = realSig % 10000 + 1;
			realSig = (realSig * 214013 + 2531011) % MOD;

			while (sum >= K) {
				if (sum == K)
					cnt++;
				sum -= deq.front();
				deq.pop_front();
			}
			deq.push_back(sig);
			sum += deq.back();
		}
		cout << cnt << '\n';
	}

	return 0;
}