#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int cache[101][101];
string wildStr, fileName;

bool match(int w, int s);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		cin >> wildStr;
		int N;
		cin >> N;
		vector<string> files;
		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> fileName;
			if (match(0, 0))
				files.push_back(fileName);
		}
		sort(files.begin(), files.end());
		for (string& fileName : files) {
			cout << fileName << '\n';
		}
	}

	return 0;
}

bool match(int w, int s) {
	if (cache[w][s] != -1) {
		return cache[w][s];
	}
	while (w < wildStr.size() && s < fileName.size() && (wildStr[w] == fileName[s] || wildStr[w] == '?')) {
		w++;
		s++;
	}

	if (w == wildStr.size())
		return cache[w][s] = (s == fileName.size());

	if (wildStr[w] == '*')
		for (int skip = 0; s + skip <= fileName.size(); skip++) {
			if (match(w + 1, s + skip))
				return cache[w][s] = 1;
		}
	return cache[w][s] = 0;
}