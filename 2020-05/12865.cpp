#include <math.h>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <utility>
using namespace std;
int N, K;
vector<int> W, V;
int dp[100][100001];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	W.resize(N);
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int j = 1; j <= K; j++) {
		if (j < W[0])
			dp[0][j] = 0;
		else
			dp[0][j] = V[0];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j < W[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}
	cout << dp[N - 1][K];
	return 0;
}