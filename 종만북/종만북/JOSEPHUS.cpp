#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		int N, K;
		cin >> N >> K;

		list<int> people(N);
		auto elem = people.begin();
		for (int i = 1; i <= N; i++, elem++) {
			*elem = i;
		}

		int listSize = N;
		auto iter = people.begin();
		while (listSize > 2) {
			iter = people.erase(iter);
			listSize--;
			if (iter == people.end())
				iter = people.begin();
			for (int i = 0; i < K - 1; i++) {
				iter++;
				if (iter == people.end())
					iter = people.begin();
			}
		}
		for (int pos : people) {
			cout << pos << ' ';
		}
		cout << '\n';
	}

	return 0;
}