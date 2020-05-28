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
vector<vector<int> > A;
vector<int> team;
int minV = 987654321;
int nt[2] = { 0, 0 };
void f(int idx) {
	if (idx == N + 1) {
		int t[2] = { 0, 0 };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (team[i] == team[j]) {
					t[team[i]] += A[i][j];
				}
			}
		}
		minV = min(minV, abs(t[0] - t[1]));
		return;
	}
	for (int i = 0; i < 2; i++) {
		if (nt[i] < N / 2) {
			nt[i]++;
			team[idx] = i;
			f(idx + 1);
			nt[i]--;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N + 1);
	team.assign(N + 1, 0);
	for (int i = 0; i < N + 1; i++)
		A[i].resize(N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	f(1);
	cout << minV;
	return 0;
}