#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N, M, T;
vector<vector<int> > A;
void _rotate(int n, int dir, int k) {
	vector<int> v(M + 1);
	int idx = 1;

	if (dir == 0) {
		for (int i = M - k + 1; i <= M; i++) v[idx++] = A[n][i];
		for (int i = 1; i <= M - k; i++) v[idx++] = A[n][i];
		A[n] = v;
	}
	else if (dir == 1) {
		reverse(A[n].begin() + 1, A[n].end());
		for (int i = M - k + 1; i <= M; i++) v[idx++] = A[n][i];
		for (int i = 1; i <= M - k; i++) v[idx++] = A[n][i];
		A[n] = v;
		reverse(A[n].begin() + 1, A[n].end());
	}
}
int visited[100][100];
bool dfs(int y, int x, int value) {
	visited[y][x] = 1;
	A[y][x] = -1;

	int my[4] = { -1, 0, 1, 0 };
	int mx[4] = { 0, 1, 0, -1 };

	bool ret = false;
	for (int i = 0; i < 4; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];

		if (nx == 0) nx = M;
		if (nx == M + 1) nx = 1;

		if (1 <= ny && ny <= N && 1 <= nx && nx <= M) {
			if (visited[ny][nx] == 0 && A[ny][nx] == value) {
				dfs(ny, nx, value);
				ret = true;
			}
				
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	A.resize(N + 1);
	for (int i = 0; i < N + 1; i++) A[i].resize(M + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	for (int t = 0; t < T; t++) {
		int x, d, k;
		cin >> x >> d >> k;
		
		for (int i = 1; x * i <= N; i++) {
			_rotate(x * i, d, k);
		}
	
		bool isRemoved = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				int number = A[i][j];

				if (number == -1) continue;
				
				memset(visited, 0, sizeof(visited));
				if (dfs(i, j, A[i][j]) == false) {
					A[i][j] = number;
				}
				else isRemoved = true;
			}
		}

		if (isRemoved == false) {
			double mean = 0.0;
			int cnt = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (A[i][j] != -1) {
						mean += (double)A[i][j];
						cnt++;
					}	
				}
			}
			mean /= cnt;
			
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if(A[i][j] == -1) continue;
					if ((double)A[i][j] > mean) {
						A[i][j]--;
					}
					else if ((double)A[i][j] < mean) {
						A[i][j]++;
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			//cout << A[i][j] << " ";
			if(A[i][j] != -1) sum += A[i][j];
		}
		//cout << "\n";
	}
	cout << sum;
	return 0;
}