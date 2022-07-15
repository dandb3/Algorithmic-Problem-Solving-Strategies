#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 2e9
//코드가 너무 더러운듯
using namespace std;
using ll = long long;

string str;
int dp[10001];

int difficulty(int idx);
int isSame(int idx, int len);
int isMonotoneInc(int idx, int len);
int isMonotoneDec(int idx, int len);
int isAlternating(int idx, int len);
int isArithmeticSeq(int idx, int len);

int main() {
	FASTIO;

	int test;
	cin >> test;
	while (test--) {
		memset(dp, -1, sizeof(dp));
		cin >> str;
		cout << difficulty(0) << '\n';
	}

	return 0;
}

int difficulty(int idx) {
	int& Ret = dp[idx];
	if (Ret != -1)
		return Ret;
	if (idx == str.size())
		return Ret = 0;
	if (idx + 2 >= str.size()) {
		return Ret = INF;
	}
	int ret = INF;
	int result = 10;
	if (idx + 2 < str.size()) {
		result = min(result, isSame(idx, 3));
		result = min(result, isMonotoneInc(idx, 3));
		result = min(result, isMonotoneDec(idx, 3));
		result = min(result, isAlternating(idx, 3));
		result = min(result, isArithmeticSeq(idx, 3));
		ret = min(ret, result + difficulty(idx + 3));
	}
	result = 10;
	if (idx + 3 < str.size()) {
		result = min(result, isSame(idx, 4));
		result = min(result, isMonotoneInc(idx, 4));
		result = min(result, isMonotoneDec(idx, 4));
		result = min(result, isAlternating(idx, 4));
		result = min(result, isArithmeticSeq(idx, 4));
		ret = min(ret, result + difficulty(idx + 4));
	}
	result = 10;
	if (idx + 4 < str.size()) {
		result = min(result, isSame(idx, 5));
		result = min(result, isMonotoneInc(idx, 5));
		result = min(result, isMonotoneDec(idx, 5));
		result = min(result, isAlternating(idx, 5));
		result = min(result, isArithmeticSeq(idx, 5));
		ret = min(ret, result + difficulty(idx + 5));
	}
	return Ret = ret;
}

int isSame(int idx, int len) {
	char num = str[idx];
	for (int i = idx + 1; i < idx + len; i++) {
		if (num != str[i])
			return 10;
	}
	return 1;
}

int isMonotoneInc(int idx, int len) {
	char num = str[idx];
	for (int i = idx + 1; i < idx + len; i++) {
		if (++num != str[i])
			return 10;
	}
	return 2;
}

int isMonotoneDec(int idx, int len) {
	char num = str[idx];
	for (int i = idx + 1; i < idx + len; i++) {
		if (--num != str[i])
			return 10;
	}
	return 2;
}

int isAlternating(int idx, int len) {
	char num1 = str[idx], num2 = str[idx + 1];
	for (int i = 2; i < len; i++) {
		if (i % 2 == 0) {
			if (str[idx + i] != num1)
				return 10;
		}
		else {
			if (str[idx + i] != num2)
				return 10;
		}
	}
	return 4;
}

int isArithmeticSeq(int idx, int len) {
	char num = str[idx];
	int diff = str[idx + 1] - str[idx];
	for (int i = idx + 1; i < idx + len; i++) {
		if ((num += diff) != str[i])
			return 10;
	}
	return 5;
}