#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int N;
vector<int> v;
int cntV[10000];
vector<pair<int, int> > A;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.second == p2.second) return p1.first > p2.first;
	return p1.second < p2.second;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v.resize(N);
	double sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());

	cout << round(sum / N) << "\n";
	cout << v[N / 2] << "\n";

	memset(cntV, 0, sizeof(cntV));
	for (int i = 0; i < N; i++) {
		cntV[v[i] + 4000]++;
	}
	for (int i = 0; i < 10000; i++) {
		if (cntV[i] != 0) {
			A.push_back(make_pair(i - 4000, cntV[i]));
		}
	}
	sort(A.begin(), A.end(), cmp);
	int n = A.size();
	if (A.size() > 1 && A[n - 1].second == A[n - 2].second) cout << A[n - 2].first << "\n";
	else cout << A[n - 1].first << "\n";
	cout << v[N - 1] - v[0] << "\n";

	return 0;
}