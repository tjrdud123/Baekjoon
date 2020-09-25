#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N, M, K;
vector<vector<int> > A, B;
vector < pair<int, pair<int, int> > > cmds;
void rotate(int r, int c, int s) {
	for (int d = 1; d <= s; d++) {
		int t = A[r][c - d];
		int a = r;
		int b = c - d;

		a++;
		while (a <= r + d) {
			A[a - 1][b] = A[a][b];
			a++;
		}
		a--;

		b++;
		while (b <= c + d) {
			A[a][b - 1] = A[a][b];
			b++;
		}
		b--;

		a--;
		while (a >= r - d) {
			A[a + 1][b] = A[a][b];
			a--;
		}
		a++;

		b--;
		while (b >= c - d) {
			A[a][b + 1] = A[a][b];
			b--;
		}
		b++;

		a++;
		while (a < r) {
			A[a - 1][b] = A[a][b];
			a++;
		}
		a--;
		A[a][b] = t;
	}
}

int getMin() {
	int ret = 987654321;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += A[i][j];
		}
		ret = min(ret, sum);
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	A.resize(N + 1);
	for (int i = 0; i < N; i++) {
		A[i + 1].resize(M + 1);
		for (int j = 0; j < M; j++) {
			cin >> A[i + 1][j + 1];
		}
	}

	vector<int> idxs;
	// 회전
	for (int i = 0; i < K; i++) {
		idxs.push_back(i);
		int r, c, s;
		cin >> r >> c >> s;
		cmds.push_back(make_pair(r, make_pair(c, s)));
	}

	B = A;
	int ans = 9999999;
	do {
		for (int i = 0; i < K; i++) {
			int idx = idxs[i];
			rotate(cmds[idx].first, cmds[idx].second.first, cmds[idx].second.second);
		}

		ans = min(ans, getMin());
		A = B;
	} while (next_permutation(idxs.begin(), idxs.end()));
	
	cout << ans;

	return 0;
}