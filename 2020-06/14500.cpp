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
int N, M;
vector<vector<int> > A;
int maxV = -1;
void f(int sum, int toPick, int r, int c, int pr, int pc) {
	if (toPick == 0) {
		maxV = max(maxV, sum);
		return;
	}
	
	if (r < 0 || r >= N || c < 0 || c >= M) {
		return;
	}

	int mr[4] = { -1, 0, 1, 0 };
	int mc[4] = { 0, 1, 0, -1 };
	
	for (int i = 0; i < 4; i++) {
		int nr = r + mr[i];
		int nc = c + mc[i];

		if (nr == pr && nc == pc)
			continue;
		f(sum + A[r][c], toPick - 1, nr, nc, r, c);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; i++)
		A[i].resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			f(0, 4, i, j, -1, -1);
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			int sum = A[i][j + 1] + A[i + 1][j] + A[i + 1][j + 1] + A[i + 1][j + 2] + A[i + 2][j + 1];
			maxV = max(maxV, sum - A[i][j + 1]);
			maxV = max(maxV, sum - A[i + 1][j]);
			maxV = max(maxV, sum - A[i + 1][j + 2]);
			maxV = max(maxV, sum - A[i + 2][j + 1]);

			sum = A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i + 1][j + 1];
			maxV = max(maxV, sum);

			sum = A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2] + A[i + 1][j + 1];
			maxV = max(maxV, sum);

			sum = A[i][j] + A[i + 1][j] + A[i + 2][j] + A[i + 1][j + 1];
			maxV = max(maxV, sum);

			sum = A[i][j + 2] + A[i + 1][j + 2] + A[i + 2][j + 2] + A[i + 1][j + 1];
			maxV = max(maxV, sum);
		}
	}
	cout << maxV;
	return 0;
}