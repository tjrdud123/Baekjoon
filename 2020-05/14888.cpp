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
vector<int> A;
vector<int> nOpers;
int maxV = -2000000000;
int minV = 2000000000;
void f(int ans, int idx) {
	if (idx == N) {
		maxV = max(maxV, ans);
		minV = min(minV, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (nOpers[i]) {
			nOpers[i]--;
			if (i == 0)
				f(ans + A[idx], idx + 1);
			else if (i == 1)
				f(ans - A[idx], idx + 1);
			else if (i == 2)
				f(ans * A[idx], idx + 1);
			else if (i == 3) {
				int t = ans;
				if (t < 0) {
					t = -t;
					t /= A[idx];
					t = -t;
					f(t, idx + 1);
				}
				else
					f(ans / A[idx], idx + 1);
			}
			nOpers[i]++;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	nOpers.assign(4, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> nOpers[i];
	f(A[0], 1);
	cout << maxV << "\n" << minV;
	return 0;
}