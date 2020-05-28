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
int N;
vector<pair<int, int> > v;
vector<int> dp;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dp.assign(N, 1);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxV = -1;
	for (int i = 0; i < N; i++) {
		maxV = max(maxV, dp[i]);
	}
	cout << N - maxV;
	return 0;
}