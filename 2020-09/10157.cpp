#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
int R, C;
int dir = 0;
vector<vector<int> > A;
void dfs(int y, int x, int value) {
	A[y][x] = value;
	if (value == R * C) return;

	int ny = y + my[dir];
	int nx = x + mx[dir];

	if(0 <= ny && ny < R && 0 <= nx && nx < C && A[ny][nx] == 0) dfs(ny, nx, value + 1);
	else {
		dir = (dir + 1) % 4;
		ny = y + my[dir];
		nx = x + mx[dir];

		if (0 <= ny && ny < R && 0 <= nx && nx < C && A[ny][nx] == 0)
			dfs(ny, nx, value + 1);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C >> R;
	A.resize(R);
	for (int i = 0; i < R; i++) {
		A[i].assign(C, 0);
	}

	// (R - 1, 0) 에서 시작
	dfs(R - 1, 0, 1);

	

	int t;
	cin >> t;
	if (t > R * C) {
		cout << "0";
		return 0;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] == t) {
				cout << j + 1 << " " << R - i;
			}
		}
	}
	return 0;
}