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
int M, N, K;
int A[100][100];
bool visited[100][100];
vector<int> ans;
int dfs(int r, int c) {
	const int mr[4] = { -1, 0, 1, 0 };
	const int mc[4] = { 0, 1, 0, -1 };
	
	int ret = 1;
	visited[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + mr[i];
		int nc = c + mc[i];
		if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
			if (A[nr][nc] && visited[nr][nc] == 0) {
				ret += dfs(nr, nc);
			}
		}
	}
	return ret;
}
int dfsAll() {
	int ret = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] && visited[i][j] == 0) {
				ans.push_back(dfs(i, j));
				ret++;
			}
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = 1;
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int r = y1; r < y2; r++) {
			for (int c = x1; c < x2; c++) {
				A[r][c] = 0;
			}
		}
	}
	

	cout << dfsAll() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}