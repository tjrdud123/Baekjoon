#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
vector<vector<char> > A;
vector<vector<int> > visited;
int mr[4] = { -1, 0, 1, 0 };
int mc[4] = { 0, 1, 0, -1 };
void dfs(int r, int c) {
	visited[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + mr[i];
		int nc = c + mc[i];
		
		if (0 <= nr && nr < N && 0 <= nc && nc < N) {
			if (visited[nr][nc] == 0) {
				if (A[r][c] == A[nr][nc]) {
					dfs(nr, nc);
				}
			}
		}
	}
}
int dfsAll() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				ret++;
				dfs(i, j);
			}
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(N);
		visited[i].assign(N, 0);
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			A[i][j] = str[j];
		}
	}
	
	cout << dfsAll() << " ";
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
			if (A[i][j] == 'G')
				A[i][j] = 'R';
		}
	}
	cout << dfsAll();
	return 0;
}