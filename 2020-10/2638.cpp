#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
vector<vector<int> > A;
bool visited[100][100];
void dfs(int y, int x) {
	visited[y][x] = true;
	A[y][x] = 2;

	for (int i = 0; i < 4; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M) {
			if (visited[ny][nx] == false && A[ny][nx] != 1) dfs(ny, nx);
		}
	}
}
int _count(int y, int x) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M) {
			if (A[ny][nx] == 2) ret++;
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; i++) A[i].resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int time;
	for (time = 0; ; time++) {
		
		memset(visited, 0, sizeof(visited));
		dfs(0, 0);
		
		bool isCompleted = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j] == 1) {
					isCompleted = false;
					if (_count(i, j) >= 2) {
						A[i][j] = 3;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j] == 3) A[i][j] = 2;
			}
		}

		

		if (isCompleted) break;
	}
	cout << time;
	return 0;
}