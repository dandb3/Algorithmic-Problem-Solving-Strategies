#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MIN 2e9

using namespace std;
using ll = long long;

int arr[101], dp[101][11], accSum[101], accSqSum[101];
int N, S;

int minimize(int start, int end);
int quantize(int idx, int maxNum);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		cin >> N >> S;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + N);
		accSum[0] = arr[0];
		for (int i = 1; i < N; i++) {
			accSum[i] = accSum[i - 1] + arr[i];
		}
		accSqSum[0] = arr[0] * arr[0];
		for (int i = 1; i < N; i++) {
			accSqSum[i] = accSqSum[i - 1] + arr[i] * arr[i];
		}
		cout << quantize(0, S) << '\n';
	}

	return 0;
}

int minimize(int start, int end) {
	double num;
	num = static_cast<double>(accSum[end] - accSum[start] + arr[start]) / (end - start + 1);
	int t = static_cast<int>(num);
	if (num - t > 0.5)
		t++;

	return (end - start + 1) * t * t - 2 * (accSum[end] - accSum[start] + arr[start]) * t + (accSqSum[end] - accSqSum[start] + arr[start] * arr[start]);
}

int quantize(int idx, int maxNum) {
	int& ret = dp[idx][maxNum];
	if (ret != -1)
		return dp[idx][maxNum];
	if (idx == N)
		return ret = 0;
	if (maxNum == 0)
		return ret = MIN;
	int minVal = MIN;
	for (int i = idx; i < N; i++) {
		minVal = min(minVal, minimize(idx, i) + quantize(i + 1, maxNum - 1));
	}
	return ret = minVal;
}