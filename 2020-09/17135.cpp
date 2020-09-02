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
#include <queue>
#include <ctype.h>
using namespace std;
int N, M, D;
vector<vector<int> > A;
pair<int, int> target(int col) {
	// archor[N][col]
	int minD = 9999999;
	pair<int, int> ret;
	ret.first = -1; ret.second = -1;
	for (int j = 0; j < M; j++) {
		for (int i = N - 1; i >= 0; i--) {
			int d = abs(N - i) + abs(col - j);
			if (d <= D && A[i][j] == 1) {
				if (d < minD) {
					minD = d;
					ret.first = i;
					ret.second = j;
				}
			}
		}
	}
	return ret;
}
void attack() {
	for (int k = 0; k < M; k++) A[N - 1][k] = 0;
	for (int j = 0; j < M; j++) {
		for (int i = N - 2; i >= 0; i--) {
			if (A[i][j]) {
				A[i + 1][j] = 1;
				A[i][j] = 0;
			}
		}
	}
}
int check() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ret += A[i][j];
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> D;
	A.resize(N + 1);
	int nE = 0;
	for (int i = 0; i < N; i++) {
		A[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j]) nE++;
		}
	}
	A[N].assign(M, 0);
	vector<vector<int> > B = A;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				A[N][i] = A[N][j] = A[N][k] = 1;
				int cnt = 0;
				// A[N][i] A[N][j] A[N][k] 궁수
				while (true) {
					pair<int, int> a, b, c;
					a = target(i);
					b = target(j);
					c = target(k);
					if (a.first != -1 && A[a.first][a.second] == 1) { cnt++; A[a.first][a.second] = 0; }
					if (b.first != -1 && A[b.first][b.second] == 1) { cnt++; A[b.first][b.second] = 0; }
					if (c.first != -1 && A[c.first][c.second] == 1) { cnt++; A[c.first][c.second] = 0; }

					int enemy = 0;
					for (int c = 0; c < M; c++) {
						if (A[N - 1][c]) {
							enemy = 1;
							break;
						}
					}
					
					if (!check()) {
						ans = max(ans, cnt);
						break;
					}
					attack();
				}
				A = B;
			}
		}
	}
	cout << ans;
	return 0;
}