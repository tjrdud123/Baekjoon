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
using namespace std;
int N, M, K;
vector<vector<int> > A, board;
vector<vector<vector<int> > > trees;
int mr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int mc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	A.resize(N);
	board.resize(N);
	trees.resize(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(N);
		board[i].assign(N, 5);
		trees[i].resize(N);
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
	}

	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int t = 0; t < trees[i][j].size(); t++) {
					int age = trees[i][j][t];
					if (board[i][j] >= age) {
						board[i][j] -= age;
						trees[i][j][t]++;
					}
					else {
						for (int s = trees[i][j].size() - 1; s >= t; s--) {
							board[i][j] += trees[i][j][s] / 2;
							trees[i][j].pop_back();
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int t = 0; t < trees[i][j].size(); t++) {
					if (trees[i][j][t] % 5 == 0) {
						for (int o = 0; o < 8; o++) {
							int nr = i + mr[o];
							int nc = j + mc[o];
							if (0 <= nr && nr < N && 0 <= nc && nc < N) {
								trees[nr][nc].push_back(1);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sort(trees[i][j].begin(), trees[i][j].end());
				board[i][j] += A[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += trees[i][j].size();
		}
	}
	cout << ans;
	return 0;
}